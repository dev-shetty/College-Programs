#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int total_levels, played_minutes, break_minutes;
        cin >> total_levels >> played_minutes >> break_minutes;
        int total_breaks;
        if (total_levels % 3 == 0) {
            total_breaks = total_levels / 3 - 1;
        } else {
            total_breaks = total_levels / 3;
        }
        int total_minutes =
            (played_minutes * total_levels) + (break_minutes * total_breaks);
        cout << total_minutes << "\n";
    }
    return 0;
}