
// https://www.acmicpc.net/problem/10703

#include <bits/stdc++.h>
using namespace std;

char ch;
int r, s, mind = 1e9, dist[3001];
char pic[3000][3000];
vector<pair<int, int>> v;

int main() {
	cin >> r >> s;

	for (int i = 0; i < r; i++)
		for (int j = 0; j < s; j++) {
			cin >> ch;
			pic[i][j] = ch;
			if (ch == 'X')
				v.push_back({ i,j });
			else if (ch == '#' && !dist[j]) {
				int c = 0;
				for (int k = i; k >= 0; k--) {
					if (pic[k][j] == 'X') {
						dist[j] = c;
						break;
					}
					else if (pic[k][j] == '.') c++;
					if (!k) dist[j] = 1e9;
				}
				mind = min(mind, dist[j]);
			}
		}

	reverse(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++) {
		pic[v[i].first + mind][v[i].second] = 'X';
		pic[v[i].first][v[i].second] = '.';
	}

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < s; j++)
			cout << pic[i][j];
		cout << endl;
	}
}
