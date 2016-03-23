#include "ctemplate.h"
#include <string>

void cTemplate::Process()
{
	std::string fmakefile="cc=gcc\ncflags=-Wall -O\nobjs=main.o\nexe=";
	fmakefile+=getdirname();
	fmakefile+="\nbin: $(exe)\n\n.c.o:\n\t$(cc) $(cflags) -c $< -o $@\n\n$(exe):$(objs)\n\t$(cc) $(cflags) -o $@ $(objs)\n\nrun: $(exe)\n\t./$(exe)\n\nclean:\n\trm -f *.o $(exe)";

	std::string fmain="#include <stdio.h>\n\nint main(int argc, char* argv[])\n{\n\n\treturn 0;\n}";

	append("Makefile",fmakefile);
	append("main.c", fmain);
	createDir();
	flush();
}
void cppTemplate::Process()
{
	std::string fmakefile="cc=g++\ncflags=-Wall -O\nobjs=main.o\nexe=";
	fmakefile+=getdirname();
	fmakefile+="\nbin: $(exe)\n\n.cc.o:\n\t$(cc) $(cflags) -c $< -o $@\n\n$(exe):$(objs)\n\t$(cc) $(cflags) -o $@ $(objs)\n\nrun: $(exe)\n\t./$(exe)\n\nclean:\n\trm -f *.o $(exe)";

	std::string fmain = "#include <iostream>\n\nint main(int argc, char* argv[])\n{\n\n\treturn 0;\n}";
	append("Makefile",fmakefile);
	append("main.cc",fmain);
	createDir();
	flush();
}
