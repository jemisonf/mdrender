GTEST_DIR = ../googletest/
USER_DIR = .
FILEDATA_INCL = md_data.o text_node.o
FILEDATA_DIR = ../filedata


CPPFLAGS += -isystem $(GTEST_DIR)/include

CXXFLAGS += -g -Wall -Wextra -pthread

#TESTS = text_node_test md_data_test
TESTS = md_to_cpp_test 

GTEST_HEADERS = $(GTEST_DIR)/include/gtest/*.h \
	$(GTEST_DIR)/include/gtest/internal/*.h

all : $(TESTS)

clean :
	rm -f $(TESTS) gtest.a gtest_main.a *.o

GTEST_SRCS_ = $(GTEST_DIR)/src/*.cc $(GTEST_DIR)/src/*.h $(GTEST_HEADERES)

gtest-all.o : $(GTEST_SRCS_)
	$(CXX) $(CPPFLAGS) -I$(GTEST_DIR) $(CXXFLAGS) -c \
		$(GTEST_DIR)/src/gtest-all.cc

gtest_main.o : $(GTEST_SRCS_)
	$(CXX) $(CPPFLAGS) -I$(GTEST_DIR) $(CXXFLAGS) -c \
		$(GTEST_DIR)/src/gtest_main.cc

gtest.a : gtest-all.o
	$(AR) $(ARFLAGS) $@ $^

md_data.o : $(FILEDATA_DIR)/md_data.cpp $(FILEDATA_DIR)/md_data.h $(GTEST_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(FILEDATA_DIR)/md_data.cpp

text_node.o : $(FILEDATA_DIR)/text_node.cpp $(FILEDATA_DIR)/text_node.h $(GTEST_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(FILEDATA_DIR)/text_node.cpp

gtest_main.a : gtest-all.o gtest_main.o
	$(AR) $(ARFLAGS) $@ $^


md_to_cpp.o : $(USER_DIR)/md_to_cpp.cpp $(USER_DIR)/md_to_cpp.h $(GTEST_HEADERS) 
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(USER_DIR)/md_to_cpp.cpp

md_to_cpp_test.o : $(USER_DIR)/md_to_cpp_test.cpp \
	$(USER_DIR)/md_to_cpp.h $(GTEST_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(USER_DIR)/md_to_cpp_test.cpp

md_to_cpp_test : md_to_cpp.o md_to_cpp_test.o gtest_main.a $(FILEDATA_INCL)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -lpthread $^ -o $@


cpp_to_html.o: $(USER_DIR)/cpp_to_html.cpp $(USER_DIR)/cpp_to_html.h $(GTEST_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(USER_DIR)/cpp_to_html.cpp

cpp_to_html_test.o: $(USER_DIR)/cpp_to_html_test.cpp \
	$(USER_DIR)/cpp_to_html.h $(GTEST_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(USER_DIR)/cpp_to_html_test.cpp

cpp_to_html_test: cpp_to_html.o cpp_to_html_test.o gtest_main.a $(FILEDATA_INCL)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -lpthread $^ -o $@
