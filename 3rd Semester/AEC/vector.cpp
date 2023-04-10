#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v;
    int n;
    cout << "Enter total elements: ";
    cin >> n;

    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        int item;
        cin >> item;
        v.push_back(item);
    }

    for (int i : v) {
        cout << i << "\t";
    }

    return 0;
}