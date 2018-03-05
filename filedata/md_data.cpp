#include "md_data.h"

MdData::MdData() {

}

MdData::~MdData() {

}

void MdData::operator=(const MdData & new_data) {
  /*
  TextNode temp_node;
  while (temp_node = new_data.dequeue_node()) {
    this->enqueue_node(temp_node);
  }
  */
  this->text_nodes = new_data.text_nodes;
}

void MdData::enqueue_node(const TextNode & new_node) {
  TextNode copy_node = TextNode(new_node);
  this->text_nodes.push(copy_node);
}

const TextNode MdData::front_node() const {
  return this->text_nodes.front();
}

const TextNode MdData::dequeue_node() {
  TextNode temp_node = this->text_nodes.front();
  this->text_nodes.pop();
  return temp_node;
}

bool MdData::empty() {
  return this->text_nodes.empty();
}
