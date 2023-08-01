#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{

	printf("Child Process 3- PID of Parent process is %d\n",getppid());
	
	return 0;
}
