#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<pthread.h>


void * ThreadProc(void *ptr)
{
	printf("Inside thread 1\n");
}

void * ThreadProc1(void *ptr)
{
	printf("Inside thread 2\n");
}

void * ThreadProc2(void *ptr)
{
	printf("Inside thread 3\n");
}

void * ThreadProc3(void *ptr)
{
	printf("Inside thread 4\n");
}


int main()
{
	pthread_t TID,TID1,TID2,TID3;
	int ret = 0,ret1,ret2,ret3;
	int atr=0;
	
	pthread_attr_t attr;
	atr = pthread_attr_init(&attr);
	if(atr == -1)
	{
		printf("Unable to set thread attributes\n");
		return -1;
	}
	
	ret = pthread_create(&TID,                   
			     &attr,		     
			     ThreadProc,     	    
			     NULL); 		   
	if(ret != 0)
	{
		printf("Unable to create thread 1\n");
		return -1;	
	}
	
	
	ret1 = pthread_create(&TID,
			      &attr,
			      ThreadProc1,
			      NULL);
			     
        if(ret1 != 0)
	{
		printf("Unable to create thread 2\n");
		return -1;	
	}
	
	ret2 = pthread_create(&TID,
			      &attr,
			      ThreadProc2,
			      NULL);
			     
        if(ret2 != 0)
	{
		printf("Unable to create thread 3\n");
		return -1;	
	}
	
	ret3 = pthread_create(&TID,
			      &attr,
			      ThreadProc3,
			      NULL);
			     
        if(ret3 != 0)
	{
		printf("Unable to create thread 4\n");
		return -1;	
	}
	pthread_join(TID,NULL);
	pthread_join(TID1,NULL);
	pthread_join(TID2,NULL);
	pthread_join(TID3,NULL);
	
	
	pthread_attr_destroy(&attr);
	
	printf("End of main Thread\n");	
	pthread_exit(NULL);
	
	return 0;
}
