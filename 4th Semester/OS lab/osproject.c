#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
// Define the student structure
typedef struct Student {
 int student_number; // Unique student number
 int id;
 char name[50];
 char department[50];
 int semester;
 struct Student* next;
} Student;
// Head of the linked list
Student* head = NULL;
// Mutex lock for thread safety
pthread_mutex_t lock;
// User credentials
const char username[] = "admin";
const char password[] = "password";
// Function to authenticate user
int authenticate_user() {
 char input_username[50];
 char input_password[50];
 printf("Enter Username: ");
 scanf("%s", input_username);
 printf("Enter Password: ");
 scanf("%s", input_password);
 // Clear input buffer
 while(getchar() != '\n'); // Clear input buffer
 if (strcmp(input_username, username) == 0 && strcmp(input_password, password) == 0) {
 return 1; // Authentication successful
 } else {
 printf("Invalid username or password. Access denied.\n");
 return 0; // Authentication failed
 }
}
// Function to add a student
void* add_student(void* arg) {
 pthread_mutex_lock(&lock);
 static int student_counter = 1; // Static counter for student number
 Student* new_student = (Student*)malloc(sizeof(Student));
 if (new_student == NULL) {
 fprintf(stderr, "Failed to allocate memory.\n");
 pthread_mutex_unlock(&lock);
 return NULL;
 }
 // Assign student number and increment the counter
 new_student->student_number = student_counter++;
 
 // Take student details including ID, name, department, and semester
 printf("Enter Student ID: ");
 if (scanf("%d", &new_student->id) != 1) {
 fprintf(stderr, "Invalid input for Student ID.\n");
 pthread_mutex_unlock(&lock);
 free(new_student);
 return NULL;
 }
 // Clear input buffer
 while(getchar() != '\n'); // Clear input buffer
 printf("Enter Student Name: ");
 if (scanf("%[^\n]", new_student->name) != 1) {
 fprintf(stderr, "Invalid input for Student Name.\n");
 pthread_mutex_unlock(&lock);
 free(new_student);
 return NULL;
 }
 // Clear input buffer
 while(getchar() != '\n'); // Clear input buffer
 printf("Enter Department: ");
 if (scanf("%s", new_student->department) != 1) {
 fprintf(stderr, "Invalid input for Department.\n");
 pthread_mutex_unlock(&lock);
 free(new_student);
 return NULL;
 }
 printf("Enter Semester: ");
 if (scanf("%d", &new_student->semester) != 1) {
 fprintf(stderr, "Invalid input for Semester.\n");
 pthread_mutex_unlock(&lock);
 free(new_student);
 return NULL;
 }
 // Clear input buffer
 while(getchar() != '\n'); // Clear input buffer
 // Add student to the linked list
 new_student->next = head;
 head = new_student;
 printf("Student added successfully with Student Number: %d\n", new_student->student_number);
 pthread_mutex_unlock(&lock);
 return NULL;
}
// Function to delete a student
void* delete_student(void* arg) {
 pthread_mutex_lock(&lock);
 int id;
 printf("Enter Student ID to delete: ");
 if (scanf("%d", &id) != 1) {
 fprintf(stderr, "Invalid input for Student ID.\n");
 pthread_mutex_unlock(&lock);
 return NULL;
 }
 // Clear input buffer
 while(getchar() != '\n'); // Clear input buffer
 Student* current = head;
 Student* previous = NULL;
 while (current != NULL && current->id != id) {
 previous = current;
 current = current->next;
 }
 if (current == NULL) {
 printf("Student with ID %d not found.\n", id);
 } else {
 if (previous == NULL) {
 head = current->next;
 } else {
 previous->next = current->next;
 }
 free(current);
 printf("Student deleted successfully.\n");
 }
 pthread_mutex_unlock(&lock);
 return NULL;
}
// Function to display all students
void* display_students(void* arg) {
 pthread_mutex_lock(&lock);
 Student* current = head;
 if (current == NULL) {
 printf("No students to display.\n");
 } else {
 printf("Student Records:\n");
 while (current != NULL) {
 printf("Student Number: %d, ID: %d, Name: %s, Department: %s, Semester: %d\n",
 current->student_number, current->id, current->name, current->department, current-
>semester);
 current = current->next;
 }
 }
 pthread_mutex_unlock(&lock);
 return NULL;
}
int main() {
 pthread_t tid1, tid2, tid3;
 int choice;
 // Initialize the mutex lock
 if (pthread_mutex_init(&lock, NULL) != 0) {
 fprintf(stderr, "Mutex initialization failed.\n");
 return 1;
 }
 // Authentication loop
 int authenticated = 0;
 while (!authenticated) {
 authenticated = authenticate_user();
 }
 // Once authenticated, proceed with student management
 while (1) {
 printf("\nStudent Management System\n");
 printf("1. Add Student\n");
 printf("2. Delete Student\n");
 printf("3. Display Students\n");
 printf("4. Exit\n");
 printf("Enter your choice: ");
 if (scanf("%d", &choice) != 1) {
 fprintf(stderr, "Invalid input for choice.\n");
 continue;
 }
 switch (choice) {
 case 1:
 pthread_create(&tid1, NULL, add_student, NULL);
 pthread_join(tid1, NULL);
 break;
 case 2:
 pthread_create(&tid2, NULL, delete_student, NULL);
 pthread_join(tid2, NULL);
 break;
 case 3:
 pthread_create(&tid3, NULL, display_students, NULL);
 pthread_join(tid3, NULL);
 break;
 case 4:
 pthread_mutex_destroy(&lock);
 exit(0);
 default:
 printf("Invalid choice. Please try again.\n");
 }
 }
 return 0;
}