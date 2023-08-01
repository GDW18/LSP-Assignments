#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<dirent.h>
#include<sys/dir.h>
#include<string.h>
#include<sys/stat.h>
#define BLOCKSIZE 50


int main(int argc, char* argv[])
{
	
	struct dirent *entry = NULL;
	DIR *dp = NULL;
	char name[BLOCKSIZE];
	int fd=0;
	
	if(argc != 2)
	{
	 	printf("Insufficient Arguments");
	 	return -1;
	}
	 
	
	dp = opendir(argv[0]);
	if(dp == NULL)
	{
		printf("Cant open the Directory");
		return -1;
	}
	
	fd = creat(argv[1],0777);
	
	while((entry = readdir(dp)) != NULL)
	{
				
		write(fd,entry->d_name,strlen(entry->d_name));
		memset(name,0,sizeof(name));
	}
	
	return 0;
}	
