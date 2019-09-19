#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

#define BUF_SIZE 8 //max size of the buffer

int buff; //buffer
int empty, full; //flags for checking if the buffer is empty/full

void *print_states() //prints curretns states and goes to sleep for 1 minute
{
        while(1) {
                printf("empty = %d\nfull = %d\nbuff = %d\n", empty, full, buff);
                sleep(60);
        }
}

void *produce()
{
        while(1)
        {
                if(full) //sleep if full
                {
                        continue;
                }
                else if(empty)
                {
                        buff++;
                        empty = 0; //wake up consumer
                }
                else
                {
                        buff++; //produce
                        if(buff == BUF_SIZE)
                                full = 1; //go to sleep if full
                }
        }
}

void *consume()
{
        while(1)
        {
                if(empty) //sleep if empty
                {
                        continue;
                }
                else if(full)
                {
                        buff--;
                        full = 0; //wake up producer
                }
                else
                {
                        buff--;
                        if(buff == 0)
                                empty = 1;//sleep if empty
                }
        }
}


int main(int argc, char const *argv[]) {

        pthread_t producer, consumer, states;
        int check; //for catching errors during threads creation

        buff = 0; //at the begginning, the buffer is empty
        empty = 1;
        full = 0;

        //creating producer thread
        check = pthread_create(&producer, NULL, produce, NULL);
        if(check)
        {
                printf("ERROR; failed to create a producer");
                exit(-1);
        }

        //creating a consumer
        check = pthread_create(&consumer, NULL, consume, NULL);
        if(check)
        {
                printf("ERROR; failed to create a consumer");
                exit(-1);
        }

        //creating a thread that prints states
        check = pthread_create(&states, NULL, print_states, NULL);
        if(check)
        {
                printf("ERROR; failed to create a thread for printing states");
                exit(-1);
        }

        pthread_join(producer, NULL);
        pthread_join(consumer, NULL);
        pthread_join(states, NULL);

        return 0;
}

/*
Output:
empty = 1
full = 1
buff = 0
empty = 1
full = 1
buff = 0
empty = 1
full = 1
buff = 0
...

as you can see, the error occured during the 1st minute
both processes are sleeping, which is bad

*/
