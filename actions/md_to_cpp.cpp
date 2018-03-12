#include "md_to_cpp.h"

MdToCpp::MdToCpp() {

}

void MdToCpp::set_file(const std::string filename) {
  this->file_stream.open(filename.c_str());
}

const MdData MdToCpp::get_md_data() {
  MdData data;
  std::string line;
  while (std::getline(this->file_stream, line)) {
    data.enqueue_node(parse_line(line));
  }
  return data;
}

TextNode MdToCpp::parse_line(const std::string line) {
  int text_start = 0;
  std::string type, text = "";
  if (line[0] == '#') {
    while (line[text_start] == '#') {
      text_start++;
    }
    type = "h";
    type += (char) text_start + 48;
    text = line.substr(text_start + 1, line.length() - (text_start + 1));
  } else if ((line[0] > '0' && line[0] <= '9') 
      && (line[1] && line[1] == '.' )
      && (line[2] && line[2] == ' ')) {
    type = "ol";
    text = line.substr(3, line.length() - 3);
  } else if ((line[0] == '-' || line[0] == '*' || line[0] == '+') 
      && (line[1] && line[1] == ' ')) {
    type = "ul";
    text = line.substr(2, line.length() - 2);
  } else {
    type = "p";
    text = line;
  }
  return TextNode(text, type);
    

   
}
