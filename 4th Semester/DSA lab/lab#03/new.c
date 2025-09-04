#include <stdio.h>
#include <unistd.h>

int main() {
    printf("Root Process PID: %d\n", getpid());
    
    // Create first child
    pid_t first_child = fork();
    if (first_child == 0) {
        printf("Child Process 1 PID: %d, Parent PID: %d\n", getpid(), getppid());
        // First child process terminates here
        return 0;
    }
    
    // Create second child
    pid_t second_child = fork();
    if (second_child == 0) {
        printf("Child Process 2 PID: %d, Parent PID: %d\n", getpid(), getppid());
        // Second child process terminates here
        return 0;
    }

    // Parent process waits for both children to finish
    wait(NULL);
    wait(NULL);

    return 0;
}
