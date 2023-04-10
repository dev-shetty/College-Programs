#include <bits/stdc++.h>
using namespace std;

int main() {
    int arr[10000], reverse_arr[10000];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    for (int i = 0; i < n; i++) {
        reverse_arr[i] = arr[n - i - 1];
    }
    for (int i = 0; i < n; i++) cout << reverse_arr[i] << " ";
    cout << "\n";
    return 0;
}