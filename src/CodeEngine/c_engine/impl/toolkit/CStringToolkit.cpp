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

int CStringToolkit::split(std::string content, std::vector<std::string> separators, std::vector<std::string>& v_split)
{
    int pos = 0;
    int found;
    bool bFound = true;

    v_split.clear();

    while (bFound)
    {
        found = content.npos;
        for (int i=0;found == content.npos && i < separators.size(); ++i)
        {
            found = content.find(separators[i], pos);
        }

        if (found != content.npos)
        {
            bFound = true;

            std::string token = content.substr(pos, found - pos);

			if (token.length() > 0)
			{
                v_split.push_back(token);
            }
            
            pos = found + 1;
        }
        else
        {
            bFound = false;
        }
    }

    return 0;
}
