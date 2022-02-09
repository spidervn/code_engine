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

    int token_type; // =1 Text Token
                    // =2 Quoted Token
                    // =3 Group Token
                    // 
    std::string token; // Current Token

    /*
     * State Machine
     *      FINDNEXT
     *          ---(input=NormalCharacter)---> CONTENT_SCANNING
     *          ---(input=QuotedCharacter)---> 
     * 
     *      CONTENT_SCANNING
     *          ---(input=NormalCharacter)---> CONTENT_SCANNING
     *          ---(input=QuotedCharacter)---> BEGINQUOTE
     * 
     */
    for (int i=0; i<code.length();++i)
    {
        if (state == STT_FINDNEXT)
        {
            if (isNormalCharacter(code[i]))
            {
                token = code[i];
                state = STT_CONTENT_SCANNING;   
            }
            else if (isQuotedCharacter(code[i]))
            {
                token = code[i];
                state = STT_CONTENT_SCANNING;
            }
        }
        else if (state == STT_CONTENT_SCANNING)
        {
            if (isNormalCharacter(code[i]))
            {
                token += code[i];
                state = STT_CONTENT_SCANNING;
            }
            
        }
        else if (state == STT_CONTENT_SCANNING)
        {
        }
    }
    return 0;
}

int GeneralCode::fuzzy_VB6_method_list(std::string code)
{
    // Probability of Data is Method=?
    // Display the highest probability which value > threshold.
    
    // 
    // P(codepices = ? |code) = ? 
    // 
    return true;
}

double GeneralCode::prob_IsVB6Method(std::string block)
{
    

    return 1.0;
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