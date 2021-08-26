#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define BUF_SIZE 255

int main(void)
{
    pid_t pid = 0;
    char buf[BUF_SIZE];
    
    printf("Input commands without arguments (exit for exit)\n");
    
    do
    {      
        bzero(buf, BUF_SIZE); 
        fgets(buf, BUF_SIZE, stdin);
        char *p = strchr(buf, '\n');
        if (p != NULL)
        {
            buf[strlen(buf) - 1] = '\0';
        }

        pid = fork();
        if (pid == 0)
        {
            if (execlp(buf, " ", NULL) == -1)
            {
                perror("EXEC ERROR");
                exit(1);
            }
            exit(0);
        }
        else
        {
            wait(NULL);
        }      
    } while (strncmp("exit", buf, 4) != 0);

    return 0;
}
