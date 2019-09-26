#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char const *argv[]) {

        //creating a pipe to pass pid of the 2nd child to the 1st child
        int p[2];

        if(pipe(p) < 0)
                exit(1);

        pid_t pid1;

        //creating the 1st child
        pid1 = fork();

        if(pid1 == 0) //in the 1st child
        {
            pid_t pid; //this will store a pid of the 2nd child
            printf("the 1st child is reading pid of the 2nd child..\n");
            read(p[0], &pid, sizeof(pid));

            //counting 5 seconds
            for(int i = 5; i >= 1; i--)
            {
              printf("the 2nd child will be terminated in %d\n", i);
              sleep(1);
            }

            //stopping the 2nd child process
            kill(pid, SIGSTOP);

            printf("The 2nd child was stopped!");
            exit(0);
        }
        else
        {
                pid_t pid2;

                //creating the 2nd child
                pid2 = fork(); //stores pid of the 2nd child

                if(pid2 == 0) //in the 2nd child
                {
                  while(1) //infinite loop
                  {
                    printf("hello from the 2nd child!\n");
                    sleep(1);
                  }
                }
                else
                {
                        //writing the pid2 to pipe
                        write(p[1], &pid2, sizeof(pid2));
                        
                        int stat;
                        //waiting for the 2nd child
                        pid_t cpid = waitpid(pid2, &stat, 0);
                        if (WIFEXITED(stat))
                                printf("Child %d terminated with status: %d\n",
                                       cpid, WEXITSTATUS(stat));
                }
        }
        return 0;
}

/*
The program doesnt terminate, so the statement is False
But if we send SIGKILL instead of SIGSTOP everything works fine
*/
