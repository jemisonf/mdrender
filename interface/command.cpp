#include <iostream>
#include <cstring>
#include <fstream>
#include "help.h"
#include "../actions/cpp_to_html.h"
#include "../actions/md_to_cpp.h"

using namespace std;

int main(int argc, char* argv[]) {
	string some;

	if (argc == 1) 
		cout << "no flag entered" << endl;

	//assuming format be "a.out --help"
	else if (argc == 2) {
		if (strstr (argv[1], "help") != NULL) 
			displayHelp();
	}

	//"a.out {file.md} html/pdf"
	else if (argc > 2) {
		//sends to md_to_cpp
		MdToCpp toCpp;
		toCpp.set_file(argv[1]);

		//gets the data stuff 
		MdData data=toCpp.get_md_data();

		//sends to cpp_to_html
		CppToHtml cpTohtml;	
		cpTohtml.set_data(&data);
		some = cpTohtml.get_html();

	}

	//outputs to specified file
	//"a.out 'file.md' html -outFile {file.html}"
	if (argv[4] and strstr (argv[4], ".html")) {
		ofstream outFile;
		outFile.open(argv[4]);
		outFile << some;
	}
	
	//"a.out 'file.md' html -out" -- outputs to screen
	else 
		cout << some;

	return 0;
}
