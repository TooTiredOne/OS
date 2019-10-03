#include <stdio.h>

const int c = 23; //initialized constant global variable, stored in data segment
int a = 25; //initialized global variable, stored in data segment
int b; //uninitialized global variable, stored in .bss

int main(int argc, char const *argv[]) {

        static int g = 23; //initialized static variable, stored in data segment
        static int h; //uninitialized static variable, stored in .bss

        printf("g = %d", g);

        return 0;
}
