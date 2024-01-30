#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> students(n);
    for (int i = 0; i < n; i++) 
        cin >> students[i];
    
    sort(students.begin(), students.end());
    
    unsigned int cnt = 0;
    for (int i = 0; i < n - 1; i++) { 
        for (int j = i + 1; j < n; j++) { 
            int a = -(students[i] + students[j]);
            int upper = upper_bound(students.begin() + j + 1, students.end(), a) - students.begin();
            int lower = lower_bound(students.begin() + j + 1, students.end(), a) - students.begin();
            cnt += (upper - lower);
        }
    }
    cout << cnt;
}
