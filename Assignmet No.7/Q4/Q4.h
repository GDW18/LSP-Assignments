int Load();
/*{
    void *ptr = NULL;
    int (*fptr)(int);
    
    ptr = dlopen("./library1.so",RTLD_LAZY);
    if(ptr == NULL)
    {
        printf("Unable to load liabrary\n");
        return -1;
    }
 
    printf("In inner library");	
    fptr = dlsym(ptr,"Factor");
    
}*/

