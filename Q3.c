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
	
	if(argc != 2)
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
	
	while((entry = readdir(dp)) != NULL)
	{
		printf("%s : %d\n",entry->d_name);
	}	
	return 0;
}
