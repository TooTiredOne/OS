#include <stdio.h>

void swap(int *a, int *b)
{
        int temp = *b;

        *b = *a;
        *a = temp;
}

int main()
{
        int a, b;

        printf("Input the 1st int: ");
        scanf("%d", &a);

        printf("Input the 2nd int: ");
        scanf("%d", &b);

        printf("\n");

        printf("Before swapping:\n");
        printf("a = %d\nb = %d\n\n", a, b);

        swap(&a, &b);

        printf("After swapping:\n");
        printf("a = %d\nb = %d\n", a, b);
}
