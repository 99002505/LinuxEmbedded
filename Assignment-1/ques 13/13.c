
#include<unistd.h>
#include <string.h>
#include<stdio.h>
#include<stdlib.h>
#include <sys/wait.h>
#include <string.h>



int main()
{
	int ret,returni;
	int child_1=fork();
	int child_2,child_3,child_4,child_5;
	char *s;
	char *ss;
	ss="./s.out";
	s="s.out"; 
	if(child_1<0||child_2<0||child_3<0)
	{
	perror("fork");
	exit(1);
	}
	if(child_1==0)
	{ 
	execlp("gcc","gcc","-c","sqr.c",NULL);
	printf("Compilation of sqr.c is completed\n");
    	}
    	else
    	{
    	waitpid(child_1, &returni, 0);
    	//child_2=fork();
    	}

	child_2=fork();
	if(child_2==0)
	{
    	execlp("gcc","gcc","-c","sum.c",NULL);
	printf("Compilation of sum.c is completed\n");
	}
    	else
    	{
	waitpid(child_2, &returni, 0);
    	}
	child_3=fork();
	if(child_3==0)
	{
    	execlp("gcc","gcc","-c","test.c",NULL);
	printf("Compilation of test.c is completed\n");
	}
    	else
    	{
	waitpid(child_3, &returni, 0);
    	}
	child_4=fork();
	if(child_4==0)
	{
  	execlp("gcc","gcc","sum.o","sqr.o","test.o","-o","s.out",NULL);
	printf("Linking is completed\n");
	printf("Execution:\n");
	}
    	else
    	{
	waitpid(child_4, &returni, 0);
	  } 
	execl("./s.out", "./s.out", NULL); 	 
	exit(0);
}

