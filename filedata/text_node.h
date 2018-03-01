#ifndef TEXT_NODE_H
#define TEXT_NODE_H

#include <string>

class TextNode {
  public:
    TextNode();
    TextNode(const TextNode &);
    void operator=(const TextNode &);
    ~TextNode();
    const string get_text();
    const string get_type();
    void set_text(const string);
    void set_type(const string);
}

#endif
