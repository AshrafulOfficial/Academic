#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    int bt[n], wt[n];
    cout << "Enter burst times:\n";
    for (int i = 0; i < n; i++) {
        cout << "P" << i + 1 << ": ";
        cin >> bt[i];
    }

    wt[0] = 0;

    for (int i = 1; i < n; i++) {
        wt[i] = wt[i - 1] + bt[i - 1];
    }

    int total = 0;
    for (int i = 0; i < n; i++) {
        total += wt[i];
    }

    float avg = (float)total / n;

    cout << "\nProcess\tBurst Time\tWaiting Time\n";
    for (int i = 0; i < n; i++) {
        cout << "P" << i + 1 << "\t" << bt[i] << "\t\t" << wt[i] << "\n";
    }

    cout << "\nTotal waiting time: " << total;
    cout << "\nAverage waiting time: " << avg << endl;

    return 0;
}