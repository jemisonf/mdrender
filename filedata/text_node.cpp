#include "text_node.h"

TextNode::TextNode() {
  this->text = "";
  this->type = "";
}
TextNode::TextNode(const std::string text, const std::string type) {
  this->text = text;
  this->type = type;
}

TextNode::TextNode(const TextNode & text_node) {
  this->text = text_node.get_text();
  this->type = text_node.get_type();
}

void TextNode::operator=(const TextNode & text_node) {
  this->text = text_node.get_text();
  this->type = text_node.get_type();
}

const std::string TextNode::get_text() const {
  return this->text;
}

const std::string TextNode::get_type() const {
  return this->type;
}

void TextNode::set_text(const std::string text) {
  this->text = text;
}

void TextNode::set_type(const std::string type) {
  this->type = type;
}

