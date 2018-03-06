#ifndef MD_TO_CPP_H
#define MD_TO_CPP_H

#include "../filedata/md_data.h"
#include "../filedata/text_node.h"
#include <iostream>
#include <string>
#include <fstream>

class MdToCpp {
  private:
    TextNode parse_line(const std::string);
    std::ifstream file_stream;
  public:
    MdToCpp();
    void set_file(const std::string);
    const MdData get_md_data();
};

#endif
