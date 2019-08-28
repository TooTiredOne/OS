#include <stdio.h>

//prints n spaces
void print_spaces(int n)
{
        for(int i = 0; i < n; i++)
                printf(" ");
}

//prints n stars
void print_stars(int n)
{
        for(int i = 0; i < n; i++)
                printf("*");
}


int main()
{
        int n;

        //reading the hight of the triangle
        printf("Input the number: ");
        scanf("%d", &n);

        /*
           spaces - number of spaces before the fisrt and after the last stars that we need to print
           stars - number of stars we need to print
         */
        int spaces = n-1, stars = 1;

        while(spaces > -1)
        {
                print_spaces(spaces);
                print_stars(stars);
                print_spaces(spaces);
                printf("\n");

                spaces--;
                stars += 2;
        }
}
