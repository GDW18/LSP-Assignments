#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>


int main(int argc, char* argv[])
{
	int fd = 0 ;
	int ret = 0;
	char Arr[20];	
		
	fd = open(argv[1],O_RDWR);
	if(fd != -1)
	{
		printf("File is Exixsting %d\n",fd);
	}
	
	lseek(fd,atoi(argv[2]),0);
	
	ret = read(fd,Arr,20);
	
	printf("Data from file is\n");
	write(1,Arr,ret);
	printf("\n");
	close(fd);
	return 0;
}
