#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int total_students, boasting_students = 0;
        cin >> total_students;
        int marks[total_students];
        for (int i = 0; i < total_students; i++) {
            cin >> marks[i];
        }
        int boasting_student_mark = marks[total_students / 2];
        sort(marks, marks + total_students);
        for (int i = total_students / 2; i >= 0; i--) {
            if (marks[i] != boasting_student_mark) {
                boasting_students++;
                break;
            }
        }
        cout << total_students - boasting_students << "\n";
    }
    return 0;
}