#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<pthread.h>



void * ThreadProc1(void *ptr)
{	
	char Buffer[512];
	int iCnt = 0,iRet = 0,i=0,fd=0;
	
	fd = open("world.txt",O_RDONLY);
	
	
	while((iRet = read(fd,Buffer,sizeof(Buffer))) != 0)
	{
		for(i = 0; i < iRet ; i++)
		{
			if((Buffer[i] >= 'A' ) && (Buffer[i] <='Z'))
			{
				iCnt++;
			}
		}
	}
	printf("NUmber of Capital characters are: %d\n",iCnt);
	close(fd);
	pthread_exit(NULL);
}


void * ThreadProc2(void *ptr)
{	
	char Buffer[512];
	int iCnt = 0,iRet = 0,i=0,fd=0;
	
	fd = open("world.txt",O_RDONLY);
	
	
	while((iRet = read(fd,Buffer,sizeof(Buffer))) != 0)
	{
		for(i = 0; i < iRet ; i++)
		{
			if((Buffer[i] >= 'a' ) && (Buffer[i] <='z'))
			{
				iCnt++;
			}
		}
	}
	printf("Number of Small characters are: %d\n",iCnt);
	close(fd);
	pthread_exit(NULL);
}

int main()
{
	pthread_t TID1,TID2;
	int ret1 =0,ret2 = 0;
	
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
