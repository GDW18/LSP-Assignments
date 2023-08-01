#include<stdio.h>
#include"sharedfile.h"

int Addition(int no1, int no2)
{
	int iAns = 0;
	iAns = no1 + no2;
    	return iAns;
}

int Multiplication(int no1, int no2)
{
	int iAns = 0;
	iAns = no1 * no2;
    	return iAns;
}

int Division(int no1, int no2)
{
	int iAns = 0;
	iAns = no1 / no2;
    	return iAns;
}

int Substraction(int no1, int no2)
{
	int iAns = 0;
	iAns = no1 - no2;
    	return iAns;
}

// To create .o file
// gcc -c -fPIC sharedfile.c

// To create .so file
// gcc -shared -o library.so sharedfile.o
