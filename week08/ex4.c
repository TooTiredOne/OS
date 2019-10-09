#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/resource.h>

int main(int argc, char const *argv[]) {
  char *ptr;
  struct rusage usage;
  long mem;

  for(int i = 0; i < 10; i++)
  {
    ptr = (char*) malloc(10 * 1024 * 1024 * sizeof(char)); //allocating 10 mb
    memset(ptr, '0', 10 * 1024 * 1024 * sizeof(char)); //filling with 0s
    getrusage(RUSAGE_SELF, &usage); //getting the usage info
    mem = usage.ru_maxrss; //used memory

    printf("%ld\n", mem);
    sleep(1);
  }
  return 0;
}

/*
output:

11136
21728
32024
42320
52616
62912
72944
83240
93536
103832
*/
