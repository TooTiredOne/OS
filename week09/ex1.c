#include<stdio.h>
#include<stdlib.h>


int arr[2000]; //array to store numbers from file
int len; //length of arr

int pages[2000]; //page table
int occupied = 0; //number of occupied "slots" in page table

//counters of pages
unsigned char count[2000]; //char is used as its size is 1 byte == 8 bits (as in our textbook)

//resets counters
void clear()
{
    for(int i = 0; i < 2000; i++)
    {
        count[i] = 0;
    }

    occupied = 0;
}

//checks is page n is in page table
int hit_or_miss(int n)
{
    /*
    returns 1 if hit
    returns 0 otherwise
    */

    for(int i = 0; i < occupied; i++)
    {
        if(pages[i] == n)
            return 1;
    }

    return 0;
}

//finds an index of a page with minimum references in page table
int find_min()
{
    int min = 0;

    for(int i = 1; i < occupied; i++)
    {
        if(count[pages[i]] < count[pages[min]])
            min = i;
    }

    return min;
}

//moves counters of every page 1 bit to the right
void move_right()
{
    for(int i = 0; i < 2000; i++)
    {
        count[i] >>= 1;
    }
}

//implementation of aging algorithm
int* aging(int num_page)
{
    int hit = 0, miss = 0; 
    int *result = calloc(2, sizeof(int));

    for(int i = 0; i < len; i++)
    {
        if(hit_or_miss(arr[i])) //checks if arr[i] is in page table
        {
            hit++; //if so, increment hit
        }

        else
        {
            miss++; //otherwise, increment miss

            if(occupied < num_page) //if there are any available slots in page table
            {
                pages[occupied] = arr[i]; //put arr[i] there
                occupied++; //and increase the number of occupied pages by 1
            }

            else //otherwise, find a page with minimum references in the page table and swap it with the current page
            {
                pages[find_min()] = arr[i];
            }
            
        }

        move_right(); //move counters of pages 1 bit to the right
        count[arr[i]] += 128; //add 1 to the leftmost position (128 == 10000000)
        
    }

    result[0] = hit;
    result[1] = miss;
    return result;
}

int main(int argc, char const *argv[])
{
    
    int n;
    int *a;

    //opening the file
    FILE *input = fopen("input.txt", "r");
    if(input == NULL)
    {
        printf("Could open the file. \nPlease, check that input.txt is in ur folder");
        return -1;
    }

    //reading numbers from file and storing them in arr
    while(fscanf(input, "%d ", &n) != EOF)
    {
        arr[len] = n;
        len++;
    }

    //closing the file
    fclose(input); 

    a = aging(10);
    printf("For the size of 10: hit/miss == %d/%d\n\n", a[0], a[1]);
    free(a);
    clear();

    a = aging(50);
    printf("For the size of 50: hit/miss == %d/%d\n\n", a[0], a[1]);
    free(a);
    clear();

    a = aging(100);
    printf("For the size of 100: hit/miss == %d/%d\n\n", a[0], a[1]);
    free(a);
    clear();

    return 0;
}

/*
output:

For the size of 10: hit/miss == 10/990

For the size of 50: hit/miss == 51/949

For the size of 100: hit/miss == 93/907

*/