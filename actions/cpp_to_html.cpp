#include "cpp_to_html.h"

CppToHtml::CppToHtml(){

}

void CppToHtml::set_data(MdData *data){
  this->data = *data;
}

const std::string CppToHtml::get_html(){
  html = "";
  while(!data.empty()){
    std::string line = "";
    TextNode cur_node = data.dequeue_node();
    std::string cur_node_type = cur_node.get_type();
    std::string cur_node_text = cur_node.get_text();
    //header
    if (cur_node_type[0] == 'h'){
      std::string tag = "h";
      tag += cur_node_type[1];
      line += "<" + tag + ">" + cur_node_text + "</" + tag + ">\n";
    }
    //paragraph
    else if (cur_node_type[0] == 'p'){
      line += "<p>" + cur_node_text + "</p>\n";
    }
    html += line;
  }

  return this->html;

}

