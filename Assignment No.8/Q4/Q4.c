#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
	int Ret = 0;
	int Ret1= 0;
	int status1=0,status2=0;
	int cpid = 0,cpid1=0;
	
	
		
	if((Ret = fork())==0) 
	{

		execl("./Child1","NULL",NULL);
	}
	else
	{	
		if((Ret1=fork())==0)
		{
			execl("./Child2","NULL",NULL);
		}
		else
		{
			cpid1 = wait(&status2);
		
		}
		
		cpid = wait(&status1);
		
		printf("Child process 1 terminated having PID %d with exit status %d\n",cpid,status1);
		
	}	
		
	return 0;
}
