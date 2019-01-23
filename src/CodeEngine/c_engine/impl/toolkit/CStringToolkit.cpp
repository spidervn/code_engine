#include "CStringToolkit.h"

CStringToolkit::~CStringToolkit()
{}

int CStringToolkit::split(std::string content, 
                            std::string separator, 
                            std::vector<std::string>& v_split)
{
    int pos = 0;
    int found;
    v_split.clear();
    while ( (found = content.find_first_of(separator, pos)) != content.npos)
    {
        if (found > pos)
        {
            std::string token = content.substr(pos, found - pos);
            v_split.push_back(token);
        }
        pos = found+1;
    }

    return 0;
}