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
    
    long long cnt = 0;
    for (int i = 0; i < n - 1; i++) { 
        for (int j = i + 1; j < n; j++) { 
            long long a = -(students[i] + students[j]);
            long long upper = upper_bound(students.begin() + j + 1, students.end(), a) - students.begin();
            long long lower = lower_bound(students.begin() + j + 1, students.end(), a) - students.begin();
            cnt += (upper - lower);
        }
    }
    cout << cnt;
}
