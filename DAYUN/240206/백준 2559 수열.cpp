#include<iostream>
#include <algorithm>

using namespace std;

int main() {
    int n, k, sum = 0;
    int result = -1000000000;
    int arr[100001];
    cin >> n >> k;

    arr[0] = 0;
    for(int i = 1; i < n + 1; i++) {
        int num;
        cin >> num;
        sum += num;
        arr[i] = sum;
    }

    for(int i = k; i <= n; i++) {
        result = max(result,arr[i] - arr[i - k]);
    }
    cout << result;
}