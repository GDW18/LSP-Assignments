#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
	int Ret = 0,Ret1=0,Ret2=0,Ret3=0;
	int status1=0,status2=0,status3=0,status4=0;
	int cpid = 0;
	
	
		
	if((Ret = fork())==0) 
	{
		execl("./Child11","NULL",NULL);
	}
	else
	{	
		if((Ret1 = fork())==0) 
		{
			
		
			execl("./Child12","NULL",NULL);
		}
		else
		{	
			if((Ret2 = fork())==0)
			{
				
			
				execl("./Child13","NULL",NULL);
			}
			else
			{
				if((Ret3 = fork())==0)
				{
					execl("./Child14","NULL",NULL);
				
				}
				else
				{
					printf("Child process 4 Child PID is %d\n",Ret3);
					printf("Child process 4 terminated having PID %d with exit status %d\n",cpid,status1);
						
				}
				printf("Child process 2 Child PID is %d\n",Ret2);
				cpid = wait(&status3);
				printf("Child process 3 terminated having PID %d with exit status %d\n",cpid,status1);
				
			}
			printf("Child process 2 Child PID is %d\n",Ret1);
			cpid = wait(&status2);
			printf("Child process 2 terminated having PID %d with exit status %d\n",cpid,status1);
				
		}
		printf("Child process 1 Child PID is %d\n",Ret);
		cpid = wait(&status1);
		printf("Child process 1 terminated having PID %d with exit status %d\n",cpid,status1);
	}	
		
	return 0;
}
