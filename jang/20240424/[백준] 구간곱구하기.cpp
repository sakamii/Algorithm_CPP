//구간곱구하기 11505
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int toDiv = 1000000007;
vector<long> tree;

long getMul(int a, int b) {
	long sum = 1;
	while (a <= b) {
		if (a % 2 == 1) {
			sum *= tree[a];
			sum %= toDiv;
			a++;
		}
		a /= 2;
		if (b % 2 == 0) {
			sum *= tree[b];
			sum %= toDiv;
			b--;
		}
		b /= 2;
	}
	return sum;

}

void setTree(int i) {
	while (i != 1) {
		tree[i] = (tree[2 * i] % toDiv) * (tree[2 * i + 1] % toDiv) % toDiv;
		i--;
	}
}

void changeVal(int a, long b) {
	tree[a] = b;
	a /= 2;
	while (a != 1) {
		tree[a] = (tree[a * 2] % toDiv) * (tree[a * 2 + 1] % toDiv) % toDiv;
		a /= 2;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int N, M, K;
	cin >> N >> M >> K;
	int treeHeight = 0;
	int length = N;
	while (length > 0) {
		length /= 2;
		treeHeight++;
	}
	int treeSize = pow(2, treeHeight + 1);
	int leftStartNode = treeSize / 2 - 1;
	tree.resize(treeSize + 1, 1);

	for (int i = leftStartNode + 1; i <= leftStartNode + N; i++) {
		cin >> tree[i];
	}
	setTree(leftStartNode);

	for (int i = 0; i < M + K; i++) {
		long a, b, c;
		cin >> a >> b >> c;
		if (a == 1) {
			changeVal(b + leftStartNode, c);
		}
		else cout << getMul(b + leftStartNode, c + leftStartNode) << '\n';
	}
}
