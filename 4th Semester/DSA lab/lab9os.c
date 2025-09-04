#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
void swap(int arr[][7],int x,int y){
int temp,i;
for (i=0;i<7-1;i++){
    temp=arr[x][i];
    arr[x][i]=arr[y][i];
    arr[y][i]=temp;
}

}
void read_job_entry(int array[][7],int num_jobs){
int i;
for (i=0;i<num_jobs;i++){
    printf("enter job no for process %d:",i+1);
    scanf("%d",&array[i][0]);
    printf("enter arrival time for process %d:",i+1);
    scanf("%d",&array[i][1]);
    printf("enter burst time for process %d:",i+1);
    scanf("%d",&array[i][2]);
}
     }
     void print_sorted(int array[][7],int num_jobs){
     int i,j;
     printf("\n the sorted jobs:/n");
     printf("job no\tarrival time\tburst time\n");
     for(i=0;i<num_jobs;i++){
        for(j=0;j<3;j++){
            printf("%d\t\t",array[i][j]);

        }
        printf("\n");

     }
     printf("\n");


     }
     void sort_by_burst_time(int array[][7],int num_jobs){
     int i,j;
     for (i=0;i<num_jobs-1;i++){
        for (j=0;j<num_jobs-i-1;j++){
            if(array[j][2]>array[j+1][2]){
                swap(array,j,j+1);
            }
        }
     }
     }
     void calculate(int array[][7],int num_jobs){
     int i;
     for(i=0;i<num_jobs;i++){
        if(i==0){
            array[i][3]=array[i][1];
        }
        else{
            array[i][3]=array[i-1][4];
        }
        array[i][4]=array[i][3] + array[i][2];
        array[i][5]=array[i][3] - array[i][1];
        array[i][6]=array[i][4] - array[i][1];
     }
     }

     void printing(int array[][7], int num_jobs){
     int i;
     printf("scheduling according to algo:\n");
     printf("job no.\tarriaval time\tburst time\tstart time\tfinish time\twaiting time\tturnaround time\n");
     for(i=0;i<num_jobs;i++){
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",array[i][0],array[i][1],array[i][2],array[i][3],array[i][4],array[i][5],array[i][6]);

     }
     }
     void FCFS(){
     int num_jobs;
     printf("enter total number of jobs:");
     scanf("%d",&num_jobs);
     int process[num_jobs][7];
     read_job_entry(process,num_jobs);
     print_sorted(process,num_jobs);
     calculate(process,num_jobs);
     printing(process,num_jobs);

     }

     void SJFS(){
     int num_jobs;
     printf("enter total number of jobs:");
     scanf("%d",&num_jobs);
     int process[num_jobs][7];
     read_job_entry(process,num_jobs);
     print_sorted(process,num_jobs);
     calculate(process,num_jobs);
     printing(process,num_jobs);
     }
     int main(){
     printf("FCFS Scheduling \n\n");
     FCFS();
     printf("\n\n");
     printf("SJFS Scheduling \n\n");
     SJFS();
     printf("\n\n");
     return 0;
     }