#include<fcntl.h>
#include<stdio.h>
#include<string.h>
#include<unistd.h>
int main(int argc,char* argv[])
{
    char* file =argv[1];
    int fd;
    char st[10000];
    struct flock lock;
    fd=open(file,O_WRONLY);
    memset(&lock,0,sizeof(lock));
    lock.l_type=F_WRLCK;
    fcntl(fd,F_SETLKW,&lock);
    printf("locked\n");
    printf("Enter a sentences:\n");
    fgets(st, sizeof(st), stdin);
    write(fd,st,strlen(st));
    getchar();
    printf("Released");
    lock.l_type=F_UNLCK;
    fcntl(fd,F_SETLKW,&lock);
    close(fd);
return 0;    
}


