#include <iostream>
#include <cstring>
#include <cstdio>
#include "templateProj.h"
#include "ctemplate.h"

void Usage(char* str)
{
   printf("Usages:\n\t%s -l language -d dir [-m comment]\n",str);
}

int getOps(Typeinfo &t, int argc, char* argv[]);

int main(int argc, char *argv[])
{
    Typeinfo t;
    if(argc<3)
    {
        Usage(argv[0]);
        return -1;
    }
    else{
    	if(getOps(t, argc, argv)!=0)
    		return -1;
    }
    ITemplate *generator; 
    if(0==strcmp(t.type,"c"))
    {
    	if(t.mode&=0x03)
    		generator = new cTemplate(t.name);
    	else
    		generator = new cTemplate(t.name, t.comment);
    }
    else
    {
    	if(t.mode&=0x03)
			generator = new cppTemplate(t.name);
		else
			generator = new cppTemplate(t.name, t.comment);
    }
   (*generator)();

    delete generator;
    return 0;
}

int getOps(Typeinfo &t, int argc, char* argv[])
{
    char opt=0;
    while((opt = getopt(argc, argv,"l:d:m:h")) != -1){
        switch(opt){
            case 'l':
            	t.mode|=1;
                strcpy(t.type, optarg);
#ifdef DEBUG
                printf("I get the type %s\n",t.type);
#endif
                break;
            case 'd':
            	t.mode|=1<1;
                strcpy(t.name, optarg);
#ifdef DEBUG
                printf("I got the name %s\n",t.name);
#endif
                break;
            case 'm':
            	t.mode|=1<2;
            	strcpy(t.comment, optarg);
#ifdef DEBUG
                printf("I got the comment %s\n",t.name);
#endif
            	break;
            case 'h':
            case '?':
                Usage(argv[0]);
                return -1;
                break;
        }
    }
    return 0;

}
