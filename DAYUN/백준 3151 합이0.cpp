#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> stu(500);
long long cnt = 0;

int main() {

    int n;
    cin >> n;

    stu.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> stu[i];
    }

    sort(stu.begin(), stu.end());
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {

            int u = upper_bound(stu.begin() + j + 1, stu.end(), -stu[i] - stu[j]) - stu.begin();
            int l = lower_bound(stu.begin() + j + 1, stu.end(), -stu[i] - stu[j]) - stu.begin();

            if (l != 10000)
            {
                cnt += (u - l);
            }
        }
    }
    cout << cnt;

    return 0;
}
