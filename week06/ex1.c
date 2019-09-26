#include <stdio.h>
#include <unistd.h>

#define SIZE 5

int main(int argc, char const *argv[]) {
        char str1[SIZE] = "hello";
        char str2[SIZE];

        //creating a pipe
        int p[2];

        if(pipe(p) < 0)
                exit(1);

        //writing to pipe and reading from pipe
        write(p[1], str1, SIZE);
        read(p[0], str2, SIZE);

        printf("%s", str2);
        return 0;
}
