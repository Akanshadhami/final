#include <bits/stdc++.h>
using namespace std;

void inputProcesses(int n, int ar[], int bt[], int prt[],int pid[]) {
    for (int i = 0; i < n; i++) {
        cout << "Arrival time of process " << i + 1 << ": ";
        cin >> ar[i];
        cout << "Burst time of process " << i + 1 << ": ";
        cin >> bt[i];
        cout << "Enter the priority for Process " << i+1 << ": ";
        cin >> prt[i];
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

void sortAccordingArrivalTimeAndPriority(int n,int *ar, int *bt, int *prt, int *pid)
    {
        int temp;
        string stemp;
        int min_at=INT_MAX;
        for(int i=0;i<n;i++){
            if(ar[i]<min_at){
                min_at=ar[i];
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n - i - 1; j++)
            {
                if(ar[j]==min_at){
                        temp = ar[j];
                        ar[j] = ar[0];
                        ar[0] = temp;

                        temp = bt[j];
                        bt[j] = bt[0];
                        bt[0] = temp;

                        temp = prt[j];
                        prt[j] = prt[0];
                        prt[0] = temp;

                        temp = pid[j];
                        pid[j] = pid[0];
                        pid[0] = temp;
                }
                else{
                    if (ar[j] > ar[j + 1])
                    {
                        temp = ar[j];
                        ar[j] = ar[j + 1];
                        ar[j + 1] = temp;

                        temp = bt[j];
                        bt[j] = bt[j + 1];
                        bt[j + 1] = temp;

                        temp = prt[j];
                        prt[j] = prt[j + 1];
                        prt[j + 1] = temp;

                        temp = pid[j];
                        pid[j] = pid[j + 1];
                        pid[j + 1] = temp;
                    }
                    else if (ar[j] == ar[j + 1])
                    {
                        if (prt[j] > prt[j + 1])
                        {
                            temp = ar[j];
                            ar[j] = ar[j + 1];
                            ar[j + 1] = temp;

                            temp = bt[j];
                            bt[j] = bt[j + 1];
                            bt[j + 1] = temp;

                            temp = prt[j];
                            prt[j] = prt[j + 1];
                            prt[j + 1] = temp;

                            temp = pid[j];
                            pid[j] = pid[j + 1];
                            pid[j + 1] = temp;
                        }
                    }
                }
                    
            }
        }
    }

void sort_res(int n, int pid[], int ar[], int bt[],int prt[], int ct[], int ta[], int wt[]){
    for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n - i - 1; j++)
            {
                
                    if (pid[j] > pid[j + 1])
                    {
                        swap(pid[j],pid[j+1]);
                        swap(ar[j],ar[j+1]);
                        swap(bt[j],bt[j+1]);
                        swap(prt[j],prt[j+1]);
                        swap(ct[j],ct[j+1]);
                        swap(ta[j],ta[j+1]);
                        swap(wt[j],wt[j+1]);
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

void displayResults(int n, int pid[], int ar[], int bt[],int prt[], int ct[], int ta[], int wt[]) {
     vector<pair<int,int>> v;
    for(int i=0;i<n;i++){
        v.push_back({ct[i],pid[i]});
    }
    sort(v.begin(),v.end());
    cout<<"Ghant Chart = ";
    for(int i=0;i<n;i++){
        cout<<"P"<<v[i].second<<" ";
    }
    cout<<endl;
    cout << "\nPID Arrival Burst Priority Complete Turnaround Waiting\n";
    for (int i = 0; i < n; i++) {
        cout << pid[i] << "\t" << ar[i] << "\t" << bt[i] << "\t" <<prt[i]<<"\t"<< ct[i] << "\t" << ta[i] << "\t" << wt[i] << endl;
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
    int prt[10];

    float avgwt = 0, avgta = 0;

    inputProcesses(n, ar, bt, prt,pid);
    sortAccordingArrivalTimeAndPriority(n,ar,bt,prt,pid);
    //bubbleSort(n, ar, bt, pid);
    calculateCompletionTimes(n, ar, bt, ct);
    calculateTurnaroundAndWaitingTimes(n, ar, bt, ct, ta, wt);

    for (int i = 0; i < n; i++) {
        avgta += ta[i];
        avgwt += wt[i];
    }

    //cout << "\nAverage waiting time: " << avgwt / n << endl;
    //cout << "Average turnaround time: " << avgta / n << endl;
    sort_res(n, pid, ar, bt,prt, ct, ta, wt);
    displayResults(n, pid, ar, bt,prt, ct, ta, wt);
    cout << "\nAverage waiting time: " << avgwt / n << endl;
    cout << "Average turnaround time: " << avgta / n << endl;
}

