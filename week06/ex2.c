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

        if(fork() == 0)
        {
                read(p[0], str2, SIZE);
                printf("From a child: %s\n", str2);
        }
        else {
                write(p[1], str1, SIZE);
                printf("hi from parent\n");
        }
}
