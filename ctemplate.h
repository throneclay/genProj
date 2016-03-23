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
