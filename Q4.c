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
			printf("File name :%s It is Regular File\n",name);
		}
		else if(S_ISDIR(sobj.st_mode))
		{
			printf("File name :%s It is Directory File\n",name);
		}
		else if(S_ISLNK(sobj.st_mode))
		{
			printf("File name :%s It is Symbolic Link\n",name);
		}
	}	
	return 0;
}
