#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>

int main(int argc, char* argv[])
{
	int Dp = 0;
	
	if(argc != 2)
	{
		printf("Insufficient arguments\n");
		return -1;
	}
	
	Dp = mkdir(argv[1],0777);
	if(Dp == -1)
	{
		printf("Directory is not Created\n");
		return -1;
	}
	else
	{
		printf("Directory is Successfully Created\n");	
	}
	
	return 0;
}
	
