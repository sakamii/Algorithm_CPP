#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

map<char, long long>m;
vector<string>hubo;
string password;
int N, K;

void init() {
	for (int i = 0; i <= 9; i++) {
		m.insert({ char(i + '0'), i });
	}
	for (int i = 0; i < 6; i++) {
		m.insert({ char('A' + i),10 + i });
	}
}

void inputHubo() {
	int nowIndex = 0;
	while (nowIndex < N / 4) {
		int tempInd = nowIndex;
		int cnt = 0;
		while (true) {
			string temp = "";
			for (int i = tempInd; i < tempInd + N / 4; i++) {
				temp += password[(i+N)%N];
			}
			hubo.push_back(temp);
			cnt++;
			if (cnt == 4) break;
			tempInd = (tempInd + N/4) % N;
		}
		nowIndex++;
	}
}

int main() {
	int tc;
	cin >> tc;
	for (int x = 1; x <= tc; x++) {
		init();
		cin >> N >> K >> password;
		inputHubo();
		sort(hubo.begin(), hubo.end());

		int cnt = 0;
		string hexanum = "";
		for (int i = hubo.size() - 1; i >= 0; i--) {
			if (i == N - 1) {
				cnt++;
			}
			else {
				if (hubo[i] == hubo[i + 1]) continue;
				cnt++;
			}

			if (cnt == K) {
				hexanum = hubo[i];
				break;
			}
		}

		long long answer = 0;
		int temp1 = hexanum.size() - 1;
		for (int i = 0; i <= temp1; i++) {
			answer += m[hexanum[i]] * pow(16, temp1 - i);
		}
		cout << '#' << x << ' ' << answer << '\n';
		m.clear();
		hubo.clear();
	}
	
}