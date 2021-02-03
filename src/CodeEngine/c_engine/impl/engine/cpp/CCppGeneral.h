#ifndef CODEENGINE_C_ENGINE_INTERFACE_ENGINE_CPP_CCPPGENERAL_H_
#define CODEENGINE_C_ENGINE_INTERFACE_ENGINE_CPP_CCPPGENERAL_H_

#include "interface/engine/cpp/ICppGeneral.h"
#include <string>

class CCppGeneral: public ICppGeneral
{
private:
    /* data */
protected:
    void print_captures(const std::string& regx, const std::string& text);

public:
    CCppGeneral(/* args */);
    virtual ~CCppGeneral();

    std::string generateIfDefPragma(
        std::string path_base,
        std::string header_file);

    int parseClassDef(std::string code, CppClassDef& def);

    int bracket_stack_parser(std::string class_content, int& open_bracket_pos, int& close_bracket_pos);

    int parse_header(std::string header_file, CppHeaderInfo& header);
};

#endif