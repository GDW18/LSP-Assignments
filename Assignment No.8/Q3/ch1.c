#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
	
	//printf("Child 1 Process - PID of Child process is %d\n",getpid());
	printf("Child Process 1 - PID of Parent process is %d\n",getppid());
	
	return 0;
}
