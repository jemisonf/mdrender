#ifndef MDDATA_H
#define DATA_H

#include "TextNode.h"

class MdData {
  public: 
    MdData();
    MdDate(const MdData &);
    void operator=(const MdData &);
    ~MdData();
    void enqueue_node(const TextNode &);
    const TextNode & dequeue_node();
    const TextNode & front_node(); 
}

#endif
