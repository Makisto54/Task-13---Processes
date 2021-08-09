#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define BUF_SIZE 255

int main(void)
{
    pid_t pid = 0;
    char buf[BUF_SIZE] = {0};
    
    printf("Input commands without arguments (exit for exit)\n");
    
    while(strncmp("exit", buf, 4) != 0)
    {        
        bzero(buf, BUF_SIZE); 
        fscanf(stdin, "%s", buf);

        pid = fork();
        if (pid == 0)
        {
            if (execlp(buf, " ", NULL) == -1)
            {
                perror("EXEC ERROR");
                exit(1);
            }
        }
        else
        {
            wait(NULL);
        }      
    }

    return 0;
}