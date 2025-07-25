#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, bt[30], wt[30], tat[30],p[30],t_wt=0, t_tat=0, i, j;
    float a_wt, a_tat;

    fstream fin("F:/Academic/OS/input.txt");

    //cout<<"Enter the number of process:\n";
    fin>>n;

    //cout<<"Enter the Burst Time:"<<endl;
    for(i=0; i<n; i++){
        //cout<<"P["<<i+1<<"]: ";
        fin>>bt[i];
        p[i] = i+1;
    }

    for(i=0; i<n-1; i++){
        for(j=i+1; j<n; j++){
            if(bt[j] < bt[i] || (bt[i] == bt[j] && p[j] < p[i])){
                swap(bt[i], bt[j]);
                swap(p[i], p[j]);
            }
        }
    }

    wt[0] = 0;
    for(i=1; i<n; i++){
        wt[i] = 0;
        for(j=0; j<i; j++){
            wt[i] = wt[i]+bt[j];
        }
    }

    cout<<"Process\t\tBurst Time\t\t\tWaiting Time\t\t\tTurn Around Time"<<endl;

    for(i=0; i<n; i++){
        tat[i] = wt[i] + bt[i];
        t_wt = t_wt + wt[i];
        t_tat = t_tat + tat[i];
        cout<<"P"<<p[i]<<"\t\t\t"<<bt[i]<<"\t\t\t"<<wt[i]<<"\t\t\t"<<tat[i]<<endl;
    }
    cout<<endl;
    a_wt = (float)t_wt/n;
    a_tat = (float)t_tat/n;

    cout<<"The average waiting time: "<<a_wt<<endl;
    cout<<"Average Turn Around Time: "<<a_tat;
    return 0;
}