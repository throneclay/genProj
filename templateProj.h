#ifndef __TEMPLATEPROJ_H__
#define __TEMPLATEPROJ_H__
#include <sys/stat.h> //mkdir
#include <unistd.h> //access
#include <vector>
#include <string>
#include <cstdio>
#include <fstream>

typedef struct info{
	unsigned char mode;
    char type[10];
    char name[100];
    char comment[200];
} Typeinfo;

class Filepair{
public:
	Filepair(const char* p)
	: path(p)
	{
	}
	~Filepair()
	{}

private:
	std::string path;

};

class ITemplate{
public:
    ITemplate(char* t)
    : dirname(t)
    {
    	append("README","SOME COMMENT");
    }
    ITemplate(char *t, char *comment)
    : dirname(t)
	{
    	append("README",comment);
	}
    const char* getdirname()
    {
    	return dirname;
    }
    virtual ~ITemplate()
    {}
    void createDir()
    {
//    	if(access(dirname, 0)!=0){
//    		printf("file exist!\n");
//    		exit(-2);
//    	}
//    	else{
    		if(mkdir(dirname, 0755))
    		{
    			printf("create file failed!\n");
    			exit(-2);
    		}
 //   	}
    }
    void append(const std::string name, const std::string content)
	{
		filename.push_back(name);
		filecontent.push_back(content);
	}
	int size()
	{
		return filename.size();
	}
	void flush()
	{
		int filesize = filename.size();
		printf("filesize = %d\n",filesize);
		for(int i=0;i<filesize;i++)
		{
			std::string currentfile = dirname;
			currentfile+= "/";
			currentfile+=filename[i];

			std::ofstream fileout;
			fileout.open(currentfile,std::ios::out|std::ios::trunc);
			if(fileout.is_open())
			{
				fileout<<filecontent[i];
				fileout.close();
			}
		}
	}
    void operator()()
    {
        Process();
    }



private:
    const char* dirname;
	std::vector<std::string> filename;
	std::vector<std::string> filecontent;
    virtual void Process() = 0;
};

#endif
