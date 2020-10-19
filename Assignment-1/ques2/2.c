#include<unistd.h>
#include<fcntl.h>

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	int fd,nbytes;
	fd=open("file1.txt",O_RDONLY);
	if(fd<0)
	{
		perror("open");
		exit(1);
	}
	int length=135;
	char buf[length];
	nbytes=read(fd,buf,length);
	if(nbytes<0)
	{
		perror("read");
		exit(2);
	}
    buf[length]='\0';
    printf("%s\n",buf);
    close(fd);
}
