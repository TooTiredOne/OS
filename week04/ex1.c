#include <stdio.h>

int main()
{
        printf("\n");
        int n = 23;

        if(fork() == 0)
                printf("Hello from child [%d - %d]\n", getpid(), n);
        else
                printf("Hello from parrent [%d - %d]\n", getpid(), n);
}

/* Results

   Hello from parrent [9143 - 23]
   Hello from child [9144 - 23]

   Hello from parrent [9145 - 23]
   Hello from child [9146 - 23]

   Hello from parrent [9147 - 23]
   Hello from child [9148 - 23]

   Hello from parrent [9149 - 23]
   Hello from child [9150 - 23]

   Hello from parrent [9151 - 23]
   Hello from child [9152 - 23]

   Hello from parrent [9153 - 23]
   Hello from child [9154 - 23]

   Hello from parrent [9155 - 23]
   Hello from child [9156 - 23]

   Hello from parrent [9157 - 23]
   Hello from child [9158 - 23]

   Hello from parrent [9159 - 23]
   Hello from child [9160 - 23]

   Hello from parrent [9161 - 23]
   Hello from child [9162 - 23]

   PID is unique for each created process
   n stays the same.
   after fork() program "duplicates".
   "child" returns 0 and "parent" reutrns smth greater than 0
 */
