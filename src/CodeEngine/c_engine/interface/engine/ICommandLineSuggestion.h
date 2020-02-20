#ifndef CODEENGINE_C_ENGINE_INTERFACE_ENGINE_ICOMMANDLINESUGGESTION_H
#define CODEENGINE_C_ENGINE_INTERFACE_ENGINE_ICOMMANDLINESUGGESTION_H

#include <string>
#include <vector>

class ICommandLineSuggestion
{
private:
    /* data */
public:
    virtual ~ICommandLineSuggestion() {}
    virtual int suggest(std::string str_Typing, std::vector<std::string>  vSuggestion) = 0;
};

#endif