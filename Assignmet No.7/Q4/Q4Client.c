#include<stdio.h>
#include<stdlib.h>
#include<dlfcn.h>
#include"Q4.h"
#include <stdbool.h>


int main(int argc, char*argv[])
{
    void *ptr = NULL;
    int (*fptr)();
    int ret = 0;

    ptr = dlopen("./library.so",RTLD_LAZY);
    if(ptr == NULL)
    {
        printf("Unable to load liabrary\n");
        return -1;
    }
 	
    fptr = dlsym(ptr,"Load");
    if(fptr == NULL)
    {
        printf("Unable to load the address of function\n");
        return -1;
    }
    else
    {
    	printf("able to load the address of function\n");
    }
    
    return 0;
}
