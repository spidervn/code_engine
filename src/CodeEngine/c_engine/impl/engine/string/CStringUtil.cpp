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

int CStringUtil::split_paragraph(std::string content, std::vector<std::string> vpara)
{
    // Do not use the paragraph 
    // 
    // Splitting: 
    //  *) 
    //  *) 
    //  *) 

    unsigned int i;
    int apos[100];  // Stack of position
                    // String is an Array 
    int npos = 0;

    for (i=0; i<content.length();++i)
    {
        if (content[i] == '\r' || content[i] == '\n')
        {
            apos[npos++] = i;   // Push to stack 
        }
    }

    return 0;
}

bool CStringUtil::ends_width(const std::wstring& wstr, const std::wstring& suffix)
{
	int r1 = wstr.length() - 1;
	int r2 = suffix.length() - 1;

	while (r1 >= 0 && r2 >= 0 && wstr[r1] == suffix[r2])
	{
		r1--;
		r2--;
	}

	return r2 < 0;
}

int CStringUtil::fuzzy_find(std::string wholecontent, std::string strfind)
{
    throw "UnImplemented";
    return 0;
}

int CStringUtil::distance(std::string str1, std::string str2)
{
    int l1 = str1.length();
    int l2 = str2.length();
    int* d = (int*) malloc(sizeof(int) * l1*l2);    // Matrix 
                                                    // distance(x,y) = d[x*l1+y]
    if (d)
    {
        /*
            l1xl2
            <-----l1---->
            [0,0,...,0,0]   ^
            [0,0,...,0,0]   |
            ...             l2
            [0,0,...,0,0]   |
            [0,0,...,0,0]   v

            distance[0,y] = 0   // y=0..l2-1
            distance[x,0] = 0   // x=0..l1-1
            distance[x,y] = max(
                                d[x-1,y],
                                d[x,y-1],
                                d[x-1,y-1] + equals(str1[x], str2[y]))
         */

        for (int y=0;y<l2;++y)
        {
            d[y] = 0;
        }

        for (int x=1;x<l1;++x)  // Pass the x=0 step; since the above command has updated it.
        {
            d[x*l1] = 0;
        }

        for (int x=1;x<l1;++x)
        {
            for (int y=1;y<l2;++y)
            {
                int max = d[(x-1)*l1+y];
                if (max < d[x*l1 + y-1])
                {
                    max = d[x*l1 + y-1];
                }

                int equals = str1[x] == str2[y] ? 1 : 0;
                if (max < d[(x-1)*l1 + y-1] + equals)
                {
                    max = d[(x-1)*l1 + y-1] + equals;
                }
            }
        }
    }
    else 
    {
        throw "Invalid memory";
    }
    return 0;
}