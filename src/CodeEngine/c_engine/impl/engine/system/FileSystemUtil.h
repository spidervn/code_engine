#ifndef CODEENGINE_C_ENGINE_IMPL_SYSTEM_FILESYSTEMUTIL_H_
#define CODEENGINE_C_ENGINE_IMPL_SYSTEM_FILESYSTEMUTIL_H_

#include "c_engine/interface/engine/system/IFileSystemUtil.h"

class FileSystemUtil: public IFileSystemUtil 
{
public:
	FileSystemUtil();
	virtual ~FileSystemUtil();
	
	int enum_directory(std::string folder, std::vector<std::string> vfiles, bool bRecursive = false, int MAX_ENUM=10000);
	int walk_through_files(std::string folder, IFileSystemUtilHandler* pHandler, bool bRecursive = false, int MAX_ENUM=10000);
	int walk_through_filesW(std::wstring folder, IFileSystemUtilHandlerW* pHandler, bool bRecursive = false, int MAX_ENUM = 10000);
	std::string concat_path(std::string path1, std::string path2);
	int file_extension(std::string path, std::string& ext);
	int file_extensionW(std::wstring path, std::wstring& ext);

	static int get_File_extensionW(std::wstring path, std::wstring& ext);
};

#endif