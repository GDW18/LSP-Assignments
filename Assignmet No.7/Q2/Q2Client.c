#include<stdio.h>
#include<stdlib.h>
#include<dlfcn.h>
#include"Q2.h"
#include <stdbool.h>


int main(int argc, char*argv[])
{
    void *ptr = NULL;
    int (*fptr)(char* , char*);
    int ret = 0;

    ptr = dlopen("./library1.so",RTLD_LAZY);
    if(ptr == NULL)
    {
        printf("Unable to load liabrary\n");
        return -1;
    }
 	
    fptr = dlsym(ptr,"Compare");
   
    if(fptr == NULL)
    {
        printf("Unable to load the address of function\n");
        return -1;
    }
    
    ret = fptr(argv[1],argv[2]);
    if(ret == 1)
    {
	 printf("Files contain same data\n");
    } 
    else
    {
	 printf("Files doesn't contain same data\n");
    }
    return 0;
}
   
