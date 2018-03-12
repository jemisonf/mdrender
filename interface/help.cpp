#include <iostream>
#include <cstring>

using namespace std;

void displayHelp() {

	cout << endl;
	cout << "mdrender	filename 	[...]" << endl;
	cout << endl;
	cout << "DESCRIPTION:" << endl;
	cout << "mdrender takes in a markdown file name and then parses the";
	cout << " document in order to produce an HTML or PDF file.";
	cout << " If no file ouput option is provided, the file will just";
	cout << " be outputted as plain text.";
	//see as plain text?
	//see as c++ data?
	// something about seeing in-between stage...
	cout << " Some special features of the document includes being";
	cout << " able to specify the output name.";
	//is there also a css option?

	cout << endl;
	cout << endl;
	cout << "OUTPUT OPTIONS: " << endl;
	cout << "-pdf			will produce a pdf file output" << endl;
	cout << "-html			will produce an html file output" << endl;

	cout << endl;
	cout << "OTHER OPTIONS: " << endl;
	cout << "-o [filename]		will allow you to specify a specific output name" << endl;


	cout << endl;
	cout << endl;
}


