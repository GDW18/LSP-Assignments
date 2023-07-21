#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<dirent.h>
#include<sys/stat.h>
#define BLOCKSIZE 1024


int main(int argc, char *argv[])
{
	
	int fdSource = 0;
	int fdDest = 0;
	int Ret = 0;
	char Buffer[BLOCKSIZE] ={'\0'};
	
	if(argc != 3 )
	{
		
		printf("Insufficient ARguments\n");
		return -1;
	}
	
	fdSource = open(argv[1],O_RDWR);
	
	if(fdSource == -1)
	{
		printf("File is Successfully opned");
		return -1;
	}
	
	fdDest = creat(argv[2],0777);
	
	while(Ret = read(fdSource,Buffer,sizeof(Buffer)) != 0)
	{
		write(fdDest,Buffer,Ret);
		memset(Buffer,0,sizeof(Buffer));
	
	}
	return 0;
}
	
