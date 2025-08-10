#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, quantum;
    int bt[30], wt[30], tat[30], rt[30];
    int time = 0, t_wt = 0, t_tat = 0;

    cout << "Enter the Number of Processes: ";
    cin >> n;

    cout << "Enter the Burst Time for each process:\n";
    for(int i = 0; i < n; i++){
        cout << "P" << i+1 << ": ";
        cin >> bt[i];
        rt[i] = bt[i];  // remaining time initialized
        wt[i] = 0;      // initialize waiting time to 0
    }

    cout << "Enter the Time Quantum: ";
    cin >> quantum;

    bool done;
    do {
        done = true;
        for(int i = 0; i < n; i++){
            if(rt[i] > 0){
                done = false;
                if(rt[i] > quantum){
                    time += quantum;
                    rt[i] -= quantum;
                }
                else{
                    time += rt[i];
                    wt[i] = time - bt[i];
                    rt[i] = 0;
                }
            }
        }
    } while(!done);

    for(int i = 0; i < n; i++){
        tat[i] = wt[i] + bt[i];
    }

    cout << "\nProcess\tBurst Time\tWaiting Time\tTurn Around Time\n";
    for(int i = 0; i < n; i++){
        t_wt += wt[i];
        t_tat += tat[i];
        cout << "P" << i+1 << "\t" << bt[i] << "\t\t" << wt[i] << "\t\t" << tat[i] << endl;
    }

    cout << fixed << setprecision(2);
    cout << "\nAverage Waiting Time: " << (float)t_wt / n << endl;
    cout << "Average Turn Around Time: " << (float)t_tat / n << endl;

    return 0;
}
