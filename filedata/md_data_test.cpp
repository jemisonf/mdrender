#include <string>
#include "gtest/gtest.h"
#include <iostream>
#include "md_data.h"

#define INIT_TEXT "Testing"

class MdDataTest : public::testing::Test {
  protected:
    MdData test_data;
    MdData empty_data;
    TextNode test_nodes[3];
    std::string test_node_texts[3];
   
    MdDataTest() {
      test_node_texts[0] = "Test 1";
      test_node_texts[1] = "Test 2";
      test_node_texts[2] = "Test 3";
    }
    virtual void SetUp() {
      test_data = MdData();
      empty_data = MdData();
      for (int i = 0; i < 3; i++) {
        test_nodes[i].set_text(test_node_texts[i]);
        test_data.enqueue_node(test_nodes[i]);
      }
    }

    virtual void TearDown() {

    }
};

TEST_F(MdDataTest, front_node) {
  EXPECT_EQ(test_data.front_node().get_text(), test_node_texts[0]);
}

TEST_F(MdDataTest, empty) {
  EXPECT_TRUE(empty_data.empty());
}

TEST_F(MdDataTest, enqueue_node) {
  empty_data.enqueue_node(test_nodes[0]);
  std::string text_a = test_nodes[0].get_text();
  std::string text_b = empty_data.front_node().get_text();
  EXPECT_EQ(text_a, text_b);
}

TEST_F(MdDataTest, dequeue_node) {
  TextNode temp_node;
  empty_data.enqueue_node(test_nodes[0]);
  empty_data.enqueue_node(test_nodes[1]);
  temp_node = empty_data.dequeue_node();
  EXPECT_EQ(temp_node.get_text(), test_node_texts[0]);
  EXPECT_EQ(empty_data.front_node().get_text(), test_node_texts[1]);
  temp_node = empty_data.dequeue_node();
  EXPECT_EQ(temp_node.get_text(), test_node_texts[1]);
}


