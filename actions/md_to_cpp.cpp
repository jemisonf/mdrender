#include "md_to_cpp.h"

MdToCpp::MdToCpp() {

}

void MdToCpp::set_file(const std::string filename) {
  this->file_stream.open(filename.c_str());
}

const MdData MdToCpp::get_md_data() {
  MdData data;
  // initialize new MdData
  // for each line in file_stream
    // call parse_line
    // add the result to MdData
  // return MdData
  return data;
}

TextNode MdToCpp::parse_line(const std::string line) {
  int text_start;
  std::string type, text = "";
  if (line[0] == '#') {
    while (line[text_start] == '#') {
      text_start++;
    }
    type = "h";
    type += (char) text_start + 49;
    text = line.substr(text_start, line.length() - text_start);
  } else if (line[0] > '0' || line[0] <= '9') {
    type = "ol";
    text = line.substr(3, line.length() - 3);
  } else if (line[0] == '-' || line[0] == '*' || line[0] == '+') {
    type = "ul";
    text = line.substr(2, line.length() - 2);
  } else {
    type = "p";
    text = line;
  }
  return TextNode(text, type);
    

   
}
