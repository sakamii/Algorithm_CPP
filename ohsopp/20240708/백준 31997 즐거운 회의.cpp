
#include <iostream>
using namespace std;
int n, m, t, a, b, dat[200010], man[200010][2];

void f(int x, int y) { dat[man[x][0]]++; dat[man[y][1]]--; }

int main() {
  ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n >> m >> t;
	for (int i = 1; i <= n; i++)
		cin >> man[i][0] >> man[i][1];

	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		if (man[a][0] <= man[b][0]) {
			if (man[a][1] > man[b][0] && man[a][1] < man[b][1]) f(b, a);
			else if (man[a][1] >= man[b][1]) f(b, b);
		}
		else if (man[b][0] <= man[a][0]) {
			if (man[b][1] > man[a][0] && man[b][1] < man[a][1]) f(a, b);
			else if (man[b][1] >= man[a][1]) f(a, a);
		}
	}
	for (int i = 0; i < t; i++) {
		dat[i] += dat[i - 1];
        cout << dat[i] << '\n';
    }
}
