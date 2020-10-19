
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
	int child_2;
	int child_3;
	int child4;
	int child_5,child_6;
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
	execlp("gcc","gcc","-c","test.c","sum.c","sqr.c",NULL);
    	}
    	else
    	{
    	waitpid(child_1, &returni, 0);
    	//child_2=fork();
    	}
	child_2=fork();
	if(child_2==0)
    	execlp("ar","ar","rc","libfunctions.a","sum.o","sqr.o",NULL);
    	else
    	{waitpid(child_2, &returni, 0);
    	}
	 
	child_3=fork();
	if(child_3==0)
	execlp("gcc","gcc","-L.","test.o","-o","all.out","-lfunctions",NULL);
	else
    	{
	waitpid(child_3, &returni, 0);
	  }
	child4=fork();
	if(child4==0)
	
	execlp("gcc","-L.","test.o","-o","libout.out","-lmyfunctions",NULL);
	else
    	{
	waitpid(child4, &returni, 0);
	  }
	child_5=fork();
	if(child_5==0)
	execl("libout.out","libout.out",NULL);
		 
	exit(0);
}

   

