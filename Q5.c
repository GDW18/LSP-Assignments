#include<stdio.h>
#include<sys/stat.h>	
#include<fcntl.h>
#include <string.h>

int main(int argc, char *argv[])
{
		
	int fd = 0;
	char *Buffer= NULL;
	int Ret = 0;
	int iSize= 0;
	
	if(argc != 3)
	{
	  printf("Invalid Number of arguments\n");
	  return -1;
	}
	
	fd = open(argv[1], O_RDONLY);
	if(fd== -1)
	{
		printf("Unable to open File");
	}
	
	iSize = atoi(argv[2]);
	
	Buffer = (char *)malloc(iSize);
	
	
	Ret = read(fd,Buffer,iSize);
	if(Ret == 0)
	{
		printf("Unable to read data from file\n");
	}
	
	printf("Data from file is:\n");
	write(1,Buffer,Ret);
	printf("\n");		
	close(fd);
	
	return 0;
	
	
}

