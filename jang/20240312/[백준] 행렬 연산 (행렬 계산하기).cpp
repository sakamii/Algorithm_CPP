#include <iostream>
#include <vector>
using namespace std;

int N, M, Q;
int a, b, c;
vector<int>row;
vector<int>column;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> N >> M >> Q;
	row.resize(N + 1, 0);
	column.resize(M + 1, 0);
	for (int i = 0; i < Q; i++) {
		cin >> a >> b >> c;
		if (a == 1) {
			row[b] += c;
		}
		else {
			column[b] += c;
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cout << row[i]+column[j] << " ";
		}
		cout << "\n";
	}
}
