#include <string>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int count_leading_spaces(string line){
  unsigned int i = 0;
  int spaces = 0;
  while(i < line.length() && line[i] == ' '){
    spaces++;
  }
  return spaces;

}
void begin_list(vector<string>& file_vector, int beginning_line_no, ofstream &outFile, unsigned int * cur_written_line){
  // write starting list tag
  outFile << "<ol>\n";

  // find end of list
  unsigned int ending_line_no = beginning_line_no;
  while(file_vector.size() >= ending_line_no && 
      isdigit(file_vector[ending_line_no][0]) && 
      file_vector[ending_line_no][1] == '.') {
    ending_line_no++;
  }

  // for each line between start and end, add list tag
  for(unsigned int i = beginning_line_no; i < ending_line_no; i++){
    int md_syntax_len = 2;
    outFile << "<li>" << file_vector[i].substr(md_syntax_len, file_vector[i].length() - md_syntax_len) << "</li>\n";

  }

  //ending list tag
  outFile << "</ol>\n";
  cout << "start: " << beginning_line_no << ", end: " << ending_line_no << endl;

  (*cur_written_line) = ending_line_no;
}
int main(){
  ifstream file;
  file.open("../testfiles/lists.md");
  if (!file){
    cout << "issues" << endl;
  }
  ofstream outFile;
  outFile.open("../out/lists.html");

  string line; 

  vector<string> file_vector;
  file_vector.clear();

  // read whole file in at start
  while (getline(file, line)){
    file_vector.push_back(line);
  }

  outFile << "<html>\n<body>\n";
  for(unsigned int cur_written_line = 0; cur_written_line < file_vector.size(); cur_written_line++){ 
    if(isdigit(file_vector[cur_written_line][0]) && file_vector[cur_written_line][1] == '.'){
      cout << "list" << endl;
      begin_list(file_vector, cur_written_line, outFile, &cur_written_line);
    }
  }
  outFile << "</body>\n</html>\n";



  return 0;
}
