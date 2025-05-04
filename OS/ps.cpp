#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, pr[30], bt[30], wt[30], tat[30],p[30],t_wt=0,t_tat=0, i, j;
    float a_wt, a_tat;

    cout<<"Enter the number of process: ";
    cin>>n;

    cout<<"Enter the priority and Burst Time: ";
    for(i=0; i<n; i++){
        cout<<"P"<<i+1<<": ";
        cin>>pr[i]>>bt[i];
        p[i] = i+1;
    }

    for(i=0; i<n-1; i++){
        for(j=i+1; j<n; j++){
            if(pr[j] < pr[i] || (pr[j] == pr[i] && p[j] < p[i])){
                swap(pr[i], pr[j]);
                swap(p[i], p[j]);
                swap(bt[i], bt[j]);
            }
        }
    }
    
    wt[0] = 0;
    for(i=1; i<n; i++){
        wt[i] = 0;
        for(j=0; j<i; j++){
            wt[i] = wt[i] + bt[j];
        }
    }

    cout<<"Process\t\tPriority\tBurst Time\tWaiting Time\tTurn Around Time"<<endl;

    for(i=0; i<n; i++){
        tat[i] = wt[i] + bt[i];
        t_wt = t_wt + wt[i];
        t_tat = t_tat + tat[i];
        cout<<"P"<<p[i]<<"\t\t"<<pr[i]<<"\t\t"<<bt[i]<<"\t\t"<<wt[i]<<"\t\t"<<tat[i]<<endl;
    }
    cout<<endl;

    a_wt = (float) t_wt/n;
    a_tat = (float) t_tat/n;

    return 0;
}