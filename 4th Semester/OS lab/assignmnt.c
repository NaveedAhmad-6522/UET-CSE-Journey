#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

#define array_size 1000
#define  thread_num 4
pthread_mutex_t mutex;
long long sum=0;

void* function(void* arg){
    int num=*((int*)arg);
for(int i=0;i<array_size;i++){
    sum=sum+num[i];
}


}


int main(){
pthread_t arr[thread_num];
int array[array_size];
for(int i=0;i<array_size;i++){
   array[i]=1; 
}

for(int i=0;i<thread_num;i++){
    pthread_mutex_init(&mutex,NULL);
    pthread_create(&arr[i],NULL,function,&array[array_size]);

}
for(int i=0;i<thread_num;i++){
   
    pthread_join(arr[i],NULL);

}
pthread_mutex_destroy(&mutex);

}
