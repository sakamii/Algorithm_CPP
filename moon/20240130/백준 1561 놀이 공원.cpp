#include <iostream>
#include <algorithm>
using namespace std;

long long int n, m;
long long int mid;
long long int sum;
long long int ans;
int arr[10001];
int max_s = 0;
int cnt = 0;
int key_value = 0;


void bs(long long int low, long long int high) {

    // 탐색할 필요 x
    if (n <= m) {
        return;
    }
    if (low > high) return;

    // 0초에 이미 놀이기구를 전부 탄다.
    sum = m;
    mid = (low + high) / 2;

    for (int i = 0; i < m; i++) {
        sum += mid / arr[i];
    }

    if (sum >= n) {
        ans = mid;
        bs(low, mid - 1);
    }
    else if (sum < n) {
        bs(mid + 1, high);
    }
}

int main() {

    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        cin >> arr[i];
        max_s = max(max_s, arr[i]);
    }

    long long int max_time = max_s * n;

    bs(1, max_time);

    // n < m 인 경우 0초에 이미 Index가 정해짐
    if (n <= m) {
        key_value = n;
    }
    // t초에 인원이 맞게 혹은 넘치게 탔다면
    // t-1초로 돌아가서 sum이 n과 같아질 때까지
    // 비어있는 기구의 Index를 찾는다.
    else {
        sum = m;
        for (int i = 0; i < m; i++) {
            sum += (ans - 1) / arr[i];
        }

        for (int i = 0; i < m; i++) {
            if (ans % arr[i] == 0) {
                sum++;
                if (sum == n) key_value = i + 1;
            }
        }
    }
    cout << key_value;

    return 0;
}
