#ifndef CODEENGINE_CENGINE_IMPL_EXAMPLE_CPARSEFUNCTION_H_
#define CODEENGINE_CENGINE_IMPL_EXAMPLE_CPARSEFUNCTION_H_

#include <string>
#include <vector>

enum class ParseResult {
    INVALID,
    SUCCESS
};

enum class ParameterType {
    VALUE_TYPE,
    REFERENCE_TYPE
};

struct FunctionParameter {
    std::string type;
    std::string name;
    ParameterType param_type;
};

struct FunctionDS {
    std::string name;
    std::string return_type;
    std::vector<FunctionParameter> param_list;
};

class CParseFunction 
{
    public: 
        virtual ~CParseFunction() {}
        int parse_function(std::string text, FunctionDS& o);
};

#endif // !CODEENGINE_CENGINE_IMPL_EXAMPLE_CPARSEFUNCTION_H_