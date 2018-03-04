#ifndef TEXT_NODE_H
#define TEXT_NODE_H

#include <string>

class TextNode {
  private:
    std::string text;
    std::string type;
  public:
    TextNode();
    TextNode(const std::string, const std::string);
    TextNode(const TextNode &);
    void operator=(const TextNode &);
    const std::string get_text() const;
    const std::string get_type() const;
    void set_text(const std::string);
    void set_type(const std::string);
};

#endif
