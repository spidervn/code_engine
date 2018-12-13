#ifndef CODEENGINE_C_ENGINE_INTERFACE_ENGINE_ICOMMANDLINESUG
#define CODEENGINE_C_ENGINE_INTERFACE_APP_IAPPLICATION_H_

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