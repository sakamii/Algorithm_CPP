#include <iostream>
#include <vector>
#include <stack>
using namespace std;

stack<int> line[7];
int N, P, answer;

void play(int guitar, int pret) {
	if (line[guitar].empty()) {
		line[guitar].push(pret);
		answer++;
		return;
	}
	int nowPret = line[guitar].top();
	if (pret == nowPret) {
		return;
	}
	else if (pret > nowPret) {
		line[guitar].push(pret);
		answer++;
	}
	else if (pret < nowPret) {
		while (!line[guitar].empty()) {
			line[guitar].pop();
			answer++;
			if (line[guitar].empty()) {
				line[guitar].push(pret);
				answer++;
				break;
			}
			int tempPret = line[guitar].top();
			if (tempPret < pret) {
				line[guitar].push(pret);
				answer++;
				break;
			}
			if (tempPret == pret) return;
		}
	}
}

int main() {
	cin >> N >> P;
	int a, b;
	for (int i = 0; i < N; i++) {
		cin >> a >> b;
		if (b > P) continue;
		play(a, b);
	}
	cout << answer;
}

