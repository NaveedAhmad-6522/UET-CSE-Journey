#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
void* fun1(void * arg){
    int num=*((int*)arg);
    printf("thread 1 with argument %d",num);
    return NULL;
}
void* fun2(void * arg1){
    int num=*((int*)arg1);
    printf("thread 2 with argument %d",num);
    return NULL;
}
int main(){
    pthread_t thread1,thread2;
    int arg[2]={1,3},result;
    result=pthread_create(&thread1,NULL,fun1,&arg[0]);
     result=pthread_create(&thread2,NULL,fun1,&arg[1]);

     pthread_join(&thread1,NULL);
     pthread_join(&thread2,NULL);

}




/*Write a C program that creates multiple threads, each printing a unique message that includes its thread number.
 Use pthread_create to create the threads and pthread_join to wait for them to complete. Pass the thread number as an
  argument to each thread.

Specifications:
The main thread should print "Main thread: Starting multiple threads."
The program should create 5 threads.
Each thread should print "Hello from thread X.", where X is the thread number.
The main thread should wait for all threads to finish and then print "Main thread: All threads have finished."*/