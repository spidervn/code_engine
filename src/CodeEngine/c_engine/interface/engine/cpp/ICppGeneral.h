#ifndef CODEENGINE_C_ENGINE_INTERFACE_ENGINE_CPP_ICPPGENERAL_H_
#define CODEENGINE_C_ENGINE_INTERFACE_ENGINE_CPP_ICPPGENERAL_H_

#include "interface/engine/cpp/ICppStructs.h"
#include <string>
#include <vector>
#include <tuple>

struct CppHeaderInfo {
    std::vector<std::tuple<int, int>> ls_ifdef; 
    std::vector<std::string> ls_include;


};

class ICppGeneral
{
private:
    /* data */
public:
    virtual ~ICppGeneral() {}
    virtual std::string generateIfDefPragma(
        std::string path_base,
        std::string header_file
    ) = 0;

    virtual int parseClassDef(std::string code, CppClassDef& def) = 0;

    virtual int bracket_stack_parser(std::string class_content, int& open_bracket_pos, int& close_bracket_pos) = 0;

    virtual int parse_header(std::string header_file, CppHeaderInfo& header) = 0;
    
};

#endif