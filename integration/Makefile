GTEST_DIR = ../googletest/
USER_DIR = .
FILEDATA_INCL = md_data.o text_node.o
FILEDATA_DIR = ../filedata
ACTION_INCL = md_to_cpp.o cpp_to_html.o
ACTION_DIR = ../actions
#INTERFACE_INCL = command.o help.o
INTERFACE_INCL = help.o
INTERFACE_DIR = ../interface

CPPFLAGS += -isystem $(GTEST_DIR)/include

CXXFLAGS += -g -Wall -Wextra -pthread

#TESTS = text_node_test md_data_test
#TESTS = cpp_to_html_test md_to_cpp_test 
TESTS = integration_test

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

gtest_main.a : gtest-all.o gtest_main.o
	$(AR) $(ARFLAGS) $@ $^

md_data.o : $(FILEDATA_DIR)/md_data.cpp $(FILEDATA_DIR)/md_data.h $(GTEST_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(FILEDATA_DIR)/md_data.cpp

text_node.o : $(FILEDATA_DIR)/text_node.cpp $(FILEDATA_DIR)/text_node.h $(GTEST_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(FILEDATA_DIR)/text_node.cpp

md_to_cpp.o : $(ACTION_DIR)/md_to_cpp.cpp $(ACTION_DIR)/md_to_cpp.h $(GTEST_HEADERS) 
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(ACTION_DIR)/md_to_cpp.cpp

cpp_to_html.o : $(ACTION_DIR)/cpp_to_html.cpp $(ACTION_DIR)/cpp_to_html.h $(GTEST_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(ACTION_DIR)/cpp_to_html.cpp  

#command.o : $(INTERFACE_DIR)/command.cpp  $(GTEST_HEADERS)
#	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(INTERFACE_DIR)/command.cpp

help.o : $(INTERFACE_DIR)/help.cpp $(INTERFACE_DIR)/help.h $(GTEST_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(INTERFACE_DIR)/help.cpp


integration_test.o : $(USER_DIR)/integration_test.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(USER_DIR)/integration_test.cpp 

#integration_test : md_data.o text_node.o md_to_cpp.o cpp_to_html.o command.o help.o integration_test.o gtest_main.a 
integration_test : md_data.o text_node.o md_to_cpp.o cpp_to_html.o help.o integration_test.o gtest_main.a 
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -lpthread $^ -o $@
#md_to_cpp_test.o : $(USER_DIR)/md_to_cpp_test.cpp \
#	$(USER_DIR)/md_to_cpp.h $(GTEST_HEADERS)
#	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(USER_DIR)/md_to_cpp_test.cpp
