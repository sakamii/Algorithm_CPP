#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;

int DP[100001];

int main() {
	int n, k;
	cin >> n >> k;
	vector<int>coin;
	for (int i = 0; i < 100001; i++) {
		DP[i] = 2e9;
	}
	//애초에 k의 범위가 10000밖에 되지 않으므로 이를 최댓값으로 갱신해준다.
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		coin.push_back(a);
		DP[a] = 1;//해당 가격을 한 코인으로만 만들 수 있다
	}

	sort(coin.begin(), coin.end());
	DP[0] = 0;

	for (int i = 0; i < coin.size(); i++) { //해당 코인 선택
		for (int j = coin[i]; j <= k; j++) {
			DP[j] = min(DP[j], DP[j - coin[i]] + 1);
			//DP[j]는 DP[j-coin[i]]에서 coin[i]를 넣었을 때 해당 숫자가 된다면 +1 처리만 해주면 된다

		}
	}

	if (DP[k] == 2e9) cout << "-1";
	else cout << DP[k];

}