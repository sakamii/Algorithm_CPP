#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int inform[16][16];
int N, Total;
int tempTotal, answer=2e9;
bool visited[16];
vector<int>temp;

void cal(int start, int cnt) {
	if (cnt == N / 2) {
		int food1 = 0;
		for (int i = 0; i < temp.size(); i++) {
			for (int j = i + 1; j < temp.size(); j++) {
				food1 += inform[temp[i]][temp[j]] + inform[temp[j]][temp[i]];
			}
		}
		vector<int>temp2;
		int food2 = 0;
		for (int i = 0; i < N; i++) {
			if (!visited[i]) temp2.push_back(i);
		}
		for (int i = 0; i < temp2.size(); i++) {
			for (int j = i + 1; j < temp2.size(); j++) {
				food2 += inform[temp2[i]][temp2[j]] + inform[temp2[j]][temp2[i]];
			}
		}
		
		answer = min(answer, abs(food1 - food2));
		return;
	}
	for (int i = start; i < N; i++) {
		if (!visited[i]) {
			temp.push_back(i);
			visited[i] = true;
			cal(i + 1, cnt + 1);
			visited[i] = false;
			temp.pop_back();
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int tc;
	cin >> tc;
	for (int x = 1; x <= tc; x++) {
		cin >> N;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> inform[i][j];
				//Total += inform[i][j];
			}
		}
		cal(0, 0);
		cout << "#" << x << ' ' << answer << '\n';
		answer = 2e9;
		for (int i = 0; i < N; i++) {
			visited[i] = false;
		}
		//Total = 0;
	}
	
}
