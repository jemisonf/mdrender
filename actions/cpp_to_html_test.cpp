#include "gtest/gtest.h"
#include "cpp_to_html.h"

class CppToHTMLTest : public::testing::Test {

  protected:
    virtual void SetUp(){

    }
    virtual void TearDown(){

    }
};

TEST_F(CppToHTMLTest, header_test){

}

int main(int argc, char* argv[]){
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
