GTEST_DIR = "../googletest"

default:
  g++ -isystem $(GTEST_DIR)/include -I$(GTEST_DIR) \
    -pthread -c $(GTEST_DIR)/src/gtest-all.cc
  ar -rv libgest.a gtest-all.o
