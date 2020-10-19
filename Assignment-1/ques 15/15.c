#include<unistd.h>
#include<fcntl.h>

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    int f1,buffsize;
	f1 =open("file1.txt",O_RDONLY);
	if(f1<0)
	{
		perror("open");
		exit(1);
	}
	int maxlen=300;
	char buf[maxlen];
    int f2,file_size;
	f2=open("file2.txt",O_WRONLY|O_CREAT, 0666);
	if(f2<0)
	{
		perror("open");
		exit(3);
	}
    while(buffsize=read(f1,buf,maxlen))
    {
	    file_size =	write(f2, buf, maxlen);
        if(file_size<0)
	    {
		    perror("write");
		    exit(4);
	    }
    }

    
    close(f1);
    close(f2);
    printf("Copy Successful \n");
}
