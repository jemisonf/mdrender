#include "gtest/gtest.h"
#include "md_data.h"

#define INIT_TEXT "Testing"

class MdDataTest : public::testing::Test {
  protected:
    MdData text_data;
    virtual void SetUp() {

    }

    virtual void TearDown() {

    }
};


int main(int argc, char* argv[]) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
