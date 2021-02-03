#include <stdlib.h>
#include <stdio.h>
#include "inja.hpp"
#include "nlohmann/json.hpp"
#include <string>
#include "c_engine/impl/toolkit/CStringToolkit.h"
#include "c_engine/interface/toolkit/Console.h"
#include "c_engine/impl/engine/cpp/CCppGeneral.h"
#include <iostream>
#include <boost/regex.h>

using namespace std;
using namespace inja;
using json = nlohmann::json;

int example()
{
    string s1;
    nlohmann::json data;
    data["name"] = "world";

    s1 = inja::render("Hello {{ name }}!", data);
    inja::Environment env = inja::Environment();

    string result = env.render("Hello {{ name }}!", data);
    inja::Template temp = env.parse_template("./template.txt");
    result = env.render_template(temp, data);   // "Hello World"

    result = env.render_file("./template.txt", "./data.json");
    env.write(temp, data, "./result.txt");

    printf("%s\r\n", s1.c_str());
    printf("Code Engine\r\n");
    return 0;
}

int main(int argc, char const *argv[])
{
    string s1;
	
	nlohmann::json data;
    data["name"] = "world";

    s1 = inja::render("Hello {{ name }}!", data);
    inja::Environment env = inja::Environment();

    string result = env.render("Hello {{ name }}!", data);

    printf("%s\r\n", s1.c_str());
    printf("Code Engine\r\n");

    IStringToolkitPtr ptk = CStringToolkitPtrNew;
    // CStringToolkit tk;
    vector<string> v_token;
	vector<string> v_token2;
	vector<string> v_sep;

	v_sep.push_back("-");
	v_sep.push_back(";");
	v_sep.push_back("h");
    
    ptk->split("-a-b--c-", "-", v_token);
	ptk->split("-a-b-;-c-;h;", v_sep, v_token2);
    
    Console::log(v_token, ";");
	Console::log(v_token2, "|");

    // 
    // Cpp General
    //
    CCppGeneral cppg;
    cppg.generateIfDefPragma("/home/ducvd/Android", "/home/ducvd/work/2020/github/code_engine/src/CodeEngine/c_engine/interface/engine/ICommandLineSuggestion.h");

    //
    // Regular expression
    //
    const std::string str01 = "00:01";
    const std::regex rg("\\d\\d:\\d\\d:\\d\\d");
    const std::regex rg_typing("(\\d)?(\\d)?:\\d\\d:\\d\\d");
    std::smatch base_match;

    if (std::regex_match(str01, base_match, rg))
    {
        printf("Matched\r\n");
    }
    else
    {
        printf("UnMatched\r\n");
    }

    // 
    // Regular expression for cpp class extraction
    // 

    std::string cpp_content;
    const std::regex rg_class("class([\\s]+)([a-zA-Z\\-\\_]+)([\\s]+)\\{([\\w\\W]*)\\}\\;");
    // const std::regex rg_class("class[\\s]+([a-z]+)");
    // const std::regex rg_class("\\w+");
    ifstream filecpp("/home/ducvd/work/2020/github/stopwatchnc/src/StopwatchNC/interface/INcursesProgram.h");

    if (filecpp.is_open())
    {
        printf("Open ifstream\r\n");
        filecpp >> cpp_content;

        cpp_content.assign(
            (std::istreambuf_iterator<char>(filecpp)),
            (std::istreambuf_iterator<char>())
        );

    }
    else 
    {
        printf("Failed ifstream\r\n");
    }
    filecpp.close();

    // Found class
    auto rgcpp_begin = std::sregex_iterator(cpp_content.begin(), cpp_content.end(), rg_class);
    auto rgcpp_end = std::sregex_iterator();

    std::cout << "Class found " << std::distance(rgcpp_begin, rgcpp_end) << endl;
    for (std::sregex_iterator i=rgcpp_begin; i != rgcpp_end; ++i)
    {
        std::smatch m = *i;

        std::cout << m.str() << " " <<  m.size() << std::endl;
        std::cout << "\t";
        for (int i=0; i<m.size();++i)
        {
            std::cout << m[i].str() << "; ";
        }
        std::cout << endl;
        std::cout << "\tClass-name: " << m[2].str() << endl;
        std::cout << "\tClass content: " << m[4].str() << endl;
    }

    return 0;
}