CC = g++
exe_file = mdrender

$(exe_file): command.o help.o cpp_to_html.o md_to_cpp.o md_data.o text_node.o
	$(CC) command.o help.o cpp_to_html.o md_to_cpp.o md_data.o text_node.o -o $(exe_file)

command.o: command.cpp
	$(CC) -c command.cpp

help.o: help.cpp
	$(CC) -c help.cpp

cpp_to_html.o: ../actions/cpp_to_html.cpp
	$(CC) -c ../actions/cpp_to_html.cpp

md_to_cpp.o: ../actions/md_to_cpp.cpp
	$(CC) -c ../actions/md_to_cpp.cpp

md_data.o: ../filedata/md_data.cpp
	$(CC) -c ../filedata/md_data.cpp

text_node.o: ../filedata/text_node.cpp
	$(CC) -c ../filedata/text_node.cpp

clean:
	rm -f mdrender *.o $(exe_file)
