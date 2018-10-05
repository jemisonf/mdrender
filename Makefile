# A sample Makefile for building Google Test and using it in user
# tests.  Please tweak it to suit your environment and project.  You
# may want to move it to your project's root directory.
#
# SYNOPSIS:
#
#   make [all]  - makes everything.
#   make TARGET - makes the given target.
#   make clean  - removes all files generated by make.

# Please tweak the following variable definitions as needed by your
# project, except GTEST_HEADERS, which you can use in your own targets
# but shouldn't modify.

# Points to the root of Google Test, relative to where this file is.
# Remember to tweak this if you move this file.
GTEST_DIR = googletest/

# Where to find user code.
USER_DIR = .

# Flags passed to the preprocessor.
# Set Google Test's header directory as a system directory, such that
# the compiler doesn't generate warnings in Google Test headers.
CPPFLAGS += -isystem $(GTEST_DIR)/include

# Flags passed to the C++ compiler.
CXXFLAGS += -g -Wall -Wextra -pthread -std=c++11

# All tests produced by this Makefile.  Remember to add new tests you
# created to the list.
# TESTS = sample1_unittest
TESTS_O = md_data_test.o text_node_test.o md_to_cpp_test.o cpp_to_html_test.o
FILES_O = md_data.o text_node.o md_to_cpp.o cpp_to_html.o

# All Google Test headers.  Usually you shouldn't change this
# definition.
GTEST_HEADERS = $(GTEST_DIR)/include/gtest/*.h \
								$(GTEST_DIR)/include/gtest/internal/*.h

# House-keeping build targets.

# TESTS = filedata/md_data_test filedata/text_node_test actions/md_to_cpp_test actions/cpp_to_html_test
all : $(TESTS_O) $(FILES_O) gtest_main.a
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $^ -o all_tests

cpp_to_html.o: actions/cpp_to_html.cpp actions/cpp_to_html.h $(GTEST_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c actions/cpp_to_html.cpp

cpp_to_html_test.o: actions/cpp_to_html_test.cpp  $(GTEST_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c actions/cpp_to_html_test.cpp

md_to_cpp.o: actions/md_to_cpp.cpp actions/md_to_cpp.h $(GTEST_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c actions/md_to_cpp.cpp

md_to_cpp_test.o: actions/md_to_cpp_test.cpp $(GTEST_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c actions/md_to_cpp_test.cpp

text_node.o: filedata/text_node.cpp filedata/text_node.h $(GTEST_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c filedata/text_node.cpp

text_node_test.o: filedata/text_node_test.cpp $(GTEST_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c filedata/text_node_test.cpp 

md_data.o: filedata/md_data.cpp filedata/md_data.h $(GTEST_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c filedata/md_data.cpp

md_data_test.o: filedata/md_data_test.cpp $(GTEST_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c filedata/md_data_test.cpp 



clean :
	rm -f $(TESTS) gtest.a gtest_main.a *.o

# Builds gtest.a and gtest_main.a.

# Usually you shouldn't tweak such internal variables, indicated by a
# trailing _.
GTEST_SRCS_ = $(GTEST_DIR)/src/*.cc $(GTEST_DIR)/src/*.h $(GTEST_HEADERS)

# For simplicity and to avoid depending on Google Test's
# implementation details, the dependencies specified below are
# conservative and not optimized.  This is fine as Google Test
# compiles fast and for ordinary users its source rarely changes.
gtest-all.o : $(GTEST_SRCS_)
	$(CXX) $(CPPFLAGS) -I$(GTEST_DIR) $(CXXFLAGS) -c \
		$(GTEST_DIR)/src/gtest-all.cc

gtest_main.o : $(GTEST_SRCS_)
	$(CXX) $(CPPFLAGS) -I$(GTEST_DIR) $(CXXFLAGS) -c \
		$(GTEST_DIR)/src/gtest_main.cc

gtest.a : gtest-all.o
	$(AR) $(ARFLAGS) $@ $^

gtest_main.a : gtest-all.o gtest_main.o
	$(AR) $(ARFLAGS) $@ $^

# Builds a sample test.  A test should link with either gtest.a or
# gtest_main.a, depending on whether it defines its own main()
# function.

# sample1.o : $(USER_DIR)/sample1.cc $(USER_DIR)/sample1.h $(GTEST_HEADERS)
# 	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(USER_DIR)/sample1.cc

# sample1_unittest.o : $(USER_DIR)/sample1_unittest.cc \
	$(USER_DIR)/sample1.h $(GTEST_HEADERS)
# 	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(USER_DIR)/sample1_unittest.cc

# sample1_unittest : sample1.o sample1_unittest.o gtest_main.a
# 	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -lpthread $^ -o $@



