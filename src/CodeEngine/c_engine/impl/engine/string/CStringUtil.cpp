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
    
    std::for_each(std::begin(input), std::end(input), [](char& c) {
        output.append(static_cast<char>(std::toupper(static_cast<unsigned char>(c))));
    });
    return 0;
}