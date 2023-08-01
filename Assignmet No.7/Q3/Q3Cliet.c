#include<stdio.h>
#include<stdlib.h>
#include<dlfcn.h>
#include"Q3.h"
#include <stdbool.h>


int main(int argc, char*argv[])
{
    void *ptr = NULL;
    void *ptr1 = NULL;
    int (*fptr)(int);
    int (*fptr1)(int);
    int ret = 0,ret1=0;

    ptr = dlopen("./library2.so",RTLD_LAZY);
    if(ptr == NULL)
    {
        printf("Unable to load liabrary\n");
        return -1;
    }
 	
    fptr = dlsym(ptr,"Prime");
    
    ret = fptr(atoi(argv[1]));
    if(ret == 1)
    {
	 printf("Nubmer is prime number\n");
    } 
    else
    {
	 printf("Nubmer is not prime number\n");
    }
    
    ptr1 = dlopen("./library3.so",RTLD_LAZY);
    if(ptr1 == NULL)
    {
        printf("Unable to load liabrary\n");
        return -1;
    }
 	
    fptr1 = dlsym(ptr1,"Perfect");
    ret1 = fptr1(atoi(argv[2]));
    if(ret1 == 1)
    {
	 printf("Nubmer is perfect number\n");
    } 
    else
    {
	 printf("Nubmer is not perfect number\n");
    }
    
    return 0;
}
    
