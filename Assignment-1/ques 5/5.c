#include<unistd.h>
#include<stdio.h>
#include<string.h>
#include<sys/wait.h>

int main()
{
    pid_t ret;
    int stat;
int execute;

    ret=fork();
    if(ret < 0)
    {
        perror("fork");
        exit(1);
    }
    if(ret == 0)
    {
                                   
        execute = execl("/usr/bin/gcc","gcc","-c","test.c",NULL); 
	execl("/bin/gcc","gcc","test.o","-o",s,NULL); 

                            
        if(execute<0)
        {
            perror("execv");
            exit(2);
        }
        exit(0);

    }
    else
    {
        waitpid(-1,&stat,0); 
        printf("parent--child exit stat=%d\n",
			WEXITSTATUS(stat));
		
    }
    return 0;

}
