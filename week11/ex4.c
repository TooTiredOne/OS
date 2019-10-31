#include<stdio.h>
#include<sys/stat.h>
#include<sys/mman.h>
#include <stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

int main()
{
    int input, output; //input file
    struct stat buff; //buff to store file's stats
    char * mapped_in; 
    char * mapped_out;

    input = open("ex1.txt", O_RDWR); //opening the input file
    output = open("ex1.memcpy.txt", O_RDWR); //opening the ouput file

    fstat(input, &buff); //getting stats of file and putting them in buff

    ftruncate(output, buff.st_size); //chaning the file size to needed

    //mappig
    mapped_in = (char*)mmap(0, buff.st_size, PROT_READ|PROT_WRITE, MAP_SHARED, input, 0);
    mapped_out = (char*)mmap(0, buff.st_size, PROT_READ|PROT_WRITE, MAP_SHARED, output, 0);
    
    memcpy(mapped_out, mapped_in, buff.st_size); //copying the text

    close(input);
    close(output);
    munmap(mapped_in, buff.st_size);
    munmap(mapped_out, buff.st_size);
    
    return 0;
}