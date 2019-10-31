#include<stdio.h>
#include<sys/stat.h>
#include<sys/mman.h>
#include <stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

int main()
{
    int input; //input file
    struct stat buff; //buff to store file's stats
    char * mapped; //mapped thing
    char *text = "This is a nice day";

    input = open("ex1.txt", O_RDWR); //opening the file
    
    fstat(input, &buff); //getting stats of file and putting them in buff

    ftruncate(input, strlen(text)); //chaning the file size to needed

    //mappig
    mapped = (char*)mmap(0, buff.st_size, PROT_READ|PROT_WRITE, MAP_SHARED, input, 0);
    
    strcpy(mapped, text); //copying the text

    close(input);
    munmap(mapped, buff.st_size);
    
    return 0;
}