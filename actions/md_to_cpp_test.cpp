#include "gtest/gtest.h"
#include "md_to_cpp.h"

#define TEST_FILE_PATH "../testfiles/"

class MdToCppTest : public::testing::Test {
  protected:
    virtual void SetUp() {
      
    }
    virtual void TearDown() {

    }
};

TEST_F(MdToCppTest, header_test) {
  std::string expected_outputs[7] = {"https://github.com/adam-p/markdown-here/wiki/Markdown-Cheatsheet", "H1", "H2", "H3", "H4", "H5", "H6" };
  std::string expected_types[7] = { "p", "h1", "h2", "h3", "h4", "h5", "h6" };
  MdToCpp converter;
  TextNode temp_node;
  MdData output;
  std::string filename = TEST_FILE_PATH;
  filename += "headers.md";
  converter.set_file(filename);
  output = converter.get_md_data();
  EXPECT_FALSE(output.empty());
  /*
  for (int i = 0; i < 7; i++) {
    temp_node = output.dequeue_node();
    EXPECT_EQ(temp_node.get_text(), expected_outputs[i]);
    EXPECT_EQ(temp_node.get_type(), expected_types[i]);
  }
  */
}

int main(int argc, char* argv[]) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
