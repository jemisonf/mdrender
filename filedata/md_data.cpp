#include "md_data.h"

MdData::MdData() {

}

void MdData::enqueue_node(const TextNode & new_node) {
  this->text_nodes.push(TextNode(new_node));
}

const TextNode MdData::front_node() const {
  return this->text_nodes.front();
}

const TextNode MdData::dequeue_node() {
  TextNode temp_node = this->text_nodes.front();
  this->text_nodes.pop();
  return temp_node;
}
