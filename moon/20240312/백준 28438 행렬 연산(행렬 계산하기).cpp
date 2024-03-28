#include<iostream>
using namespace std;

long long col[500000];
long long row[500000];

// 9832KB, 596ms
int main() {
	ios::sync_with_stdio;
	cin.tie(0);

	int N, M, Q;

	cin >> N >> M >> Q;

	for (int i = 0; i < Q; i++) {
		int type, rc, v;

		cin >> type >> rc >> v;

		if (type == 1) row[rc - 1] += v;
		else if (type == 2) col[rc - 1] += v;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << row[i] + col[j] << " ";
		}
		cout << "\n";
	}

	int de = -1;


	return 0;
}
