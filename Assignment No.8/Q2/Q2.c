#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
	int Ret = 0;
	int Ret1= 0;
	int status1=0;
	int cpid = 0;
	
	
		
	if((Ret = fork())==0) 
	{
		printf("Child process 1 parent PID is %d\n",getppid());
		
		execl("./Child1","NULL",NULL);
	}
	else
	{
		printf("Child process 1 PID is%d\n",Ret);
		cpid = wait(&status1);
		
		printf("Child process 1 terminated having PID %d with exit status %d\n",cpid,status1);
		
	}	
		
	return 0;
}
