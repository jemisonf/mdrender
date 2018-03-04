#include "md_to_cpp.h"

MdToCpp::MdToCpp() {

}

void MdToCpp::set_filestream(const std::ifstream &input_stream) {
  this->file_stream = input_stream;
}

const MdData & MdToCpp::get_md_data() {
  // initialize new MdData
  // for each line in file_stream
    // call parse_line
    // add the result to MdData
  // return MdData
}

TextNode MdToCpp::parse_line(const std::string line) {
   
}
