#include<bits/stdc++.h>
using namespace std;

struct Process{
    string name;
    int pr,at,bt,ct,wt,tat,rt;
};

int main(){
    freopen("input.txt", "r", stdin);

    int n;
    cin>>n;
    vector<Process>process(n);

    for(int i=0; i<n; i++){
        cin>>process[i].name>>process[i].pr>>process[i].at>>process[i].bt;
        process[i].rt = process[i].bt;
    }

    int completed = 0, current_time = 0;
    vector<bool>is_completed(n, false);

    vector<string>gantt;

    while(completed < n){
        int idx = -1, min_pr = INT_MAX;
        for(int i=0; i<n; i++){
            if(process[i].at <= current_time && !is_completed[i] && process[i].rt > 0){
                if(process[i].pr < min_pr){
                    min_pr = process[i].pr;
                    idx = i;
                }
                if(process[i].pr == process[idx].pr){
                    if(process[i].at < process[idx].at){
                        min_pr = process[i].pr;
                        idx = i;
                    }
                }
            }
        }

        if(idx != -1){
            if(gantt.empty() || gantt.back() != process[idx].name){
                gantt.push_back(process[idx].name);
            }
            process[idx].rt--;
            current_time++;

            if(process[idx].rt == 0){
                completed++;
                is_completed[idx] = true;
                process[idx].ct = current_time;
            }
        }
        else{
            if(gantt.empty() || gantt.back() != "IDLE"){
                gantt.push_back("IDLE");
            }
            current_time++;
        }
    }

    int tot_wt = 0, tot_tat = 0;
    for(int i=0; i<n; i++){
        process[i].tat = process[i].ct - process[i].at;
        process[i].wt = process[i].tat - process[i].bt;
        tot_wt = tot_wt + process[i].wt;
        tot_tat = tot_tat + process[i].tat;
    }

    cout<<endl<<endl;

    for(auto p : gantt){
        cout<<" "<< p <<" |";
    }
    cout<<endl<<endl;

    cout<<"Process\tPriority\tAT\tBT\tCT\tTAT\tWT";
    cout<<endl;

    for(auto p : process){
        cout<<p.name<<"\t"<<p.pr<<"\t"<<p.at<<"\t"<<p.bt<<"\t"<<p.ct<<"\t"<<p.tat<<"\t"<<p.wt<<endl;
    }
    cout<<endl<<endl;

    cout<<"Total Waiting Time is: "<<tot_wt<<endl;
    cout<<"Average Waiting time is: "<<(float) tot_wt / n<<endl;
    cout<<"Total TurnAround Time is: "<<tot_tat<<endl;
    cout<<"Average TurnAround Time is: "<<tot_tat / n;

    return 0;
}