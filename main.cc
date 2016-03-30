#include <iostream>
#include <cstring>
#include <cstdio>

#include "templateProj.h"
#include "ctemplate.h"


void Usage(char* str)
{
    printf("genproj is used to generate a code template!\n");
    printf("Usages:\n\t%s -t language -p projectName [-m comment]\n",str);
}

void getOps(Typeinfo &t, int argc, char* argv[]);

int main(int argc, char *argv[])
{
    Typeinfo t;
    if(argc<3){
        Usage(argv[0]);
        return -1;
    }
    else{
    	getOps(t, argc, argv);
        if((t.mode&0x03)!=0x03){
            Usage(argv[0]);
    		return -1;
        }
    }
    ITemplate *generator; 
    if(0==strcmp(t.type,"c"))
    {
    	if(t.mode&1<<2)
    		generator = new cTemplate(t.name, t.comment);
    	else
    		generator = new cTemplate(t.name);
    }
    else
    {
    	if(t.mode&1<<2)
			generator = new cppTemplate(t.name, t.comment);
		else
			generator = new cppTemplate(t.name);
    }
   (*generator)();

    delete generator;
    return 0;
}

void getOps(Typeinfo &t, int argc, char* argv[])
{
    char opt=0;
    t.mode=0;
    while((opt = getopt(argc, argv,"t:p:m:h")) != -1){
        switch(opt){
            case 't':
            	t.mode|=1;
                strcpy(t.type, optarg);
                //printf("mode=%d\tI get the type %s\n",t.mode,t.type);
                break;
            case 'p':
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
                break;
        }
    }

}
