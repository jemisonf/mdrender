#include "gtest/gtest.h"
#include "cpp_to_html.h"
#include "md_to_cpp.h"

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
};

TEST_F(CppToHtmlTest, header_test){
  std::string expected_html = get_expected_html("headers.html");
  MdToCpp converter;
  std::string filename = TEST_IN_FILE_PATH;
  filename += "headers.md";
  converter.set_file(filename);
  MdData input = converter.get_md_data();

  CppToHtml html_maker;
  html_maker.set_data(&input);
  std::string html = html_maker.get_html();

  EXPECT_EQ(html, expected_html);
}

int main(int argc, char* argv[]){
  testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}
