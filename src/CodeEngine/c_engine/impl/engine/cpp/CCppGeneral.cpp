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
    // @Path
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
    // 
    // @Output:
    //  * O01: A list with:
    //      a) Score 
    //      b) Path
    //
    int max_score = 0;
    int trycount = 0;
    int MAX_DEPTH = 10;
    int MAX_RECORD = 4;
    bool bReachRoot = false;
    path enum_path = fp.parent_path();
    path project_base;

    vector<std::pair<int, path>> v_record;

    while (trycount < MAX_DEPTH && !bReachRoot)
    {
        path path_cmake = enum_path; // path::concat(enum_path, "/CMakeLists.txt");
        path path_main = enum_path; //.concat("/main.cpp");

        path_cmake.concat("/CMakeLists.txt");
        path_main.concat("/main.cpp");
        path arr_path[2] = { path_cmake, path_main };
        
        int arr_mark[2] = { 8, 10 };
        int score;

        for (int i=0; i<2; ++i)
        {
            cout << "Check: " << arr_path[i] << endl;
            if (exists(arr_path[i]))
            {
                score = arr_mark[i] + (MAX_DEPTH - trycount)*3;   // MAX_DEPTH - trycount <=> Sooner is better

                int last_good_score = v_record.size() > 0 ? v_record[0].first : 0;
                if (v_record.size() < MAX_RECORD || score > last_good_score)
                {
                    std::pair<int, path> pp(score, enum_path);
                    // max_score = score;
                    // project_base = enum_path;

                    // 1st entry that 
                    int j = 0;
                    while (j < v_record.size()) 
                    { 
                        if (v_record[j].first <= last_good_score) j++;
                        else break; 
                    }

                    v_record.insert(v_record.begin() + j, pp);

                    if (v_record.size() > MAX_RECORD)
                    {
                        v_record.erase(v_record.begin());
                    }
                }
            }
        }
        
        trycount++;
        bReachRoot = enum_path.parent_path().string() == enum_path.string();
        enum_path = enum_path.parent_path();
    }

    if (v_record.size() > 0)
    {
        for (int i=0; i<v_record.size(); ++i)
        {
            cout << "Record(" << i << ")" << endl;
            cout << "\tBase Path = " << v_record[i].second << "(Score=" << v_record[i].first << ")" << endl;
            cout << "\tFileName = " << v_record[i].second.filename() << endl;
        }
        // cout << "Base Path = " << project_base << "(Score=" << max_score << ")" << endl;
        // cout << "\tFileName = " << project_base.filename() << endl;
    }
    else
    {
        cout << "Could not found" << endl;
    }

    return "";
}