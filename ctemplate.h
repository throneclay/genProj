#ifndef __CTEMPLATE_H__
#define __CTEMPLATE_H__
#include <string>
#include "templateProj.h"

class cTemplate : public ITemplate
{
public:
    cTemplate(char* t)
    :ITemplate(t)
    {}
    cTemplate(char* t, char* c)
	:ITemplate(t,c)
	{}
    ~cTemplate() {}
private:
    void genMakefile(std::string &fmakefile,const std::string projname);
    void genHeader(std::string &fheader);
    void genFunction(std::string &ffunc,const std::string funcname);
    void genMain(std::string &fmain,const std::string callfunc);
    void Process();
};

class cppTemplate : public ITemplate
{
public:
    cppTemplate(char* t)
    : ITemplate(t)
    {}
    cppTemplate(char* t,char*c)
	: ITemplate(t,c)
	{}
    ~cppTemplate() {}
private:
    void Process();
};

#endif
