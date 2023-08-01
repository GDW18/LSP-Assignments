#include<stdio.h>
#include<stdlib.h>
#include"Q3.h"
#define false 0
#define true 1

int Prime(int no1)
{
	int i = 1,j=0;
	if(no1<1)
	{
		printf("Number is not prime number");
	}
	
	for(i;i <= no1;i++)
	{
		if(no1 % i == 0)
		{
			j++;
		}
	}
	if(j>2)
	{
		return false;
		printf("Number is not prime number");
	}
	else
	{
		return true;
	}
	return 0;
}
