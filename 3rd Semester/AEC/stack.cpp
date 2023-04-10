#include <bits/stdc++.h>
using namespace std;

int main() {
    stack<int> s;

    int n;
    cout << "Enter total elements: ";
    cin >> n;

    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        int item;
        cin >> item;
        s.push(item);
    }

    for (int i = 0; i < n; i++) {
        cout << s.top() << "\t";
        s.pop();
    }

    return 0;
}