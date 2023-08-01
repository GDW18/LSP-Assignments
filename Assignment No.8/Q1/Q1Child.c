#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{	
	int ret = 0;
	int status1=0;
	int cpid = 0;
	
	if((ret=fork())==0)
	{
		printf("Child process 2 created by parent\n");
		printf("Inside Child 2 Process - PID of Parent process is %d\n",getppid());
		execl("./Child2","NULL",NULL);
	}
	else
	{
		printf("Inside Child 2 Process - PID of Child Process is %d\n",ret);
		cpid = wait(&status1);
		
		printf("Child process 2 terminated having PID %d with exit status %d\n",cpid,status1);
		
		
	}
	
	return 0;
}
