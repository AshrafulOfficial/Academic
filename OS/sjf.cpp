#include <iostream>
#include <iomanip>
#include <utility> // for std::swap
using namespace std;

int main() {
    int burst_time[20], p[20], waiting_time[20], tat[20];
    int i, j, n, total = 0;
    float avg_waiting_time, avg_tat;

    cout << "Please enter number of processes: ";
    cin >> n;

    cout << "\nEnter the Burst Time:\n";
    for (i = 0; i < n; i++) {
        cout << "P" << i + 1 << ": ";
        cin >> burst_time[i];
        p[i] = i + 1;  // Process ID (P1, P2, etc.)
    }

    // Stable sort: if burst time equal, keep lower PID first
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (burst_time[j] < burst_time[i] ||
               (burst_time[j] == burst_time[i] && p[j] < p[i])) {
                swap(burst_time[i], burst_time[j]);
                swap(p[i], p[j]);
            }
        }
    }

    // Calculate waiting times
    waiting_time[0] = 0;
    for (i = 1; i < n; i++) {
        waiting_time[i] = 0;
        for (j = 0; j < i; j++)
            waiting_time[i] += burst_time[j];
        total += waiting_time[i];
    }

    avg_waiting_time = (float)total / n;

    // Calculate turnaround times
    total = 0;
    cout << "\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n";
    for (i = 0; i < n; i++) {
        tat[i] = burst_time[i] + waiting_time[i];
        total += tat[i];
        cout << "P" << p[i] << "\t"
             << burst_time[i] << "\t\t"
             << waiting_time[i] << "\t\t"
             << tat[i] << "\n";
    }

    avg_tat = (float)total / n;

    cout << fixed << setprecision(2);
    cout << "\nAverage Waiting Time = " << avg_waiting_time;
    cout << "\nAverage Turnaround Time = " << avg_tat << "\n";

    return 0;
}
