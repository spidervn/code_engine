#ifndef CODEENGINE_CENGINE_IMPL_EXAMPLE_CVisualStudioToolkit_H_
#define CODEENGINE_CENGINE_IMPL_EXAMPLE_CVisualStudioToolkit_H_

#include <string>
#include <vector>

struct VSProject
{
	enum ProjectType
	{
		Unknown = 0,
		CPP = 1,
		CSharp = 2
	};


	std::string type;   // C++, C#
	std::wstring project_name;
	std::wstring project_path;

	int keyLen;

	static const int ATTRIBUTE_LEN = 10;

	static std::wstring TypeVcProj; // = L"vcproj";
	static std::wstring TypeVcProjFilter; // = L"vcxproj.filters";
	static std::wstring TypeCsProj; // = L"csproj";

	std::wstring arrAttributes[2*ATTRIBUTE_LEN];

	VSProject()
	{
		type = "";
		project_name = L"";
		project_path = L"";
		keyLen = 0;
	}

	int GetAttribute(std::wstring key, std::wstring& value);
	int SetAttribute(std::wstring key, std::wstring value);	
	int HasAttribute(std::wstring key);	// =-1: Do Not Have; Else Return Index

	std::wstring toString();

	ProjectType Type();
};
class CVisualStudioToolkit
{
public:
	int FindAllProject(std::wstring path, bool bRecursive, std::vector<VSProject>& vFound);

	bool VCppProjectContainsFile(std::string vcprojectFile, std::string filepath);

	bool CSharpProjectContainsFile(std::string csharpProjectFile, std::string filepath);

	int _upsert(std::wstring name, std::wstring path, std::wstring attributeKey, std::wstring attributeValue, std::vector<VSProject>& vprojects);

	int parseCppProject(std::wstring wstrProjectFile, std::wstring wstrProjectFilterFile, std::vector<std::wstring>& vFiles);
};

#endif