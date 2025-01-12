#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define SIZE 5

int main(int argc, char const *argv[]) {
        char str1[SIZE] = "hello";
        char str2[SIZE];

        //creating a pipe
        int p[2];

        if(pipe(p) < 0)
                exit(1);


        if(fork() == 0) //in child
        {
                read(p[0], str2, SIZE); //reading from pipe
                printf("From a child: %s\n", str2);
        }
        else { //in parent
                write(p[1], str1, SIZE); //writing to pipe
                printf("hi from parent\n");
        }
}
