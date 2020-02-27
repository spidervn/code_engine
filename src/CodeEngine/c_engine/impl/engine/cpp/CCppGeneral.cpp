#include "CCppGeneral.h"
#include <boost/filesystem.hpp>
#include <iostream>

using namespace std;
using namespace boost::filesystem;

CCppGeneral::CCppGeneral(/* args */)
{
}

CCppGeneral::~CCppGeneral()
{
}

std::string CCppGeneral::generateIfDefPragma(
    std::string path_base,
    std::string header_file)
{
    string ret;
    string project_root;

    // 
    // Header File 
    // Recursively find Path-Base
    // 
    // Need Try/catch
    
    // Check Filesize
    long sz = file_size(header_file);
    
    // Check File existence
    path fp(header_file);
    if (exists(fp))
    {
        if (is_regular_file(fp))
        {

        }
        else if (is_directory(fp))
        {

        }
        else
        {

        }
    }

    // Directory iteration & catching exceptions
    try
    {
        path p1(header_file);

        if (is_directory(p1))
        {
            cout << p1 << " is a directory containing:\n";

            for (directory_entry& x: directory_iterator(p1))
            {
                cout << " " << x.path() << "\n";
            }
        }
    }
    catch (const filesystem_error& ex)
    {
    }

    // 
    // Path decomposition
    // 
    try
    {
        path fp2(header_file);
        vector<path> v2;

        if (is_directory(fp2))
        {
            cout << fp2 << " is a directory containing" << endl;
            for (auto&& x: directory_iterator(fp2))
            {
                v2.push_back(x.path());
            }

            std::sort(v2.begin(), v2.end());
        }
    }
    catch (const filesystem_error& ex)
    {
        cout << ex.what() << endl;
    }

} 