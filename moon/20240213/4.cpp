#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector<int> v;

int visited[100];
int T, N;
int ans, sum, thr;


void three(int x) {
	int mid = v[1] * 3;
	int side;
	thr = 0;

	if (v[0] > v[2]) side = v[0] * v[2] + v[0] * 2;
	else side = v[0] * v[2] + v[2] * 2;

	if (mid > side) thr = mid;
	else thr = side;
}

void recursion(int x) {
	if (v.size() == 3) {
		three(0);
		ans = max(ans, sum + thr);
		return;
	}
	for (int i = 1; i < N - 1 - x; i++) {
		int del = v[i];
		sum += v[i-1] * v[i + 1];
		v.erase(v.begin() + i);
		recursion(x + 1);
		v.insert(v.begin() + i, del);
		sum -= v[i - 1] * v[i + 1];
	}
}

int main() {

	cin >> T;

	for (int t = 1; t <= T; t++) {
		cin >> N;
		ans = 0;
		for (int i = 0; i < N; i++) {
			int score;
			cin >> score;
			v.push_back(score);
		}

		if (N >= 3) {
			recursion(0);
		}
		else if (N == 2) {
			if (v[0] > v[1]) ans = v[0] * 2;
			else ans = v[1] * 2;
		}
		else if (N == 1) {
			ans = v[0];
		}
		

		cout << "#" << t << " " << ans << endl;
		v.clear();
	}


	return 0;
}
