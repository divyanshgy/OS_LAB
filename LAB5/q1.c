#include<sys/types.h>
#include<unistd.h>
#include<stdio.h>
#include<sys/wait.h>
int main(){
    int pid,status;
    pid=fork();
    if (pid>0){
        //wait(&status);
        printf("parent process\n");
        printf("PID: %d\n", getpid()); 
        printf("PPID: %d\n", getppid());
    }
    else if (pid==0){
        printf("child process\n");
        printf("PID: %d\n", getpid()); 
        printf("PPID: %d\n", getppid());
    }
}