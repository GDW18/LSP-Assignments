#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{	
		
	printf("Child process 2 created by parent\n");
	printf("Inside Child 2 Process - PID of Parent process is %d\n",getppid());
	
		
	return 0;
}
