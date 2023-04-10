#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int height, weight;
        cin >> weight >> height;
        float BMI;
        BMI = weight / (height * height);
        if(BMI <= 18) {
            cout << "1 \n";
        } else if(BMI > 18 && BMI <= 24) {
            cout << "2 \n";
        } else if(BMI > 24 && BMI <=29) {
            cout << "3 \n";
        } else if(BMI >= 30) {
            cout << "4 \n";
        }
    }
    return 0;
}