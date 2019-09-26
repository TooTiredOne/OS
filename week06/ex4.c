#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void handler(int sig_n)
{
        if(sig_n == SIGSTOP)
                printf("SIGINT is recieved\n");
        else if(sig_n == SIGKILL)
                printf("SIGKILL is recieved\n");
        else if(sig_n == SIGUSR1)
                printf("SIGUSR1 is recieved\n");
}

int main()
{
        signal(SIGSTOP, handler);
        signal(SIGKILL, handler);
        signal(SIGUSR1, handler);
        while (1);
        return 0;
}

/*
   the command kill -SIGUSR1 <pid> gives the following output:

   SIGUSR1 is recieved

   because we pass the signal SIGUSR1 using kill
 */
