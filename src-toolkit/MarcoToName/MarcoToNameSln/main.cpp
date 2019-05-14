#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <fstream>
#include <iostream>
#include <iterator>
#include <regex>

using namespace std;

int test1()
{
	std::string lines[] = { "Roses are #ff0000",
		"violets are #0000ff",
		"all of my base are belong to you" };

	std::regex color_regex("#([a-f0-9]{2})"
		"([a-f0-9]{2})"
		"([a-f0-9]{2})");

	// simple match
	for (const auto &line : lines) {
		std::cout << line << ": " << std::boolalpha
			<< std::regex_search(line, color_regex) << '\n';
	}
	std::cout << '\n';

	// show contents of marked subexpressions within each match
	std::smatch color_match;
	for (const auto& line : lines) {
		if (std::regex_search(line, color_match, color_regex)) {
			std::cout << "matches for '" << line << "'\n";
			std::cout << "Prefix: '" << color_match.prefix() << "'\n";
			for (size_t i = 0; i < color_match.size(); ++i)
				std::cout << i << ": " << color_match[i] << '\n';
			std::cout << "Suffix: '" << color_match.suffix() << "\'\n\n";
		}
	}

	// repeated search (see also std::regex_iterator)
	std::string log(R"(
        Speed:	366
        Mass:	35
        Speed:	378
        Mass:	32
        Speed:	400
	Mass:	30)");
	std::regex r(R"(Speed:\t\d*)");
	std::smatch sm;
	while (regex_search(log, sm, r))
	{
		std::cout << sm.str() << '\n';
		log = sm.suffix();
	}

	// C-style string demo
	std::cmatch cm;
	if (std::regex_search("this is a test", cm, std::regex("test")))
		std::cout << "\nFound " << cm[0] << " at position " << cm.prefix().length();
	return 0;
}

int main(int argc, char const *argv[])
{
    if (argc < 2)
    {
        printf("Usage: %s <<file_header_or_source>> \r\n", argv[0]);
        return 1;
    }

	// return test1();

    std::string txt("#efine STATE_MONEY001_NO_FILE				            300001");
	const std::regex rg("\\#define\\s+([A-Za-z0-9\\_]+)\\s+([0-9]+)");
	// const std::regex rg("[A-Za-z0-9\\_]+");
    


		string code = "string getDefineMarcoName(int defined_value)\r\n{\r\n";
		string line;
		ifstream ifile(argv[1]);
    

		string arr[] = 
		{
			"#define",
			" "
		};

		std::vector<string> v_marco;
		std::vector<string> v_number;

		while (getline(ifile, line))
		{
			std::smatch pieces_match;

			if (std::regex_search(line, pieces_match, rg) && pieces_match.size() > 2)
			{
				std::ssub_match sub_match_df = pieces_match[1];
				std::ssub_match sub_match_num = pieces_match[2];

				std::string marco = sub_match_df.str();
				std::string num = sub_match_num.str();

				v_marco.push_back(marco);
				v_number.push_back(num);
			}
		}
		
		code += "string arrName[] = {\r\n";
		int n = v_marco.size();
		for (int i = 0; i < v_marco.size();++i)
		{
			if (i == n - 1)
			{
				code += "\"" + v_marco[i] + "\"\r\n";
			}
			else
			{
				code += "\"" + v_marco[i] + "\",\r\n";
			}
		}
		code += "};\r\n";

		code += "int arrNum[] = {\r\n";
		for (int i = 0; i < v_number.size();++i)
		{
			if (i == n - 1)
			{
				code +=  v_number[i] + "\r\n";
			}
			else
			{
				code += v_number[i] + ",\r\n";
			}
		}
		code += "};\r\n";

		code += R"(
	int n = sizeof(arrNum)/sizeof(arrNum[0]);
	for (int i=0; i<n;++i)
	{
		if (arrNum[i]==defined_value)
		{
			return arrName[i];
		}
	}

	return "";
			)";

		code += "}\r\n";

		cout << code;
    return 0;
}