#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int friends, capacity, already_enrolled;
        cin >> friends >> capacity >> already_enrolled;
        if (capacity < friends + already_enrolled) {
            cout << "No \n";
        } else {
            cout << "Yes \n";
        }
    }
    return 0;
}