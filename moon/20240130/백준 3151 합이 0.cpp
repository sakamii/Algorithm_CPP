#include <iostream>

#include<vector>

#include <algorithm>
using namespace std;

vector<int> v;
int n, m;
int sum;
long long int cnt;


int bs_1(int low, int high, int x) {

    while (low <= high) {

        int mid = (low + high) / 2;

        if (v[mid] >= x) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }

    }
    return low;
}

int bs_2(int low, int high, int x) {

    while (low <= high) {

        int mid = (low + high) / 2;

        if (v[mid] <= x) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }

    }
    return low;
}

int main() {

    cin >> n;

    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        v.push_back(val);
    }

    sort(v.begin(), v.end());
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            sum = v[i] + v[j];

            int start = bs_1(j + 1, v.size() - 1, -sum);

            int end = bs_2(j + 1, v.size() - 1, -sum);

            cnt += end - start;
        }
    }

    cout << cnt;

    return 0;
}
