#include "gtest/gtest.h"
#include "cpp_to_html.h"
#include "md_to_cpp.h"

#define TEST_IN_FILE_PATH "testfiles/"
#define TEST_OUT_FILE_PATH "testfiles/prewritten_out/"

using namespace std;

class CppToHtmlTest : public::testing::Test {
  public:
    std::string get_expected_html(std::string test_name){
      std::string path = TEST_OUT_FILE_PATH + test_name;
      std::ifstream ifs(path.c_str());
      std::string html( (std::istreambuf_iterator<char>(ifs) ),
          (std::istreambuf_iterator<char>()    ) );
      return html;
    }
  protected:
    virtual void SetUp(){
    }
    virtual void TearDown(){
    }
};

void make_md_data_header(MdData & input){
  TextNode start_node;
  start_node.set_text("https://github.com/adam-p/markdown-here/wiki/Markdown-Cheatsheet");
  start_node.set_type("p");
  input.enqueue_node(start_node);

  TextNode header_node;
  string tags[] = {"h1", "h2", "h3", "h4", "h5", "h6"};
  string text[] = {"H1", "H2", "H3", "H4", "H5", "H6"};
  for(int i = 0; i < 6; i++){
    header_node.set_text(text[i]);
    header_node.set_type(tags[i]);
    input.enqueue_node(header_node);
  }
}

TEST_F(CppToHtmlTest, header_test){
  std::string expected_html = get_expected_html("headers.html");
  MdData input;
  make_md_data_header(input);

  CppToHtml html_maker;
  html_maker.set_data(&input);
  std::string html = html_maker.get_html();

  EXPECT_EQ(html, expected_html);
}
