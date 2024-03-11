// @START 24.03.11:09:30
// @END 24.03.11:09:40
// @TOTAL 10MIN

#include <iostream>

using namespace std;

int N, M, Q;

int vect[2][500000];

int main() {
	cin >> N >> M >> Q;
	for (int i = 0; i < Q; i++) {
		int type, target, v;
		cin >> type >> target >> v;
		vect[type - 1][target - 1] += v;
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << vect[0][i] + vect[1][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}