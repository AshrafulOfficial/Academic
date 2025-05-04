#include<stdio.h>
int main()
{
    int n, bt[30], wt[30], tat[30], awt, atat, i, j, t_tat=0, t_wt=0;
    printf("Enter the total number of process (maximum 30): ");
    scanf("%d", &n);

    printf("Enter the Burst time\n");
    for(i=0; i<n; i++){
        printf("P[%d]: ", i+1);
        scanf("%d", &bt[i]);
    }

    wt[0]=0;
    for(i=1; i<n; i++){
        wt[i] = 0;
        for(j=0; j<i; j++){
            wt[i] = wt[i] + bt[j];
        }
    }

    printf("\nProcess\t\tBurst Time\t\tWaiting Time\t\tTurn Around Time");

    for(i=0; i<n; i++){
        tat[i] = wt[i] + bt[i];
        t_tat = t_tat + tat[i];
        t_wt = t_wt + wt[i];
        printf("\nP[%d]\t\t\t%d\t\t\t%d\t\t\t%d", i+1, bt[i], wt[i],tat[i]);
    }

    printf("\n\n");

    atat = t_tat/n;
    awt = t_wt/n;
    printf("The total Turn around time: %d\n", atat);
    printf("The total waiting time: %d", awt);
    return 0;
}