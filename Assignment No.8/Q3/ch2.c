#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
	//printf("Child 2 Process - PID of Child process is %d\n",getpid());
	printf("Child Process 2 - PID of Parent process is %d\n",getppid());
	
	return 0;
}
