#include <bits/stdc++.h>
using namespace std;

int main() {
    queue<int> q;
    int n;
    cout << "Enter total elements: ";
    cin >> n;

    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        int item;
        cin >> item;
        q.push(item);
    }

    for (int i = 0; i < n; i++) {
        cout << q.front() << "\t";
        q.pop();
    }

    return 0;
}