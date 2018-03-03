#ifndef MDDATA_H
#define DATA_H

#include "text_node.h"

class MdData {
  public: 
    MdData();
    MdData(const MdData &);
    void operator=(const MdData &);
    ~MdData();
    void enqueue_node(const TextNode &);
    const TextNode & dequeue_node();
    const TextNode & front_node(); 
};

#endif
