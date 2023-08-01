#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int main(int argc, char* argv[])
{
	int Ret = 0;
	int cpid = 0;
	int Exit_status = 0;
	
	
	
	Ret = fork();
	
	if(Ret == 0) //Child
	{
		execl("./ChildProcess",argv[1],argv[2],NULL);
	}
	else	
	{
		printf("Parent is running with PID :%d\n",getpid());
		cpid = wait(&Exit_status);
		printf("Child process terminated having PID %d with exit status %d\n",cpid,Exit_status);
	}	
	return 0;
}
