#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> v;
int t, value;
int st;
int en;
int cnt;
int flag;
int k_sum;
int sum;

int main() {
  // 안쓰면 시간초과
	ios::sync_with_stdio(false);
  cout.tie(0);
  cin.tie(0);
    
	cin >> t;

	for (int i = 0; i < t; i++) {
		int n, k;
		cin >> n >> k;

		for (int j = 0; j < n; j++) {
			cin >> value;
			v.push_back(value);
		}
		//오름차순 정렬
		sort(v.begin(), v.end());

		en = v.size() - 1, st = 0, flag = 0;
		cnt = 0, k_sum = 2134567890;

		while (st < en) {
			sum = v[st] + v[en];
      // sum이 k랑 같은 경우가 나오기 전까지는
      // k와 같아지는 값이 나오면 갱신
			if (abs(sum - k) < abs(k_sum - k)) {
				cnt = 1;
				k_sum = sum;
			}
      // sum이 k와 같은 경우 또는 k 근처의 값이 계속해서 발견되는 경우
			else if (abs(sum - k) == abs(k_sum - k)) {
				cnt++;
			}

      // sum이 k보다 큰 경우 오른쪽 좌표를 왼쪽으로 이동
      // 현재 en 좌표보다 큰 위치에 있는 value의 경우에는 어차피 sum이 k를 넘음
			if (sum > k) en--;
			else st++;

		}

		cout << cnt << endl;

		v.clear();
	}

	return 0;
}
