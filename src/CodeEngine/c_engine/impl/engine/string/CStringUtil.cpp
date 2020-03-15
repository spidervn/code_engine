#include "CStringUtil.h"
#include <algorithm>
#include <cctype>
#include <iostream>
#include <iterator>
#include <string>

using namespace std;

CStringUtil::CStringUtil(/* args */)
{
}

CStringUtil::~CStringUtil()
{
}

int CStringUtil::toUpper(std::string input, std::string& output)
{
    output.clear();
    char x;

    std::for_each(std::begin(input), std::end(input), [&output](char& c) {
        char d = static_cast<char>(std::toupper(static_cast<unsigned char>(c)));
        output += d;
    });
    return 0;
}

int CStringUtil::split_sentence(std::string content, std::vector<std::string> vsentence)
{
    /* 
     * 
     *  Split string?
     *      Split by dots 
     * 
     */
    int i;

    vector<int> vposition;
    vposition.reserve(100);

    for (int i=0; i<content.size();++i)
    {
        if (content[i]=='.')
        {
            // Split at i-th position
            vposition.push_back(i);
        }
    }

    for (int i=0; i<vposition.size();++i)
    {
        if (i==0)
        {
            vsentence.push_back( content.substr(0, vposition[i]) );
        }
        else
        {
            vsentence.push_back( content.substr( vposition[i-1] + 1, vposition[i]));
        }
    }

    if (vposition[vposition.size()-1] < content.size())
    {
        vsentence.push_back(content.substr(vposition[vposition.size()-1], content.size()));
    }

    return 0;
}