#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, at[30], bt[30], wt[30], tat[30], ct[30], p[30];
    int t_wt = 0, t_tat = 0;
    
    freopen("input.txt", "r", stdin);

    cin>>n;
    for(int i = 0; i<n; i++){
        cin>>at[i]>>bt[i];
        p[i] = i + 1;
    }

    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            if(at[j] < at[i]){
                swap(at[i], at[j]);
                swap(bt[i], bt[j]);
                swap(p[i], p[j]);
            }
        }
    }

    for(int i=0; i<n; i++){
        if(i==0){
            ct[i] = max(0, at[i]) + bt[i];
        }
        else{
            ct[i] = max(ct[i-1], at[i]) + bt[i];
        }

        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
        t_wt += wt[i];
        t_tat += tat[i];
    }

    cout<<"Gantt Chart:"<<endl;
    for(int i=0; i<n; i++){
        cout<<" "<<"P"<<p[i]<<" |";
    }

    cout<<endl<<endl;
    cout << "Process\tArrival\tBurst\tCompletion\tWaiting\tTurnaround\n";
    for(int i=0; i<n; i++){
        cout << "\t" << "P" << p[i] << "\t" << at[i] << "\t" << bt[i] << "\t"
                << ct[i] << "\t" << wt[i] << "\t" << tat[i] << endl;
    }
    return 0;
}