# Requirements

Only tested in Linux. 

Requires the GNU compiler

To use the project, clone the repository, then run ”make” in the base
directory. This will compile all of the tests and generate linker files for each
component of the project. You can also enter the directory for each package
(actions, filedata, or interface) and compile individual tests for those parts
of the project. If you run make in the interface directory, it will compile an
”mdrender” binary that you can use to run the program itself.

Functionality for mdrender is limited, but you can render markdown to
html with the format ”mdrender [source.md] -html -o [output.html].
