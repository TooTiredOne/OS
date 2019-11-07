#include<stdio.h>
#include<sys/stat.h>
#include<sys/mman.h>
#include <stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

int main()
{
    int input, output;
    char buff[20];

    //opening the files
    input = open("/dev/random", O_RDONLY); 
    output = open("./ex1.txt", O_RDWR);
 
    read(input, buff, 20); //reading 20 random symbols
    write(output, buff, 20); //writing those symbols to output file

    close(input);
    close(output);

    return 0;
}