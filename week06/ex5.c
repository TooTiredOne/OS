#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

int main()
{
        pid_t pid = fork();

        if(pid == 0)
        {
                while(1)
                {
                        printf("I'm alive \n");
                        sleep(1);
                }
        }
        else
        {
                sleep(10);
                kill(pid, SIGTERM);
        }

        return 0;
}

/*
output
I'm alive
I'm alive
I'm alive
I'm alive
I'm alive
I'm alive
I'm alive
I'm alive
I'm alive
I'm alive 
*/
