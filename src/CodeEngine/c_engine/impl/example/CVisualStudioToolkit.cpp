
#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>
#include "CVisualStudioToolkit.h"
#include "c_engine/impl/engine/system/FileSystemUtil.h"
#include "c_engine/impl/engine/string/CStringUtil.h"


std::wstring VSProject::TypeVcProj = L"vcproj";
std::wstring VSProject::TypeVcProjFilter = L"vcxproj.filters";
std::wstring VSProject::TypeCsProj = L"csproj";


int VSProject::GetAttribute(std::wstring key, std::wstring& value)
{
	for (int i = 0; i < keyLen; ++i)
	{
		std::wstring wstrStoredKey = arrAttributes[2 * i];

		if (_wcsnicmp(key.c_str(), wstrStoredKey.c_str(), -1) == 0)
		{
			value = arrAttributes[2 * i + 1];
			return 0;	// FOUND
		}
	}
	return 1;	// NOT FOUND
}

int VSProject::SetAttribute(std::wstring key, std::wstring value)
{
	bool bExisted = false;
	int nRet = 2;	// Failed
	// Existing?
	for (int i = 0; i < keyLen; ++i)
	{
		std::wstring wstrStoredKey = arrAttributes[2 * i];

		if (_wcsnicmp(key.c_str(), wstrStoredKey.c_str(), -1) == 0)
		{
			arrAttributes[2 * i + 1] = value;
			bExisted = true;
			nRet = 1;		// Update
		}
	}

	if (!bExisted)
	{
		if (keyLen < ATTRIBUTE_LEN)
		{
			arrAttributes[2 * keyLen] = key;
			arrAttributes[2 * keyLen + 1] = value;
			keyLen++;

			nRet = 0;	// Insert
		}
		else
		{
			nRet = 3; // Run out of Quota
		}
	}

	return nRet;
}

int VSProject::HasAttribute(std::wstring key)
{
	int nRet = -1;	// Failed
	for (int i = 0; i < keyLen; ++i)
	{
		std::wstring wstrStoredKey = arrAttributes[2 * i];

		if (_wcsnicmp(key.c_str(), wstrStoredKey.c_str(), -1) == 0)
		{
			nRet = i;	// Position
		}
	}
	return nRet;
}

VSProject::ProjectType VSProject::Type()
{
	int cpp_count = 0;
	int csharp_count = 0;

	for (int i = 0; i < keyLen; ++i)
	{
		int iA = i << 1; // 2*i
		if (arrAttributes[iA] == TypeVcProj || arrAttributes[iA] == TypeVcProjFilter)
		{
			cpp_count++;
		}
		else if (arrAttributes[iA] == TypeCsProj)
		{
			csharp_count++;
		}		
	}

	if (cpp_count > csharp_count)
		return CPP;
	else if (csharp_count > 0)
		return CSharp;
	else
		return Unknown;
}

std::wstring VSProject::toString()
{
	std::wstringstream wss;

	wss << L"[Name=" << project_name << L"]; [Path=" << project_path << "]; Attributes(";

	for (int i = 0; i < keyLen; ++i)
	{
		wss << L"[" << arrAttributes[2*i].c_str() << L"=" << arrAttributes[2*i+1] << "]; "; 
	}

	wss << ")";
	return wss.str();
}

int CVisualStudioToolkit::_upsert(std::wstring name, std::wstring path, std::wstring attributeKey, std::wstring attributeValue, std::vector<VSProject>& vprojects)
{
	bool bUpdate = false;
	int nRet = -1; // Failed

	for (int i = 0; i < vprojects.size(); ++i)
	{
		// Duplicated
		if (_wcsnicmp(vprojects[i].project_name.c_str(), name.c_str(), name.length()) == 0 &&
			_wcsnicmp(vprojects[i].project_path.c_str(), path.c_str(), path.length()) == 0)
		{
			vprojects[i].SetAttribute(attributeKey, attributeValue);
			bUpdate = true;
			nRet = 1; // Update
			break;
		}
	}

	if (!bUpdate)
	{
		VSProject proj;
		proj.project_name = name;
		proj.project_path = path;
		proj.SetAttribute(attributeKey, attributeValue);

		vprojects.push_back(proj);

		nRet = 2; // Insert
	}

	return nRet;
}

int CVisualStudioToolkit::FindAllProject(std::wstring path, bool bRecursive, std::vector<VSProject>& vFound)
{
    std::vector<VSProject> vcurrent;

	class FHandlerW: public IFileSystemUtilHandlerW 
    {
        public:
        int counter;
        FileSystemUtil*m_pFsu;
		CVisualStudioToolkit* mpVSTK;

		std::vector<VSProject> vPrjOneDir;
		std::vector<VSProject>* mp_vPrjAll;

		std::wstring m_wstrCurrentFolder;

		FHandlerW(FileSystemUtil* pfsu, CVisualStudioToolkit* pvstk, std::vector<VSProject>* pPrjAll)
        { 
        	counter = 0; 
        	m_pFsu = pfsu;
			mpVSTK = pvstk;
			mp_vPrjAll = pPrjAll;

			m_wstrCurrentFolder = L"";
        }

		int ConCat(const std::vector<VSProject>& vOneDir, std::vector<VSProject>& vAll)
		{
			for (int i = 0; i < vOneDir.size(); ++i)
			{
				vAll.push_back(vOneDir[i]);
			}

			return 0;
		}

        int onVisitFile(const std::wstring enumeratingFolder, std::wstring filename)
        {
        	const int NDEFINE = 3;
        	const int NCOL = 2;

        	std::wstring vExt[NDEFINE][NCOL] = {
        		{ L".csproj", VSProject::TypeCsProj },
				{ L".vcxproj.filters", VSProject::TypeVcProjFilter },
				{ L".vcxproj", VSProject::TypeVcProj }
        	};

        	std::wstring ext;
        	for (int idefine=0; idefine<NDEFINE; ++idefine)
        	{
                std::string::size_type nfind;
                std::wstring wstrName;
				std::wstring wstrExt;

				wstrExt = vExt[idefine][0];

                if (CStringUtil::ends_width(filename, wstrExt))
                {
                    wstrName = filename.substr(0, filename.length() - wstrExt.length());
					// Put to Array 
					mpVSTK->_upsert(wstrName, enumeratingFolder, vExt[idefine][1], filename, vPrjOneDir);
                }
        	}

			return 0;
        }

		int onEnterEnumFolder(const std::wstring folder)
		{
			m_wstrCurrentFolder = folder;
			return 0;
		}

		int onLeaveEnumFolder(const std::wstring folder)
		{
			// New Folder 
			ConCat(vPrjOneDir, *mp_vPrjAll);
			vPrjOneDir.clear();

			return 0;
		}
    };

    FileSystemUtil fsu;
	FHandlerW fhw(&fsu, this, &vFound);
	
    fsu.walk_through_filesW(path, &fhw, true, -1);	// Recursive check
	return 0;
}

bool CVisualStudioToolkit::VCppProjectContainsFile(std::string vcprojectFile, std::string filepath)
{
	return false;
}

bool CVisualStudioToolkit::CSharpProjectContainsFile(std::string csharpProjectFile, std::string filepath)
{
	return false;
}

int CVisualStudioToolkit::parseCppProject(std::wstring wstrProjectFile, std::wstring wstrProjectFilterFile, std::vector<std::wstring>& vFiles)
{
	if (!wstrProjectFile.empty())
	{
		// Parse Project File
		wstrProjectFile.size();
		wstrProjectFilterFile.size();

		// Open File
		// Find all <ClCompile></ClCompile>

		// Read Whole File.

		// 


		std::wstring wstrContent;


		std::wifstream fi;
		fi.open(wstrProjectFile);


		fi.close();
	}

	return 0;
}