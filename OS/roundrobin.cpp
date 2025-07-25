#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,quantum, bt[30], wt[30], tat[30],rt[30],time = 0,t_wt=0, t_tat=0, i, j;
    bool done;
    cout<<"Enter the Number of Process: ";
    fin>>n;
    cout<<"Enter the Burst Time: "<<endl;
    for(i=0; i<n; i++){
        cout<<"P"<<i+1<<": ";
        fin>>bt[i];
        rt[i] = bt[i];
    }

    cout<<"Enter the Time Quantum: ";
    fin>>quantum;

    for(i=0; i<n; i++){
        wt[i] = 0;
    }

    do{
        done = true;
        for(i=0; i<n; i++){
            if(rt[i] > 0){
                done = false;
                if(rt[i] > quantum){
                    time = time + quantum;
                    rt[i] = rt[i] - quantum;
                }
                else{
                    time = time + rt[i];
                    wt[i] = time - bt[i];
                    rt[i] = 0;
                }
            }
        }
    } while(!done);

    for(i=0; i<n; i++){
        tat[i] = wt[i] + bt[i];
    }

    cout<<"Process\t\tBurst Time\t\tWaiting Time\t\tTurn Around Time"<<endl;

    for(i=0; i<n; i++){
        t_wt = t_wt + wt[i];
        t_tat = t_tat + tat[i];
        cout<<"P"<<i+1<<"\t\t"<<bt[i]<<"\t\t"<<wt[i]<<"\t\t"<<tat[i]<<endl;
    }

    float a_wt = (float) t_wt/n;
    float a_tat = (float) t_tat/n;

    cout<<"Average waiting Time: "<<a_wt<<endl;
    cout<<"Average Turn Around Time: "<<a_tat;

    return 0;


}