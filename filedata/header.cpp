#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

void header(ofstream &outFile, char x[], ifstream &inFile){
	//gets how many '#' which will be the number for <h_> 
	//	i.e. strlen == 5 then <h5>
	int numNum = strlen(x);
	outFile << "<h" << numNum << ">";

	// gets the rest of the line 
	char line[200];
	memset(line, '\0', 200);
	inFile >> line;
	outFile << line;

	outFile << "</h" << numNum <<">\n";
}

int main() {
	//opens sample .md file 
	ifstream file;
	file.open("some.md");
	if (!file) 
		cout << "issues" << endl;

	//opens a random .html file to write to 
	ofstream outFile;
	outFile.open("hopes.html");

	// starts the html doc 
	outFile << "<!DOCTYPE html>\n";
	//is head necessary..... 
	outFile << "<body>\n\n";

	//reads each line of the file
	char x[50];
		memset(x, '\0', 50);
	while (file >> x) {
		/* if the first char of the line is '#' then its some sort of 
		header */
		if (x[0] == '#') {
			header(outFile, x, file);
		}
	}

	//ends the html doc
	outFile << "\n</body>\n\n";
	outFile << "</html>\n\n";
}
