#include <iostream>
#include <queue>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;
int t, n, sum;
int map[20][20];
int dat[100];
int ans = INT_MAX;

// 시너지 구해주기
int calc(vector<int>v) {
	sum = 0;
	for (int i : v) {
		for (int j : v) {
			if (i == j)continue;
			sum += map[i][j];
		}
	}
	return sum;
}
// 팀 나누기
void dfs(int now, int cnt) {
	if (cnt == n / 2) {
		vector<int>v1;
		vector<int>v2;
		for (int i = 0; i < n; i++) {
			if (dat[i] == 0)v1.push_back(i);
			else v2.push_back(i);
		}
		int a= calc(v1);
		int b = calc(v2);
		ans = min(abs(a - b), ans);
	}
	for (int i = now; i < n; i++) {
		if (dat[i] != 0)continue;
		dat[i] = 1;
		dfs(i, cnt+1);
		dat[i] = 0;
	}
}

int main() {
	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
        ans = INT_MAX;
		cin >> n;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++) {
				cin >> map[i][j];
			}
		int de = -1;
		dfs(0, 0);
		cout <<"#"<<tc<<" "<< ans<<endl;
	}
}
