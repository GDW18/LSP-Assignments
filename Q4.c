#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<dirent.h>
#include<sys/stat.h>


int main(int argc, char *argv[])
{
	
	struct dirent *entry = NULL;
	DIR *dp = NULL;
	char DirName[20];
	struct stat sobj;
	char name[30];
	
	printf("ENter name od Directory:\n");
	scanf("%s",DirName);
	
	dp = opendir(DirName);
	
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
		sprintf(name,"%s/%s",DirName,entry->d_name);
		stat(name,&sobj);
		if(S_ISREG(sobj.st_mode))
		{
			if(sobj.st_size > 100)
			{
				remove(name);
			}
		}
	}	
	return 0;
}
