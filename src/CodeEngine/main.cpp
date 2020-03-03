#include <stdlib.h>
#include <stdio.h>
#include "inja.hpp"
#include "nlohmann/json.hpp"
#include <string>
#include "c_engine/impl/toolkit/CStringToolkit.h"
#include "c_engine/interface/toolkit/Console.h"
#include "c_engine/impl/engine/cpp/CCppGeneral.h"

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

    return 0;
}