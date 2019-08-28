#include <stdio.h>

//prints n stars
void print_stars(int n)
{
        for(int i = 0; i < n; i++)
                printf("*");
}

//prints 1st figure
void print_first_fig(int n)
{
        for(int i = 1; i <= n; i++)
        {
                print_stars(i);
                printf("\n");
        }

}

//prints 2nd figure
void print_second_fig(int n)
{
        for(int i = 1; i <= n / 2; i++)
        {
                print_stars(i);

                printf("\n");
        }

        print_stars(n/2 + 1);

        printf("\n");

        for(int i = n/2; i >= 1; i--)
        {
                print_stars(i);

                printf("\n");
        }
}

//prints 3rd figure
void print_third_fig(int n)
{
        for(int i = 0; i < n; i++)
        {
                print_stars(n);
                printf("\n");
        }
}


int main()
{
        int n, k;

        printf("Input the number: ");
        scanf("%d", &n);

        printf("Enter the number of figure u want (1, 2, 3): ");
        scanf("%d", &k);

        if(k == 1)
                print_first_fig(n);
        else if(k == 2)
                print_second_fig(n);
        else if(k==3)
                print_third_fig(n);

}
