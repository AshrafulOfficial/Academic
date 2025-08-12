#include<bits/stdc++.h>
using namespace std;

struct Process{
    string name;
    int at,bt,tat,wt,ct,rt;
};

int main(){
    freopen("input.txt", "r", stdin);

    int n;
    cin>>n;
    vector<Process>process(n);
    for(int i=0; i<n; i++){
        cin>>process[i].name>>process[i].at>>process[i].bt;
        process[i].rt = process[i].bt;
    }

    int completed = 0, current_time = 0, prev = -1;
    vector<bool>is_completed(n, false);

    vector<string>gantt_names;

    while(completed < n){
        int idx = -1, min_rt = INT_MAX;
        for(int i=0; i<n; i++){
            if(process[i].at <= current_time && !is_completed[i] && process[i].rt > 0){
                if(process[i].rt < min_rt){
                    min_rt = process[i].rt;
                    idx = i;
                }
                if(process[i].rt == min_rt){
                    if(process[i].at < process[idx].rt){
                        min_rt = process[i].rt;
                        idx = i;
                    }
                }
            }
        }

        if(idx != -1){
            if(gantt_names.empty() || gantt_names.back() != process[idx].name){
                gantt_names.push_back(process[idx].name);
            }

            process[idx].rt--;
            current_time++;

            if(process[idx].rt == 0){
                process[idx].ct = current_time;
                is_completed[idx] = true;
                completed++;
            }
        }
        else{
            if(gantt_names.empty() || gantt_names.back() != "IDLE"){
                gantt_names.push_back("IDLE");
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

    for(auto p: gantt_names){
        cout<<" "<< p <<" |";
    }
    cout<<endl;

    cout<<"Name\tAT\tBT\tCT\tTAT\tWT";
    cout<<endl;
    for(auto p : process){
        cout<<p.name<<"\t"<<p.at<<"\t"<<p.bt<<"\t"<<p.ct<<"\t"<<p.wt<<"\t"<<p.tat<<endl;
    }

    cout<<endl;

    cout<<"Average Witing Time: "<<(float) tot_wt / n <<endl;
    cout<<"Average TurnAround Time: "<<(float) tot_tat / n ;

    return 0;


}