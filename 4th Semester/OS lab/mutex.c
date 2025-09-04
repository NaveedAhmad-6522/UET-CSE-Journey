/*Write a C program using the pthread library to create three threads. 
Each thread should increment a shared counter 1,000,000 times.
 Use a mutex to ensure that the increments are performed atomically.
  Ensure that the main thread waits for all threads to finish before printing the final value of the counter.
 Provide a sample code snippet to achieve this.*/
 #include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
pthread_mutex_t mutex;
int counter=1;
void* function(void* arg){
    for(int i=0;i<30000;i++){
    pthread_mutex_lock(mutex);
    counter++;
     pthread_mutex_unlocklock(mutex);
}
}
int main(){
    pthread-t threads[3];
     pthread_mutex_init(&mutex, NULL);
    for(int i=0;i<3;i++){
        pthread_create(&threads[i],NULL,function,&counter);
    }
      for(int i=0;i<3;i++){
        pthread_join(threads[i],NULL);
    }
    pthread_mutex_destory(mutex);
}