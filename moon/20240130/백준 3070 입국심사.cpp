#include <iostream>
#include <algorithm>
using namespace std;

unsigned long long int n, m;
unsigned long long int arr[100001];
unsigned long long int max_s = 0;
unsigned long long int cnt;
unsigned long long int sum;
unsigned long long int mid;
unsigned long long int ans;

void bs(unsigned long long int low, unsigned long long int high) {

    if (low > high) return;

    sum = 0;
    mid = (low + high) / 2;

    for (int i = 0; i < n; i++) {
        sum += mid / arr[i];
    }

    if (sum >= m) {
        ans = mid;
        bs(low, mid - 1);
    }
    else if (sum < m) {
        bs(mid + 1, high);
    }

}

int main() {

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        max_s = max(max_s, arr[i]);
    }
    // 이진 탐색을 위해 경우의 수 중에서 제일 큰 경우를 
    // high로 설정하기 위해 max_time을 찾는다.
    unsigned long long int max_time = max_s * m;

    bs(0, max_time);


    cout << ans;

    return 0;
}
