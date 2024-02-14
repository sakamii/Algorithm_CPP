//풍선 사격 게임
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N, M, K, nowNum, answer;
vector<int>balloon;
vector<bool>visited;


void DFS2(int d, int sum) {
	if (d == N) {
		answer = max(answer, sum);
		return;
	}

	for (int i = 1; i <= N; i++) {
		if (!visited[i]) {
			visited[i] = true;

			int tmp = 1;
			int idx = i;
			while (visited[idx]) idx--;
			tmp *= balloon[idx];
			idx = i;
			while (visited[idx]) idx++;
			tmp *= balloon[idx];

			if (d + 1 == N) DFS2(d + 1, sum + balloon[i]);
			else DFS2(d + 1, sum + tmp);

			visited[i] = false;
		}
	}
}

int main() {
	int tc;
	cin >> tc;
	for (int x = 1; x <= tc; x++) {
		answer = 0;
		cin >> N;
		balloon.resize(N + 2, 0);
		visited.resize(N + 2, false);
		balloon[0] = balloon[N + 1] = 1;

		
		for (int i = 1; i <= N; i++)
			cin >> balloon[i];

		
		DFS2(0, 0);
		cout << '#' << x << ' ' << answer << '\n';
	}
}
