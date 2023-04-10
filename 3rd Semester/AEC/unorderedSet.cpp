#include <bits/stdc++.h>
using namespace std;

int main() {
    unordered_set<string> fruits;
    int n;
    cout << "Enter total fruits: ";
    cin >> n;
    cout << "Enter fruit names: ";

    for (int i = 0; i < n; i++) {
        string fruit;
        cin >> fruit; 
        fruits.insert(fruit);
    }

    for (auto it : fruits) {
        cout << it << "\t";
    }

    return 0;
}