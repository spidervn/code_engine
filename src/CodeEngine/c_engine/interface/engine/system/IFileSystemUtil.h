#ifndef CODEENGINE_C_ENGINE_INTERFACE_ENGINE_SYSTEM_IFileSystemUtil_H_
#define CODEENGINE_C_ENGINE_INTERFACE_ENGINE_SYSTEM_IFileSystemUtil_H_

#include <string>
#include <vector>

class IFileSystemUtilHandler
{
public:
	virtual ~IFileSystemUtilHandler() {}
	virtual int onEnterEnumFolder(const std::string folder) { return 0; };
	virtual int onLeaveEnumFolder(const std::string folder) { return 0; };

	virtual int onVisitFile(const std::string enumeratingFolder, std::string filename) = 0;
};

class IFileSystemUtilHandlerW
{
public:
	virtual ~IFileSystemUtilHandlerW() {}
	virtual int onEnterEnumFolder(const std::wstring folder) { return 0; };
	virtual int onLeaveEnumFolder(const std::wstring folder) { return 0; };

	virtual int onVisitFile(const std::wstring enumeratingFolder, std::wstring filename) = 0;
};


class IFileSystemUtil
{
public:
	virtual ~IFileSystemUtil() {}
	
	virtual int enum_directory(std::string folder, std::vector<std::string> vfiles, bool bRecursive = false, int MAX_ENUM=10000) = 0;

	virtual int walk_through_files(std::string folder, IFileSystemUtilHandler* pHandler, bool bRecursive = false, int MAX_ENUM=10000) = 0;

	virtual int walk_through_filesW(std::wstring folder, IFileSystemUtilHandlerW* pHandler, bool bRecursive = false, int MAX_ENUM = 10000) = 0;

	virtual std::string concat_path(std::string path1, std::string path2) = 0;

	virtual int file_extension(std::string path, std::string& ext) = 0;

	virtual int file_extensionW(std::wstring path, std::wstring& ext) = 0;

	
};

#endif 