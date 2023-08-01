#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
	int ret = 0;
	
	if((ret=fork())==0)
	{
		printf("Child process 3 created by parent\n");
		printf("Inside Child 3 Process - PID of Parent process is %d\n",getppid());
	}
	else
	{
		printf("Inside Child 3 Process - PID of Child Process is %d\n",ret);
		
	}
	
	return 0;
}
