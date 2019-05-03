#include "CParseFunction.h"

int CParseFunction::parse_function(std::string text, FunctionDS& o)
{
    ParseResult r;
    int n = text.length();
    
    char arr[1000];
    int narr = 0;
    int i = 0;

    while (i < n)
    {
        if (text[i] == ',')
        {

        }
        else if (text[i] == ';')
        {

        }
        else if (text[i] == ' ')
        {

        }
        else 
        {
            arr[narr++] = text[i];
        }
    }

    return 0;
}