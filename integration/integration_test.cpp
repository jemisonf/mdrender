#include "gtest/gtest.h"
#include "../actions/cpp_to_html.h"
#include "../actions/md_to_cpp.h"

#define TEST_IN_FILE_PATH "../testfiles/"
#define TEST_OUT_FILE_PATH "../testfiles/prewritten_out/"

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
    std::string arr[7]= { "https://github.com/adam-p/markdown-here/wiki/Markdown-Cheatsheet", "# H1", "## H2", "### H3", "#### H4", "##### H5", "###### H6" };
};

TEST_F(CppToHtmlTest, header_test){
  std::string expected_html = get_expected_html("headers.html");
  MdToCpp converter;
//  std::string filename = TEST_IN_FILE_PATH;
//  filename += "headers.md";
  
  ofstream filename;
  filename.open("testOutput.md");
  for (int i = 0; i < 7; i++) {
	filename << arr[i];
	filename << '\n';
  }
  filename.close();

  converter.set_file("testOutput.md");
  MdData input = converter.get_md_data();

  CppToHtml html_maker;
  html_maker.set_data(&input);
  std::string html = html_maker.get_html();
  EXPECT_EQ(html, expected_html);
}
