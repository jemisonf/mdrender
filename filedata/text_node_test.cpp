#include "gtest/gtest.h"
#include "text_node.h"

#define INIT_TEXT "Testing"
#define INIT_TYPE "h1"

class TextNodeTest : public::testing::Test {
  protected:
    TextNode test_node;
    virtual void SetUp() {
      test_node.set_text(INIT_TEXT); 
      test_node.set_type(INIT_TYPE);
    }

    virtual void TearDown() {

    }
};

TEST_F(TextNodeTest, get_text) {
  EXPECT_EQ(test_node.get_text(), INIT_TEXT);
}

TEST_F(TextNodeTest, get_type) {
  EXPECT_EQ(test_node.get_type(), INIT_TYPE);
}

TEST_F(TextNodeTest, set_text) {
  const std::string new_text = "Testing setting text";
  test_node.set_text(new_text);
  EXPECT_EQ(new_text, test_node.get_text());
} 

TEST_F(TextNodeTest, set_type) {
  const std::string new_type = "p";
  test_node.set_type(new_type);
  EXPECT_EQ(new_type, test_node.get_type());
}

int main(int argc, char* argv[]) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
