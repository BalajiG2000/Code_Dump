//First come first serve is a non-pre emptive CPU scheduling algorithm
#include <stdio.h>
int main()
{
    //defining variables for further usage
    int n, sum = 0, waiting_time, turnaround_time, total_wt = 0, ttat;
    int t[10];
    float avgwt, avgtat;
    //asking the user for the number of processes
    printf("Enter the number of processes:\n");
    scanf("%d", &n);
    //accepting the burst time for each process
    for (int i = 0; i < n; i++)
    {
        printf("\nEnter the Burst Time of process %d ", i + 1);
        scanf("\n %d", &t[i]);
    }
    printf("\n\n--------First come First Serve Scheduling Algorithm--------\n");
    printf("\n Process ID \t Waiting Time \t Turn Around Time \n");
    printf(" 1 \t\t 0 \t\t %d \n", t[0]);
    ttat = t[0];
    //calculating the waiting time, turnaround time and total turnaround time
    for (int i = 1; i < n; i++)
    {
        sum += t[i - 1];
        waiting_time = sum;
        turnaround_time = sum + t[i];
        total_wt = total_wt + waiting_time;
        ttat = ttat + turnaround_time;
        printf("\n %d \t\t %d \t\t %d", i + 1, waiting_time, turnaround_time);
        printf("\n\n");
    }
    avgwt = (float)total_wt / n;
    avgtat = (float)ttat / n;
    printf("\n Average Waiting Time %4.2f", avgwt);
    printf("\n Average Turnaround Time %4.2f", avgtat);
    return 0;
}
