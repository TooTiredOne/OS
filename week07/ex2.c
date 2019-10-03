#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
        //reading N
        int N;
        printf("Enter N: ");
        scanf("%d", &N);
        printf("Your numbers: ");

        //alocating memory
        int *arr = (int*)calloc(N, sizeof(int));

        //filling and printing the array
        for(int i = 0; i < N; i++)
        {
                arr[i] = i;
                printf("%d ", arr[i]);
        }

        //freeing the memory
        free(arr);

        return 0;
}
