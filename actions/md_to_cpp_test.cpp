#include "gtest/gtest.h"
#include "md_to_cpp.h"

#define TEST_FILE_PATH "../testfiles/"
#define TEST_FILE_NAME "test.md"

class MdToCppTest : public::testing::Test {
  public:
    MdToCppTest() {
    }
  protected:
    std::string expected_outputs[];
    std::string expected_types[];
    virtual void SetUp() {
      
    }
    virtual void TearDown() {

    }
};

TEST_F(MdToCppTest, header_test) {
  MdToCpp converter;
  TextNode temp_node;
  MdData output;
  std::string filename = TEST_FILE_NAME;
  std::string expected_outputs[] = {"https://github.com/adam-p/markdown-here/wiki/Markdown-Cheatsheet", "H1", "H2", "H3", "H4", "H5", "H6" };
  std::string expected_types[] = { "p", "h1", "h2", "h3", "h4", "h5", "h6" };
  std::string input_types[] = { "", "# ", "## ", "### ", "#### ", "##### ", "###### " };
  std::ofstream test_file;
  test_file.open(filename.c_str());
  for (int i = 0; i < 7; i++) {
    test_file << input_types[i] << expected_outputs[i] << "\n";
  }
  test_file.close();
  converter.set_file(filename);
  output = converter.get_md_data();
  EXPECT_FALSE(output.empty());
  if (!output.empty()) {
    for (int i = 0; i < 7; i++) {
      temp_node = output.dequeue_node();
      EXPECT_EQ(temp_node.get_text(), expected_outputs[i]);
      EXPECT_EQ(temp_node.get_type(), expected_types[i]);
    }
  }
}
