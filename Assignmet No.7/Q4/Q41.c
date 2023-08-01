#include<stdio.h>
#include<stdlib.h>
#include<dlfcn.h>
#include"Q41.h"
#include <stdbool.h>

void Factor(int no1)
{
	
	int i = 1;
	
	if(no1<1)
	{
		printf("Cant find factor of this number");
	}
	
	for(i;i <= no1;i++)
	{
		if(no1 % i == 0)
		{
		 	printf("%d\n",i);
		}
	}	
}
