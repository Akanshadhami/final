#include <bits/stdc++.h>
using namespace std;

void inputProcesses(int n, int ar[], int bt[], int pid[]) {
    for (int i = 0; i < n; i++) {
        cout << "Enter Arrival time and burst time of process " << i + 1 << ": ";
        cin >> ar[i]>> bt[i];
        pid[i] = i + 1;
    }
}

void bubbleSort(int n, int ar[], int bt[], int pid[]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - (i + 1); j++) {
            if (ar[j] > ar[j + 1]) {
                swap(ar[j], ar[j + 1]);
                swap(bt[j], bt[j + 1]);
                swap(pid[j], pid[j + 1]);
            }
        }
    }
}

void calculateCompletionTimes(int n, int ar[], int bt[], int ct[]) {
    ct[0] = ar[0] + bt[0];
    for (int i = 1; i < n; i++) {
        if (ar[i] > ct[i - 1])
            ct[i] = ar[i] + bt[i];
        else
            ct[i] = ct[i - 1] + bt[i];
    }
}

void calculateTurnaroundAndWaitingTimes(int n, int ar[], int bt[], int ct[], int ta[], int wt[]) {
    for (int i = 0; i < n; i++) {
        ta[i] = ct[i] - ar[i];
        wt[i] = ta[i] - bt[i];
    }
}

void displayResults(int n, int pid[], int ar[], int bt[], int ct[], int ta[], int wt[]) {

    vector<pair<int,int>> v;
    for(int i=0;i<n;i++){
        v.push_back({ar[i],pid[i]});
    }
    sort(v.begin(),v.end());
    cout<<"Ghant Chart = ";
    for(int i=0;i<n;i++){
        cout<<"P"<<v[i].second<<" ";
    }
    cout<<endl;

    cout << "\nPID Arrival Burst Complete Turnaround Waiting\n";
    for (int i = 0; i < n; i++) {
        cout << pid[i] << "\t" << ar[i] << "\t" << bt[i] << "\t" << ct[i] << "\t" << ta[i] << "\t" << wt[i] << endl;
    }


}

int main() {
    int n;
    cout << "Enter the number of processes: ";
    cin >> n;
    int pid[10];
    int ar[10];
    int bt[10];
    int ct[10];
    int ta[10];
    int wt[10];
    float avgwt = 0, avgta = 0;

    inputProcesses(n, ar, bt, pid);
    bubbleSort(n, ar, bt, pid);
    calculateCompletionTimes(n, ar, bt, ct);
    calculateTurnaroundAndWaitingTimes(n, ar, bt, ct, ta, wt);

    for (int i = 0; i < n; i++) {
        avgta += ta[i];
        avgwt += wt[i];
    }

    //cout << "\nAverage waiting time: " << avgwt / n << endl;
    //cout << "Average turnaround time: " << avgta / n << endl;

    displayResults(n, pid, ar, bt, ct, ta, wt);
    cout << "\nAverage waiting time: " << avgwt / n << endl;
    cout << "Average turnaround time: " << avgta / n << endl;
}