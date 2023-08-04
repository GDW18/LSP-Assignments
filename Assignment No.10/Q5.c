#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<pthread.h>


void * ThreadProc(void *ptr)
{
	int ret = 0;
	
	pthread_t self;
	
	ret=pthread_self();
	printf("Thread is created with ID From self:%d\n",ret);
	
}


int main(int argc, char*argv[])
{
	pthread_t TID;
	int ret = 0;
	
	
	ret = pthread_create(&TID,                  
			     NULL,		   
			     ThreadProc,     	    
			     NULL); 	   
	
	if(ret != 0)
	{
		printf("Unable to create thread\n");
		return -1;	
	}
	
	printf("Thread is created with ID From main:%d\n",TID);
	
	pthread_join(TID,NULL);
	
	
	printf("End of main Thread\n");	
	return 0;
}
