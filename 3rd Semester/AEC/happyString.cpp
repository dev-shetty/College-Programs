#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int flag = 0;
        string s;
        cin >> s;
        for (int i = 0; i < s.length() - 3; i++) {
            flag = 0;
            for (int j = i; j < i + 3; j++) {
                if (s[j] != 'a' && s[j] != 'e' && s[j] != 'i' && s[j] != 'o' &&
                    s[j] != 'u') {
                    flag = 1;
                }
            }
            if (flag == 0) {
                cout << "Happy\n";
                break;
            }
        }
        if (flag == 1) {
            cout << "Sad \n";
        }
    }
    return 0;
}