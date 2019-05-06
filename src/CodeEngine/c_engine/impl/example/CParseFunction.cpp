#include "CParseFunction.h"

#include <string>
#include <vector>
/* 
 * Approaching:
 *      01- State Machine
 * 
 */

enum class ElementType
{
    CONTINUOUS,
    SPLIT,
    PARENTHESES_GROUP,
    CURLY_BRACKETS_GROUP,
    END
};

struct ParseResult
{
    ElementType type;
    std::string content;
};


int CParseFunction::parse_function(std::string text, FunctionDS& o)
{
    ParseResult r;
    int n = text.length();
    
    char arr[1000];
    int narr = 0;
    int i = 0;

    /* 
     * Formatted, 
     *  [RETURN_TYPE][SPACE][NAME]([ARGUMENTS])[END]
     *  [RETURN_TYPE][SPACE][NAME]([ARGUMENTS]) {[CONTENT]}
     *  [RETURN_TYPE][SPACE][NAME]([ARGUMENTS]) {[CONTENT]}[END]
     * 
     * [RETURN_TYPE]=?
     *  [RETURN_TYPE][SPACE][NAME][SPACE]([SPACE][ARGUMENTS][SPACE])
     * [ret-type]
     */

    // Data-structure? 
    // Matching 


    // Find all continuous elements 
    int scanning_type;
    ElementType current_type;

    current_type = ElementType::CONTINUOUS;
    int STT_SCANNING = 0;

    for (int i=0; i<n; ++i)
    {
        if (text[i] == ' ')
        {
            /*-----*/

        }
        else if (text[i] == '(' || text[i] == ')')
        {
            /* */
        }
        else if (text[i] == '{' || text[i] == '}')
        {
            /* */
        }
    }

    /*
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
                // arr[narr++] = text[i];
            }
            else 
            {
                arr[narr++] = text[i];
            }
        }
    */
    return 0;
}