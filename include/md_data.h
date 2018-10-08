#ifndef MDDATA_H
#define MDDATA_H

#include <queue>
#include "text_node.h"

class MdData {
  protected:
    std::queue<TextNode> text_nodes;
  public: 
    MdData();
    MdData(const MdData &);
    void operator=(const MdData &);
    ~MdData();
    void enqueue_node(const TextNode &);
    bool empty();
    const TextNode dequeue_node();
    const TextNode front_node() const; 
};

#endif
