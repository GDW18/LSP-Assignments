#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<dirent.h>
#include<sys/dir.h>
#include<sys/stat.h>

int main(int argc, char* argv[])
{

	struct dirent *entry = NULL;
	DIR *dp = NULL;
	
	char oldname[50];
	char newname[50];
	
	
	dp = opendir(argv[1]);
	if(dp == NULL)
	{
		printf("Cant open the Directory");
	}
	
	while((entry = readdir(dp)) != NULL)
	{
		sprintf(oldname,"%s/%s",argv[1],entry->d_name);
		sprintf(newname,"%s/%s",argv[2],entry->d_name);
	
		rename(oldname,newname);
	}
	
	closedir(dp);
	return 0;
}
