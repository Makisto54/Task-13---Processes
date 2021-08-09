#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
    pid_t pid = 0;

    pid = fork();
    if (pid == 0)
    {
        printf("Process %d, parent pid - %d\n", getpid(), getppid());
    }
    else
    {
        printf("Process %d\n", getpid());
        wait(NULL);
    }

    return 0;
}