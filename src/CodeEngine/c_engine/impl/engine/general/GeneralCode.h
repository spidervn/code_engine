#ifndef CODEENGINE_C_ENGINE_IMPL_ENGINE_GENERAL_GENERALCODE_H__H_
#define CODEENGINE_C_ENGINE_IMPL_ENGINE_GENERAL_GENERALCODE_H__H_

#include <string> 
#include <vector>

struct VB6IfThenBlock
{
    std::string ifCondition;
    std::string ifContent;
    std::string elseContent;
    std::vector<std::string> vElseIf;

    
};

class GeneralCode
{
private:
    /* data */
public:
    GeneralCode(/* args */);
    virtual ~GeneralCode();

    int parseIfThenBlock_VB6(std::string code);

    bool isNormalCharacter(char ch);
    bool isQuotedCharacter(char ch);
};



#endif