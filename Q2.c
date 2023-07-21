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
	char Dirname[30];
	char filename[30];
	
	
	printf("Enter the name of Directory you want to open\n");
	scanf("%s",Dirname);
	
	printf("Enter the file name you want to find in Directory\n");
	scanf("%s",filename);
	
	dp = opendir(Dirname);
	if(dp == NULL)
	{
		printf("Cant open the Directory");
	}
	
	while((entry = readdir(dp)) != NULL)
	{
		if(strcmp(filename,entry->d_name) == 0)
		{
			printf("File is present in Directory\n");
			break;
		}
	}
	if(entry == NULL)
	{
		printf("File is no present in Directory\n");
		return -1;
	}
	
	
	return 0;
}
