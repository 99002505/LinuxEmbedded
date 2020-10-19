
/* mini shell that can take 6 arguments*/
#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<sys/wait.h>

int main()
{
    pid_t ret_status;
    int status;
    int cmd_exe;
    char Comm[10];
    printf("Enter your command:");
    scanf("%s", Comm);                  
    ret_stat=fork();
    
    if(ret_status<0)
    {
        perror("fork");
        exit(1);
    }
    if(ret_status==0)
    {
        cmd_exe=execlp(Comm,Comm);
        if(cmd_exe<0)
        {
            perror("execlp");
            exit(2);
        }
        exit(0);
    }
    else
    {
        waitpid(-1,&status,0); //wait(&status);
        printf("parent--child exit status=%d\n",
			WEXITSTATUS(status));
    }
}
