#ifndef CPP_TO_HTML_H
#define CPP_TO_HTML_H

#include "md_data.h"
#include "text_node.h"
#include <iostream>
#include <string>
#include <fstream>

class CppToHtml {
  public:
    CppToHtml();
    void set_data(MdData*);
    const std::string get_html();
  private:
    std::string html;
    MdData data;
};


#endif
