#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int total_horses;
        cin >> total_horses;
        vector<int> horses(total_horses);
        for (int i = 0; i < total_horses; i++) {
            cin >> horses[i];
        }
        int min = INT_MAX;
        sort(horses.begin(), horses.end());
        for (int i = 0; i < total_horses - 1; i++) {
            if (horses[i + 1] - horses[i] < min) {
                min = horses[i + 1] - horses[i];
            }
        }
        cout << min << "\n";
    }
    return 0;
}