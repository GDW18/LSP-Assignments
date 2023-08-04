#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<pthread.h>

pthread_mutex_t mut;

void * ThreadProc1(void *ptr)
{	
	pthread_mutex_lock(&mut);
	int i = 0;
	for(i = 1; i <=10;i++)
	{
		printf("Thread 1:%d\n",i);
	}
	pthread_mutex_unlock(&mut);
	pthread_exit(NULL);
}


void * ThreadProc2(void *ptr)
{	
	pthread_mutex_lock(&mut);
	int i = 0;
	for(i = 10; i >= 1;i--)
	{
		printf("Thread 2:%d\n",i);
	}
	pthread_mutex_unlock(&mut);
	pthread_exit(NULL);
}

int main()
{
	pthread_t TID1,TID2;
	int ret1 =0,ret2 = 0;
	int mut1 =0 ;
	
	
	
	mut1 = pthread_mutex_init(&mut,NULL);
	if(mut1 !=0)
	{
		printf("Unable to set mutex\n");
		return -1;
	
	}
	
	ret1 = pthread_create(&TID1,                  
			     NULL,		     
			     ThreadProc1,     	    
			     NULL); 		   
	
	if(ret1 != 0)
	{
		printf("Unable to create thread\n");
		return -1;	
	}
	
	printf("Thread1 is created with ID:%d\n",TID1);
	
	ret2 = pthread_create(&TID2,                   
			     NULL,		 
			     ThreadProc2,     	    
			     NULL); 		    
	
	if(ret2 != 0)
	{
		printf("Unable to create thread\n");
		return -1;	
	}
	
	printf("Thread2 is created with ID:%d\n",TID1);
	
	
	pthread_join(TID1,NULL);
	pthread_join(TID2,NULL);
	
	printf("End of main Thread\n");	
	pthread_exit(NULL);
	return 0;
}
