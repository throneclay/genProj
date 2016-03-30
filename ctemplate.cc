#include "ctemplate.h"
#include <string>

using namespace std;

void cTemplate::genMakefile(string &fmakefile,const string projname)
{
	string comment="# This file is generated by genProj program.n\n# ";
	comment+=timeInfo;
	comment+="\n";
	string cc="cc=gcc\n";
	string cflags="cflags=-Wall -O\n";
	//string libflags;
	//string includeflags;
	string obj="objs=main.o\n";
	string exe="exe=";
	exe+=projname;
	exe+="\n\n";

	string bin="all: bin\nbin: $(exe)\n\n";
	string compile=".c.o:\n\t$(cc) $(cflags) -c $< -o $@\n\n";
	string link="$(exe):$(objs)\n\t$(cc) $(cflags) -o $@ $(objs)\n\nrun: $(exe)\n\t./$(exe)\n\n";
	string clean="clean:\n\trm -f *.o $(exe)\n";

	fmakefile=comment + cc + cflags + \
			obj + exe + bin + compile + link + clean;
}
void cTemplate::genHeader(string &fheader)
{
	string comment="// This file is generated by genProj program.\n// ";
	comment += timeInfo;
	comment += "\n";
	string include="#include <stdio.h>\n#include <stdlib.h>\n\n";
	fheader = comment + include;
}
void cTemplate::genFunction(string &ffunc,const string funcname)
{
	string ret = "void ";
	string para="(void)\n";
	string body="{\n\tprintf(\"hello, world!\\n\");\n}\n\n";
	ffunc=ret + funcname + para + body;
}
void cTemplate::genMain(string &fmain,const string callfunc)
{
	fmain="int main(int argc, char* argv[])\n{\n\t";
	fmain+=callfunc;
	fmain+="();\n";
	fmain+="\treturn 0;\n}";
}
void cTemplate::Process()
{
	string fmakefile;
	genMakefile(fmakefile,dirname);

	string fheader,ffunc,fmain,ffile;
	genHeader(fheader);
	genFunction(ffunc, dirname);
	genMain(fmain,dirname);
	ffile=fheader+ffunc+fmain;

	append("Makefile",fmakefile);
	append("main.c", ffile);
	createDir();
	flush();
}

void cppTemplate::genMakefile(string &fmakefile,const string projname)
{
	string comment="# This file is generated by genProj program.n\n# ";
	comment += timeInfo;
	comment += "\n";
	string cc="cc=g++\n";
	string cflags="cflags=-Wall -O\n";
	//string libflags;
	//string includeflags;
	string obj="objs=main.o\n";
	string exe="exe=";
	exe+=projname;
	exe+="\n\n";

	string bin="all: bin\nbin: $(exe)\n\n";
	string compile=".cc.o:\n\t$(cc) $(cflags) -c $< -o $@\n\n";
	string link="$(exe):$(objs)\n\t$(cc) $(cflags) -o $@ $(objs)\n\nrun: $(exe)\n\t./$(exe)\n\n";
	string clean="clean:\n\trm -f *.o $(exe)\n";

	fmakefile=comment + cc + cflags + \
			obj + exe + bin + compile + link + clean;
}
void cppTemplate::genHeader(string &fheader)
{
	string comment="// This file is generated by genProj program.\n// ";
	comment += timeInfo;
	comment += "\n";

	string include="#include <iostream>\nusing namespace std;\n\n";
	fheader = comment + include;
}
void cppTemplate::genFunction(string &ffunc,const string funcname)
{
	string ret = "void ";
	string para="(void)\n";
	string body="{\n\tcout<<\"hello, world!\"<<endl;\n}\n\n";
	ffunc=ret + funcname + para + body;
}

void cppTemplate::genClass(std::string &fclass, const std::string classname)
{
	string head="class "+classname+"{\npublic:\n";
	string constructorfunc="\t"+classname+"()\n\t{}\n\n";
	string destructorfunc="\t~"+classname+"()\n\t{}\n\n";
	string ffunc;
	genFunction(ffunc, classname+"func");
	string end = "private:\n\n};\n";
	fclass=head + constructorfunc + destructorfunc + ffunc + end;
}

void cppTemplate::genMain(string &fmain,const string callclass)
{
	fmain="int main(int argc, char* argv[])\n{\n\t";
	fmain+=callclass;
	fmain+=" t;\n\tt.";
	fmain+=callclass+"func();\n";
	fmain+="\treturn 0;\n}";
}
void cppTemplate::Process()
{
	string fmakefile;
	genMakefile(fmakefile, dirname);

	string fheader,fclass,fmain,ffile;

	genHeader(fheader);
	genClass(fclass, dirname);
	genMain(fmain, dirname);
	ffile=fheader+fclass+fmain;

	append("Makefile",fmakefile);
	append("main.cc", ffile);
	createDir();
	flush();
}
