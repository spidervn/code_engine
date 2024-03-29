#include "FileSystemUtil.h"
#include <boost/filesystem.hpp>
#include <boost/regex.hpp>
#include <queue>

using namespace std;
using namespace boost::filesystem;

FileSystemUtil::FileSystemUtil()
{}

FileSystemUtil::~FileSystemUtil()
{}

int FileSystemUtil::enum_directory(std::string folder, std::vector<std::string> vfiles, bool bRecursive, int MAX_ENUM)
{
	vfiles.clear();
	// try
    // {
    //     path fp1(path);
    //     vector<path> v2;

    //     if (is_directory(fp2))
    //     {
    //         for (auto&& x: directory_iterator(fp2))
    //         {
    //             v2.push_back(x.path());
    //         }
    //     }
    // }
    // catch (const filesystem_error& ex)
    // {
    //     cout << ex.what() << endl;
    // }

	return 0;
}

int FileSystemUtil::walk_through_files(std::string folder, IFileSystemUtilHandler* pHandler, bool bRecursive, int MAX_ENUM)
{
    if (!pHandler)
    {
        return 1;  // General Error
    }

	path fp1(folder);

    if (exists(fp1))
    {
        if (is_directory(fp1))
        {
            if (bRecursive)
            {
                int countEnum = 0;
                std::queue<path> vqueue;
                vqueue.push(fp1);

                while (vqueue.size() > 0 && (MAX_ENUM <=0 || countEnum < MAX_ENUM))
                {
                    path fpe = vqueue.front();
                    vqueue.pop();

                    pHandler->onEnterEnumFolder(fpe.string());
                    
                    for (directory_entry& de: directory_iterator(fpe))
                    {
                        if (is_directory(de))
                        {
                            vqueue.push(de);
                        }
                        else if (is_regular_file(de))
                        {
                            pHandler->onVisitFile(folder, de.path().string());
                            countEnum++;

                            if (MAX_ENUM > 0 && countEnum >= MAX_ENUM) 
                            {
                                break;
                            }
                        }
                    }
					
                    pHandler->onLeaveEnumFolder(fpe.string());
                }
            }
            else 
            {
            	pHandler->onEnterEnumFolder(fp1.string());

                int countEnum = 0;
                for (directory_entry& de: directory_iterator(fp1))
                {
                    if (is_regular_file(de))
                    {
                        pHandler->onVisitFile(folder, de.path().string());
                        countEnum++;

                        if (MAX_ENUM > 0 && countEnum >= MAX_ENUM) 
                        {
                            break;
                        }
                    }
                }

                pHandler->onLeaveEnumFolder(fp1.string());
            }

        }
        else if (is_regular_file(fp1)) 
        {
            pHandler->onVisitFile(folder, fp1.string());
        }
    }

    return 0;   // Success
}


int FileSystemUtil::walk_through_filesW(std::wstring folder, IFileSystemUtilHandlerW* pHandler, bool bRecursive, int MAX_ENUM)
{
	if (!pHandler)
	{
		return 1;  // General Error
	}

	path fp1(folder);

	if (exists(fp1))
	{
		if (is_directory(fp1))
		{
			if (bRecursive)
			{
				int countEnum = 0;
				std::queue<path> vqueue;
				vqueue.push(fp1);

				while (vqueue.size() > 0 && (MAX_ENUM <= 0 || countEnum < MAX_ENUM))
				{
					path fpe = vqueue.front();
					vqueue.pop();

					pHandler->onEnterEnumFolder(fpe.wstring());

					for (directory_entry& de : directory_iterator(fpe))
					{
						if (is_directory(de))
						{
							vqueue.push(de);
						}
						else if (is_regular_file(de))
						{
							pHandler->onVisitFile(fpe.wstring(), de.path().filename().wstring());
							countEnum++;

							if (MAX_ENUM > 0 && countEnum >= MAX_ENUM)
							{
								break;
							}
						}
					}

					pHandler->onLeaveEnumFolder(fpe.wstring());
				}
			}
			else
			{
				int countEnum = 0;
				pHandler->onEnterEnumFolder(fp1.wstring());

				for (directory_entry& de : directory_iterator(fp1))
				{
					if (is_regular_file(de))
					{
						pHandler->onVisitFile(fp1.wstring(), de.path().filename().wstring());
						countEnum++;

						if (MAX_ENUM > 0 && countEnum >= MAX_ENUM)
						{
							break;
						}
					}
				}

				pHandler->onLeaveEnumFolder(fp1.wstring());
			}
		}
		else if (is_regular_file(fp1))
		{
			pHandler->onVisitFile(folder, fp1.wstring());
		}
	}

	return 0;   // Success
}

std::string FileSystemUtil::concat_path(std::string path1, std::string path2)
{
	path p1(path1);
	p1.append(path2);

	return p1.string();
}

int FileSystemUtil::file_extension(std::string path, std::string& ext)
{
    int nBreak = -1;
    for (int i=path.length()-1; i>=0; --i)
    {
        if (path[i] == '.')
        {
            nBreak = i;
            break;
        }
    }

    if (nBreak >= 0)
    {
		ext = path.substr(nBreak+1);
		return 0;	// Success
    }

	return 1;	// Failed
}

int FileSystemUtil::file_extensionW(std::wstring path, std::wstring& ext)
{
	int nBreak = -1;
	for (int i = path.length() - 1; i >= 0; --i)
	{
		if (path[i] == L'.')
		{
			nBreak = i;
			break;
		}
	}

	if (nBreak >= 0)
	{
		ext = path.substr(nBreak + 1);
		return 0;	// Success
	}

	return 1;	// Failed
}


int FileSystemUtil::get_File_extensionW(std::wstring path, std::wstring& ext)
{
    int nBreak = -1;
    for (int i = path.length() - 1; i >= 0; --i)
    {
        if (path[i] == L'.')
        {
            nBreak = i;
            break;
        }
    }

    if (nBreak >= 0)
    {
        ext = path.substr(nBreak + 1);
        return 0;   // Success
    }

    return 1;   // Failed
}