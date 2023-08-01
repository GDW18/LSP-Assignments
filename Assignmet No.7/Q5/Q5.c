#include "Q5.h"
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<unistd.h>
#include<sys/stat.h>

void Fileinfo(char*filename)
{
        struct stat sobj;
        stat(filename,&sobj);
    
	printf("File name: %s\n",filename);	
	printf("File size is :%d\n",sobj.st_size);
	printf("Number of links: %d\n",sobj.st_nlink);
	printf("Inode number : %d\n",sobj.st_ino);
	printf("File SYtem number : %d\n",sobj.st_dev);
	printf("Number of Blocks:%d\n",sobj.st_blocks);
}

// convert .c to .o
// gcc -c sharedfile.c -o sharedfile.o

// convert .o to .a
// ar rcs sharedfile.a sharedfile.o

