#ifndef CODEENGINE_C_ENGINE_IMPL_ENGINE_STRING_CSTRINGUTIL_H_
#define CODEENGINE_C_ENGINE_IMPL_ENGINE_STRING_CSTRINGUTIL_H_

#include <memory>
#include <vector>
#include <string>
#include "interface/engine/string/IStringUtil.h"

class CStringUtil: public IStringUtil
{
private:
    /* data */
public:
    CStringUtil(/* args */);
    virtual ~CStringUtil();
    int toUpper(std::string, std::string&);

    int split_sentence(std::string content, std::vector<std::string> vsentence);

    int split_paragraph(std::string content, std::vector<std::string> vpara);

	static bool ends_width(const std::wstring& wstr, const std::wstring& suffix);

    int fuzzy_find(std::string wholecontent, std::string strfind);

    int distance(std::string str1, std::string str2);    
};

#define CStringUtilPtrNew std::make_shared<CStringUtil>

#endif