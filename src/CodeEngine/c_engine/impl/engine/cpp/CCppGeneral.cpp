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

    // 
    try
    {
        path fp(header_file);

        cout << "Branch Path = " << fp.branch_path() << endl;
        cout << "Parent Path = " << fp.parent_path() << endl;
        cout << "Relative Path = " << fp.relative_path() << endl;
        cout << "Filename = " <<  fp.filename() << endl;
        cout << "Ext = " << fp.extension() << endl;
    }
    catch (const filesystem_error& e)
    {
        cout << e.what() << endl;
    }

    //
    // Find Base-path 
    // Recursively find base-path?
    //  * Find base-path 
    //  * 
    // 

    string vpath[100];
    int n = 0;
    int score = 0;

    auto f = 0; // Lambda function
    int fscore;
    int max_score;
    int trycount = 0;
    int MAX_TRY = 10;
    bool bReachRoot = false;

    vpath[n++] = fp.parent_path().string(); // Push into stack
    while (trycount < MAX_TRY && !bReachRoot)
    {
        string apath = vpath[--n];  // Pop from stack

        path boostpath(apath);
        path p2 = boostpath.concat("CMakeLists.txt");
        int score = fscore; // With p2

        if (score > max_score)
        {
            max_score = score;
        }

        // Finish when?
        // Root directory 
        // Or Limit Reached

        trycount++;
        bReachRoot = boostpath.parent_path().string() == apath;
    }



    return "";
} 