#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, pr[30], bt[30], ct[30], tat[30], wt[30], p[30];
    int t_wt=0, t_tat=0;
    float a_wt, a_tat;

    fstream fin("input1.txt");
    fin>>n;

    for(int i=0; i<n; i++){
        fin>>pr[i]>>bt[i];
        p[i] = i+1;
    }

    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            if(pr[j] > pr[i] || (pr[i] == pr[j] && p[j] < p[i])){
                swap(pr[i], pr[j]);
                swap(bt[i], bt[j]);
                swap(p[i], p[j]);
            }
        }
    }

    for(int i=0; i<n; i++){
        if(i == 0){
            ct[i] = bt[i];
        }
        else{
            ct[i] = ct[i-1] + bt[i];
        }

        tat[i] = ct[i];
        wt[i] = tat[i] - bt[i];
        t_tat += tat[i];
        t_wt += wt[i];
    }

    cout<<"Process\tPriority\tBurst\tCompletion\tTurnaround\tWaiting\n";
    for(int i=0; i<n; i++){
        cout<<"P"<<p[i]<<"\t\t"<<pr[i]<<"\t"<<bt[i]<<"\t"<<ct[i]<<"\t\t"<<tat[i]<<"\t\t"<<wt[i]<<endl;
    }

    a_wt = (float) t_wt / n;
    a_tat = (float) t_tat / n;

    cout<<"\nAverage Witing Time: "<<a_wt<<endl;
    cout<<"Average Turnaround Time: "<<a_tat;

    cout<<"\nGantt Chart: \n";
    for(int i=0; i<n; i++){
        cout<<"P"<<p[i];
        if(i != n-1){
            cout<<" -> ";
        }
    }
    cout<<endl;
    return 0;
}