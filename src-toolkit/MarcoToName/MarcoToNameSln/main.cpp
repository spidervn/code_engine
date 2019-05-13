#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <fstream>
#include <iostream>
#include <iterator>
#include <regex>

using namespace std;

int main(int argc, char const *argv[])
{
    if (argc < 2)
    {
        printf("Usage: %s <<file_header_or_source>> \r\n", argv[0]);
        return 1;
    }
    std::string txt("#define STATE_MONEY001_NO_FILE				            300001");
    const std::regex rg("\\s+[A-Za-z0-9\\_]+\\s+[0-9]+");
	// const std::regex rg("[A-Za-z0-9\\_]+");
    std::smatch pieces_match;

   if (std::regex_search(txt, pieces_match, rg))
   {
        printf("Matched\r\n");
        for (size_t i = 0; i < pieces_match.size(); ++i) {
                std::ssub_match sub_match = pieces_match[i];
                std::string piece = sub_match.str();
                std::cout << "  submatch " << i << ": " << piece << '\n';
        }  
   }

    /*
		string code = "string getDefineMarcoName(int defined_value)\r\n{";
		string line;
		ifstream ifile(argv[1]);
    

		string arr[] = 
		{
			"#define",
			" "
		};

		while (getline(ifile, line))
		{
			if (line.find("#define"))
			{

			}
		}

		code += "}\r\n";
    */

    return 0;
}