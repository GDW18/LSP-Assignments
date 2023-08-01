#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/resource.h>

int main()
{
	int ret = 0;
	
	ret =nice(-5);
	
	printf("Cuurent Priority of process is %d\n",ret);
	
	return 0;
}
