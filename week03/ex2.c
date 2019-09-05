#include <stdio.h>

void bubble_sort(int *a, int size)
{
        int temp;
        int swapped;

        do {

                swapped = 0;

                for(int i = 0; i < size-1; i++)
                {
                        if(a[i] > a[i + 1])
                        {
                                temp = a[i];
                                a[i] = a[i + 1];
                                a[i + 1] = temp;
                                swapped++;
                        }
                }

        } while(swapped);
}

int main()
{
        const int size = 10; //the size of array which will be sorted
        int arr[] = {9, 10, 7, 6, 3, 5, 9, 2, 1, 0}; //the array which will be sorted

        bubble_sort(arr, 10);

        //printing the array after sorting
        for(int i = 0; i < size; i++)
        {
                printf("%d ", arr[i]);
        }

        return 0;
}
