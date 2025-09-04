#include <stdio.h>
void findWaitingTime(int n, int bt[], int wt[], int at[], int quantum) {
 int i, rem_bt[n];
 for (i = 0; i < n; i++) {
 rem_bt[i] = bt[i];
 }
 int t = 0; // Current time
 // Keep traversing processes in round robin manner
 // until all processes are complete
 while (1) {
 int done = 1;
 for (i = 0; i < n; i++) {
 // If a process hasn't finished its burst time
 if (rem_bt[i] > 0) {
 done = 0; // There are still processes to complete
 if (rem_bt[i] > quantum) {
 // Reduce remaining burst time by quantum
 rem_bt[i] -= quantum;
 t += quantum;
 } else {
 // If this is the last cycle for this process
 t += rem_bt[i];
 wt[i] = t - bt[i] - at[i];
 rem_bt[i] = 0; // Marking process as complete
 }
 }
 }
 // If all processes are complete
 if (done == 1) {
 break;
 }
 }
}
void findTurnAroundTime(int n, int bt[], int wt[], int tat[], int at[]) {
 for (int i = 0; i < n; i++) {
 tat[i] = bt[i] + wt[i];
 }
}
void findAvgTime(int n, int bt[], int at[], int quantum) {
 int wt[n], tat[n], total_wt = 0, total_tat = 0;
 findWaitingTime(n, bt, wt, at, quantum);
 findTurnAroundTime(n, bt, wt, tat, at);
 printf("Process\tBurst Time\tArrival Time\tWaiting Time\tTurn Around Time\n");
 // Calculate total waiting time and turn around time
 for (int i = 0; i < n; i++) {
 total_wt = total_wt + wt[i];
 total_tat = total_tat + tat[i];
 printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", i + 1, bt[i], at[i], wt[i], 
tat[i]);
 }
 float avg_wt = (float)total_wt / (float)n;
 float avg_tat = (float)total_tat / (float)n;
 printf("Average Waiting Time = %f\n", avg_wt);
 printf("Average Turnaround Time = %f\n", avg_tat);
}
int main() {
 int n;
 printf("Enter Total Process:\t ");
 scanf("%d", &n);
 int bt[n], at[n];
 printf("Enter Burst Time and Arrival Time for %d Processes:\n", n);
 for (int i = 0; i < n; i++) {
 printf("Process %d:\n", i + 1);
 printf("Burst Time: ");
 scanf("%d", &bt[i]);
 printf("Arrival Time: ");
 scanf("%d", &at[i]);
 }
 int quantum;
 printf("Enter Time Quantum:\t");
 scanf("%d", &quantum);
 findAvgTime(n, bt, at, quantum);
}
