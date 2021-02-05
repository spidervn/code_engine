#include "GeneralCode.h"
#include <string>

using namespace std;

GeneralCode::GeneralCode(/* args */)
{}

GeneralCode::~GeneralCode()
{}

/* 
 * Define Input and Output:
 *  
 */
int GeneralCode::parseIfThenBlock_VB6(std::string code)
{
    int STT_START = 1;
    int STT_FINDNEXT = 2;
    int STT_CONTENT_SCANNING = 3;
    
    int state = STT_FINDNEXT;

    std::string token; // Current Token

    for (int i=0; i<code.length();++i)
    {
        if (state == STT_FINDNEXT)
        {
            if (isNormalCharacter(code[i]))
            {
                token = code[i];
            }
        }
        else if (state == STT_CONTENT_SCANNING)
        {

        }
    }

    

    return 0;
}

bool GeneralCode::isNormalCharacter(char ch)
{
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' || ch <= 'Z') || (ch >= '0' && ch <='9') || 
            (ch == '-' || ch == '_');
}

bool GeneralCode::isQuotedCharacter(char ch)
{
    return (ch == '(' || ch == ')' || ch == '{' || ch == '}');
}