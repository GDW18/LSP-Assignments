#include<stdio.h>
#include<sys/stat.h>	
#include<fcntl.h>


int main(int argc, char *argv[])
{
	
	struct stat sobj;
	
	int fd = 0;
	
	if(argc != 2 )
	{
		
		printf("Insufficient ARguments\n");
		return -1;
	}
	
	fd = open(argv[1],O_RDONLY);
	
	if(fd== -1)
	{
		printf("Unable to open File");
	}
	
	fstat(fd,&sobj);
	
	printf("File name: %s\n",argv[1]);	
	printf("File size is :%d\n",sobj.st_size);
	printf("Inode number : %d\n",sobj.st_ino);
	printf("Number of links: %d\n",sobj.st_nlink);
	printf("Number of Blocks:%d\n",sobj.st_blocks);
	printf("File Sytem number : %d\n",sobj.st_dev);	
	
	
	return 0;

}
