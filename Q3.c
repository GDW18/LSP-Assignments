#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<dirent.h>

int main(int argc, char *argv[])
{
	
	struct dirent *entry = NULL;
	DIR *dp = NULL;
	struct stat sobj;
	char name[30];
	int fd = 0;
	
	if(argc != 3)
	{
	  printf("Invalid Number of arguments\n");
	  return -1;
	}
	
	dp = opendir(argv[1]);
	
	if(dp == NULL)
	{
		printf("Unable to open Directory\n");
		return -1;
	}	
	else
	{
		printf("Directory is Successfully Opened\n");
	}
	
	sprintf(name,"%s/%s",argv[1],argv[2]);
	
	fd = creat(name,0777);
	
	if(fd == -1)
	{
		printf("File is not successfully Created");
	}
	
		
	return 0;
}
