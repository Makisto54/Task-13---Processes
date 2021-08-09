#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
    pid_t pid = 0;

    for (int i = 0; i < 2; i++)
    {
        pid = fork();
        if (pid == 0)
        { 
            pid = fork();
            if (pid == 0)
            {
                printf("Process %d, parent pid - %d\n", getpid(), getppid());
                exit(0);      
            }
            else
            {
                printf("Process %d, parent pid - %d\n", getpid(), getppid());
                wait(NULL);
                if (i == 0)
                {
                    exit(0);
                }
            }

            if (i == 1)
            {   
                pid = fork();
                if (pid == 0)
                {
                    printf("Process %d, parent pid - %d\n", getpid(), getppid());  
                    exit(0);  
                }
                else
                {
                    wait(NULL);
                    exit(0);
                }  
            }
        }
        else
        {   
            printf("Process %d\n", getpid());      
            wait(NULL);
        } 
    }                

    return 0;
}