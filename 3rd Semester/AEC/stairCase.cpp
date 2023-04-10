#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int total, climb, moves = 0;
        cin >> total >> climb;
        moves = (total / climb) + (total % climb);
        cout << moves << "\n";
    }
    return 0;
}