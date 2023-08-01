#include<stdio.h>
#include<stdlib.h>
#include"Q31.h"
#define false 0
#define true 1

int Perfect(int no1)
{
	
	int i = 1,j=0,iSum=0;
	
	if(no1<1)
	{
		printf("Number is not perfect number number");
	}
	
	for(i;i <= no1;i++)
	{
		if(no1 % i == 0)
		{
			iSum = iSum + i;
		}
	}
	if(iSum == no1)
	{
		return true;
	}
	else
	{
		return false;
	}
	return 0;
	
}
