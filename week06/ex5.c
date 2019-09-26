#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

int main()
{
        pid_t pid = fork(); //stores child's pid

        if(pid == 0) //in child
        {
                while(1)
                {
                        printf("I'm alive \n");
                        sleep(1);
                }
        }
        else //in parent
        {
                sleep(10);

                //passing a signal to child
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
