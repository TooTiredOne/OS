#include<stdio.h>

int main()
{
    char buff[5];
    char *text = "Hello";
    
    setvbuf(stdout, buff, _IOLBF, 5); //creating a buff

    //printing
    
    for(int i = 0; i < 5; i++)
    {
        printf("%c", text[i]);
        sleep(1);
    }

    printf("\n");

}