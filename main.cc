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
    	if(t.mode&0x07)
    		generator = new cTemplate(t.name, t.comment);
    	else
    		generator = new cTemplate(t.name);
    }
    else
    {
    	if(t.mode&0x07)
			generator = new cppTemplate(t.name, t.comment);
		else
			generator = new cppTemplate(t.name);
    }
   (*generator)();

    delete generator;
    return 0;
}

int getOps(Typeinfo &t, int argc, char* argv[])
{
    char opt=0;
    t.mode=0;
    while((opt = getopt(argc, argv,"l:d:m:h")) != -1){
        switch(opt){
            case 'l':
            	t.mode|=1;
                strcpy(t.type, optarg);
                //printf("mode=%d\tI get the type %s\n",t.mode,t.type);
                break;
            case 'd':
            	t.mode|=1<<1;
                strcpy(t.name, optarg);
                //printf("mode=%d\tI got the name %s\n",t.mode,t.name);
                break;
            case 'm':
            	t.mode|=1<<2;
            	strcpy(t.comment, optarg);
                //printf("mode = %d\tI got the comment %s\n",t.mode,t.name);
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
