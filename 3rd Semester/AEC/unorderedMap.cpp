#include <bits/stdc++.h>
using namespace std;

int main() {
    unordered_map<int, string> student;
    int n;
    cout << "Enter total students: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        int index;
        string name;
        cout << "Enter unique index: ";
        cin >> index;
        cout << "Enter name: ";
        cin >> name;
        student.insert({index, name});
    }
    for (auto& it : student) {
        cout << it.first << ": " << it.second << "\n";
    }
    return 0;
}