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
    std::string last_node_type = "";
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

    else if (cur_node_type[0] == 'o') {
/*
      if (last_node_type[0] != 'o') {
         std::string hold = "<ol>" + '\n';
         html += hold;
      }
*/
      if(html[html.length() - 3] != 'i'){
        line += "<ol>\n";
      }
      line += "<li>" + cur_node_text + "</li>\n";
      if(data.empty() || data.front_node().get_type() != "ol"){
        line += "</ol>\n";
      }     
    }

    else if (cur_node_type[0] == 'u') {
      if(html[html.length() - 3] != 'i'){
        line += "<ul>\n";
      }
      line += "<li>" + cur_node_text + "</li>\n";
      if(data.empty() || data.front_node().get_type() != "ul"){
        line += "</ul>\n";
      }
    }

    std::size_t found = line.find("**");
    if (found!=std::string::npos) {
      line.replace(line.begin()+found, line.begin()+found+2,"<b>");
      found = line.find("**");
      line.replace(line.begin()+found,line.begin()+found+2,"</b>");
    }

    found = line.find("__");
    if (found!=std::string::npos) {
      line.replace(line.begin()+found, line.begin()+found+2,"<b>");
      found = line.find("__");
      line.replace(line.begin()+found,line.begin()+found+2,"</b>");
    }

    found = line.find("*");
    if (found!=std::string::npos) {
      line.replace(line.begin()+found,line.begin()+found+1,"<em>");
      found = line.find("*");
      line.replace(line.begin()+found,line.begin()+found+1,"</em>");
    }

    found = line.find("_");
    if (found!=std::string::npos) {
      line.replace(line.begin()+found, line.begin()+found+1,"<em>");
      found = line.find("_");
      line.replace(line.begin()+found,line.begin()+found+1,"</em>");
    }


    found = line.find("~~");
    if (found!=std::string::npos) {
      line.replace(line.begin()+found,line.begin()+found+2,"<del>");
      found = line.find("~~");
      line.replace(line.begin()+found,line.begin()+found+2,"</del>");
    }

    last_node_type = cur_node_type;
    html += line;

  }

  return this->html;

}

