#include<stdio.h>
#include<stdlib.h>
#include<dlfcn.h>
#include"sharedfile.h"

int main(int argc, char*argv[])
{
    void *ptr = NULL;
    int (*fptr)(int , int);
    int (*fptr1)(int , int);
    int ret = 0;

    ptr = dlopen("./library.so",RTLD_LAZY);
    if(ptr == NULL)
    {
        printf("Unable to load liabrary\n");
        return -1;
    }
 	
    fptr = dlsym(ptr,"Addition");
   
    if(fptr == NULL)
    {
        printf("Unable to load the address of function\n");
        return -1;
    }
    
    ret = fptr(atoi(argv[1]),atoi(argv[2]));
    printf("Addition is %d\n",ret);
	
	
    fptr = dlsym(ptr,"Multiplication");
   
    if(fptr == NULL)
    {
        printf("Unable to load the address of function\n");
        return -1;
    }
    
    ret = fptr(atoi(argv[1]),atoi(argv[2]));
    printf("Multiplication is %d\n",ret);
	
	
    fptr = dlsym(ptr,"Division");
   
    if(fptr == NULL)
    {
        printf("Unable to load the address of function\n");
        return -1;
    }
    
    ret = fptr(atoi(argv[1]),atoi(argv[2]));
    printf("Division is %d\n",ret);	
    
    fptr = dlsym(ptr,"Substraction");
   
    if(fptr == NULL)
    {
        printf("Unable to load the address of function\n");
        return -1;
    }
    
    ret = fptr(atoi(argv[1]),atoi(argv[2]));
    printf("Substraction is %d\n",ret);	
    //fptr();
    return 0;
}

// gcc -rdynamic -o Myexe client.c
// gcc -ldl -o Myexe client.c

// ./Myexe
