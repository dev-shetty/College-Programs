#include <bits/stdc++.h>
using namespace std;

int main() {
    int x, y, side, time, count;
    cin >> x >> y >> side >> time;
    for (int i = x; i <= x + side; i++) {
        for (int j = y; j <= y + side; j++) {
            if (i + j <= time) count++;
        }
    }
    cout << count << "\n";
    return 0;
}