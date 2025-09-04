#include <stdio.h>
#include <pthread.h>

// Function to be executed by the first thread
void *thread_function1(void *arg) {
    printf("Thread 1: Hello from Thread 1!\n");
    return NULL;
}

// Function to be executed by the second thread
void *thread_function2(void *arg) {
    printf("Thread 2: Hello from Thread 2!\n");
    return NULL;
}

int main() {
    pthread_t thread1, thread2;

    // Create the first thread
    if (pthread_create(&thread1, NULL, thread_function1, NULL) != 0) {
        perror("pthread_create");
        return 1;
    }

    // Create the second thread
    if (pthread_create(&thread2, NULL, thread_function2, NULL) != 0) {
        perror("pthread_create");
        return 1;
    }

    // Wait for both threads to finish
    if (pthread_join(thread1, NULL) != 0) {
        perror("pthread_join");
        return 1;
    }

    if (pthread_join(thread2, NULL) != 0) {
        perror("pthread_join");
        return 1;
    }

    printf("Main: Both threads have finished executing.\n");

    return 0;
}
