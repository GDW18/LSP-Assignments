#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>


int main(int argc, char *argv[])
{
	int mode = 0;
	int fd = 0 ;
	
	if(argc != 3)
	{
		printf("Insufficient Arguments\n");
		return -1;
	}
	
	if(strcmp(argv[2],"read")==0)
	{
		mode =R_OK;
	}
	else if(strcmp(argv[2],"write")==0)
	{
		mode =W_OK;
	}
	esle if(strcmp(argv[2],"execute")==0)
	{
		mode =R_OK;
	}
	
	if(access(argv[1],mode) <0)
	{
		printf("unable to access %s file in %s mode \n",argv[1],argv[2]);
	}
	else
	{
		printf("you can access %s file in %s mode \n",argv[1],argv[2]);
	}

	return 0;
}
