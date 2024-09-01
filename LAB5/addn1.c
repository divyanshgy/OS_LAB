#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
void simulate_lsl(){
    char *args[]={"ls","-l",NULL};
    execvp(args[0],args);
    perror("execvp failed");
    exit(1);
}
void simulate_cp(const char *src, const char *dest){
    char *args[]={"cp",src,dest,NULL};
    execvp(args[0],args);
    perror("execvp failed");
    exit(1);
}
void simulate_wc(const char *file) {
    char *args[]={"wc",file,NULL};
    execvp(args[0],args);
    perror("execvp failed"); 
    exit(1);
}
int main(int argc, char *argv[]){
    int status;
    pid_t pid;
    if (argc < 2) {
        printf("Too less arguments!\n");
        exit(1);
    }
    pid=fork();
    if (pid==0){
        if (strcmp(argv[1], "ls") == 0 && argc == 3) {
            simulate_lsl();
        } else if (strcmp(argv[1], "cp") == 0 && argc == 4) {
            simulate_cp(argv[2], argv[3]);
        } else if (strcmp(argv[1], "wc") == 0 && argc == 3) {
            simulate_wc(argv[2]);
        } else {
            printf("Invalid command or arguments\n");
            exit(1);
        }
    }
    else if (pid>0){
        wait(&status);
        printf("Child process terminated.\n");
    }
}