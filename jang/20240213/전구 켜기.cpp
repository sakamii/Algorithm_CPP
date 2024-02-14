//전구켜기
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<vector<int>>A;
int N, M, K, nowNum;
vector<bool>bulbFirst;
vector<int>temp;
bool done = false;

bool calculate() {
	vector<bool>temp1 = bulbFirst;
	for (int i = 0; i < temp.size(); i++) {
		for (int elem : A[temp[i]]) {
			temp1[elem]=!temp1[elem];
		}
	}
	bool tobeAll = temp1[1];
	for (int i = 2; i <= N; i++) {
		if (tobeAll != temp1[i]) {
			return false;
		}
	}
	return true;

}

void DFS(int a, int start) {
	if (a == nowNum) {
		if (calculate()) {
			done = true;
			cout << a;
		}
		return;
	}
	for (int i = start + 1; i <= N; i++) {
		temp.push_back(i);
		DFS(a + 1, i);
		temp.pop_back();
	}
}

int main() {
	cin >> N >> M >> K;
	int q;
	bulbFirst.resize(N+1);
	for (int i = 1; i <= N; i++) {
		cin >> q;
		if (q == 1) bulbFirst[i] = true;
		else bulbFirst[i] = false;
	}
	int a, b;
	A.resize(N + 1);
	for (int i = 1; i <= M; i++) {
		for (int j = 0; j < K; j++) {
			cin >> a;
			A[i].push_back(a);
		}
		
	}
	for (int i = 1; i <= N; i++) {
		nowNum = i;
		DFS(0, 0);
		if (done) break;
	}
	if (!done) cout << -1 << '\n';
}
