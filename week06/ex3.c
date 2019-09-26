#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

// Handler for SIGINT, caused by
// Ctrl-C at keyboard
void handle_sigint(int sig)
{
        printf("\nCaught signal %d\n", sig);
}

int main()
{
        signal(SIGINT, handle_sigint);

        //infinite loop
        while (1);

        return 0;
}
