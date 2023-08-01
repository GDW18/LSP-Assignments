#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{

	printf("Child process 3 created by parent\n");
	printf("Inside Child 3 Process - PID of Parent process is %d\n",getppid());
	
	
	return 0;
}
