#ifndef MD_TO_CPP_H
#define MD_TO_CPP_H

#include "../filedata/md_data.h"
#include <iostream>
#include <fstream>

class MdToCpp {
  public:
    MdToCpp();
    void set_filestream(const std::ifstream &);
    const MdData & get_md_data();
}

#endif
