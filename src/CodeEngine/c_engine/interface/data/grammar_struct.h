#ifndef CODEENGINE_C_ENGINE_INTERFACE_DATA_GRAMMAR_STRUCT_H_
#define CODEENGINE_C_ENGINE_INTERFACE_DATA_GRAMMAR_STRUCT_H_

#include <string>
#include <vector>

struct GrammarStruct
{
    int id;
    std::string code;
    std::string description;
};

struct CommandLineRule
{
    int id;
    std::vector<std::string> tags;
};

// A matching rules
// A string for matching rules

#endif