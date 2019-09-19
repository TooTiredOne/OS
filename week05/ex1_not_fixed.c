#include <stdio.h>
#include <pthread.h>

void *print_message(void *thread_id)
{
  int id = (int) thread_id;
  printf("A message from thread number %d. My id is %d!\n", id, (int)pthread_self());
  pthread_exit(NULL);
}

int main(int argc, char const *argv[]) {
  int num_threads;

  printf("Enter the number of threads to be created: ");
  scanf("%d", &num_threads);

  pthread_t threads[num_threads];
  int check;

  for(int i = 1; i <= num_threads; i++)
  {
    printf("A thread number %d was created!\n", i);
    check = pthread_create(&threads[i], NULL, print_message, (void*)i);

    if(check)
    {
      printf("ERROR; failed to create a thread");
      exit(-1);
    }
  }
  return 0;
}

/*
Enter the number of threads to be created: 5
A thread number 1 was created!
A thread number 2 was created!
A thread number 3 was created!
A message from thread number 1. My id is 1950385920!
A message from thread number 3. My id is 1933600512!
A message from thread number 2. My id is 1941993216!
A thread number 4 was created!
A thread number 5 was created!
A message from thread number 4. My id is 1811937024!
A message from thread number 5. My id is 1923012352!


As we can see, threads do not execute in the order of their creation.
The reason is that it's up to OS(scheduler) to decide when and where execute each thread

*/
