#include<stdio.h>
#include<sys/stat.h>
#include<sys/mman.h>
#include <stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

int main(int argc, char const *argv[])
{
    FILE *output;
    char buf[20000], c;
    int count = 0;

    if(argc == 3)
        output = fopen(argv[2], "a"); //input is in the from ./ex2 -a file_name
    else
        output = fopen(argv[1], "w"); //input is in the form ./ex2 file_name


    while (read(STDIN_FILENO, &c, 1) > 0) //reading the input
    {
        buf[count] = c;
        count ++;
    }

    buf[count] = '\0'; //end of the string



    fwrite(buf, 1, count, output);
    fclose(output);


    return 0;
}
