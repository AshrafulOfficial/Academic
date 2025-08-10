#include<bits/stdc++.h>
using namespace std;
int main() {
    int n, bt[30], ct[30], tat[30], wt[30], p[30];
    int t_wt = 0, t_tat = 0;
    float a_wt, a_tat;

    fstream fin("input1.txt");

    fin >> n;
    for(int i=0; i<n; i++) {
        fin >> bt[i];
        p[i] = i+1;
    }
    for(int i=0; i<n; i++){
        if(i == 0)
            ct[i] = bt[i];
        else
            ct[i] = ct[i-1] + bt[i];

        tat[i] = ct[i];
        wt[i] = tat[i] - bt[i];
        t_wt = t_wt + wt[i];
        t_tat = t_tat + tat[i];
    }

    cout << "Process\tBurst\tCompletion\tturnaround\tWaiting\n";
    for(int i=0; i<n; i++) {
        cout << "P" << p[i] << "\t" << bt[i] << "\t" << ct[i] << "\t\t" << tat[i] << "\t\t" << wt[i] << endl;
    }
    a_wt = (float)t_wt / n;
    a_tat = (float) t_tat / n;
    cout << "\nAverage Waiting Time: " << a_wt <<endl;
    cout << "Average Turnaround Time: " << a_tat << endl;

    cout << "\nGantt Chart:\n";
    for(int i=0; i<n; i++) {
        cout << "P" << p[i];
        if(i != n-1) {
            cout << " -> ";
        }
    }
    cout << endl;
    return 0;
}