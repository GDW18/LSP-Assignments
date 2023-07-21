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
	
		
	fd = open(argv[1],O_RDWR);
	if(fd != -1)
	{
		printf("File is Exixsting %d\n",fd);
	}
	
	truncate(argv[1],atoi(argv[2]));
	close(fd);
	return 0;
}
