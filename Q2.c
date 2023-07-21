#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char*argv[])
{
	int fd= 0;
	char Buffer[]="Hello World";
	int Count = 0;
	

	if(argc != 2)
	{
	  printf("Invalid Number of arguments\n");
	  return -1;
	}
	
	Count = strlen(Buffer);
	printf("%d\n",Count);
	
	fd = open(argv[1],O_RDWR);
	if(fd== -1)
	{
		printf("Unable to open File");
		return -1;
	}
	
	write(fd,Buffer,Count);
	close(fd);
	
	return 0;
}
