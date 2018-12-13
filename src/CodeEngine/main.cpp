#include <stdlib.h>
#include <stdio.h>
#include "inja.hpp"
#include "nlohmann/json.hpp"
#include <string>

using namespace std;
using namespace inja;
using json = nlohmann::json;

int example()
{
    string s1;
    json data;
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
    json data;
    data["name"] = "world";

    s1 = inja::render("Hello {{ name }}!", data);
    inja::Environment env = inja::Environment();

    string result = env.render("Hello {{ name }}!", data);

    printf("%s\r\n", s1.c_str());
    printf("Code Engine\r\n");
    return 0;
}