#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>

#pragma pack(1)


struct Student
{
	int Rollno;
	char Sname[20];
	float Marks;
	int Age;
};

int main(int argc, char *argv[])
{
	struct student sobj;
	char Fname[20];
	int fd = 0;
	
	
	printf("ENter the file name:\n");
	scanf("%s",Fname);
	
	fd = open(Fname,O_RDONLY);
	
	read(fd,&sobj,sizeof(sobj));
	
	printf("Roll number:%d\n",sobj.Rollno);
	printf("Marks are:%f\n",sobj.Marks);
	printf("Age is:%f\n",sobj.Age);
	
	return 0;
}

