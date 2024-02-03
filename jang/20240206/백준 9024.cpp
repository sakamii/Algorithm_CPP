//백준 9024.
//정렬 후 투포인터로 양쪽 끝에서부터 시작
//K값에 가까워질수록 현재 최소값 갱신.
//절대값도 동일시 하므로 algorithm 헤더 abs사용해야할것.

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;

int numArray[1000000];
int s, e, n, k, a;
int answer = 1;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int tc;
	cin >> tc;
	while (tc--) {
		cin >> n >> k;
		for (int i = 0; i < n; i++) {
			cin >> numArray[i];
		}
		int mintemp = INT_MAX;
		sort(numArray, numArray + n);
		s = 0, e = n - 1;
		while (s < e) {
			if (abs(k - (numArray[s] + numArray[e])) < mintemp) {
				answer = 1;
				mintemp = abs(k - (numArray[s] + numArray[e]));
			}
			else if (abs(k - (numArray[s] + numArray[e])) == mintemp) {
				answer++;	
			}
			//두 합이 음수면 ex)-1 두 합이 양수인 경우도 고려해주기 위해서 s++;
			//두 합이 양수면 ex)+1 두 합이 음수인 경우도 고려해주기 위해서 e--;
			//예제입력두번째꺼
			if (numArray[s] + numArray[e] > k) e--;
			else s++;
		}
		cout << answer << '\n';
	}
	
}
