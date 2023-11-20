#include <bits/stdc++.h>
using namespace std;


void fifoPage(int pg[], int pn, int fn) {
    vector<int> fr;
    queue<int> fifoQueue;
    int pageFaults = 0;

    for (int i = 0; i < pn; i++) {
        int currentPage = pg[i];

        if (find(fr.begin(), fr.end(), currentPage) == fr.end()) {
            pageFaults++;

            if (fr.size() < fn) {
                fr.push_back(currentPage);
                fifoQueue.push(currentPage);
            } else {
                int replacedPage = fifoQueue.front();
                fifoQueue.pop();
                fr.erase(remove(fr.begin(), fr.end(), replacedPage), fr.end());
                fr.push_back(currentPage);
                fifoQueue.push(currentPage);
            }
        }

        cout << "Page " << currentPage << " is in the frame. Frame Contents: ";
        for (const auto& frameContent : fr) {
            cout << frameContent << " ";
        }
        cout << endl;
    }

    cout << "No. of page faults = " << pageFaults << endl;
}

int main() {
    int pn, fn;

    cout << "Enter the number of pages: ";
    cin >> pn;
    int pg[pn];

    cout << "Enter the page numbers:" << endl;
    for (int i = 0; i < pn; i++) {
        cin >> pg[i];
    }

    cout << "Enter the frame size: ";
    cin >> fn;

    fifoPage(pg, pn, fn);

    
    return 0;
}