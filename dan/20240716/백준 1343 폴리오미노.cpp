#include <iostream>
#include <algorithm>
#include<vector>
#include<string>
using namespace std;


int main() {
	int flag = 0;
	int cnt = 0;
	string board;
	cin >> board;
	for (int i = 0; i < board.length(); i++) {
		cnt++;
		if (board[i] == '.') {
			cnt--;
			if (cnt % 2 != 0) {
				cout << -1;
				flag = 1;
				break;
			}
			else {
				for (int j = 0; j < (cnt / 4) * 4; j++) {
					board[i - cnt + j] = 'A';
				}
				cnt -= (cnt / 4) * 4;
				for (int j = 0; j < cnt; j++) {
					board[i - 1 - j] = 'B';
				}
			}
			cnt = 0;
		}
	}
	if (flag == 0) {
		if (cnt != 0) {
			if (cnt % 2 != 0) {
				cout << -1;
				return 0;
			}
			else {
				for (int j = 0; j < (cnt / 4) * 4; j++) {
					board[board.length() - cnt + j] = 'A';
				}
				cnt -= (cnt / 4) * 4;
				for (int j = 0; j < cnt; j++) {
					board[board.length() - 1 - j] = 'B';
				}
			}
		}
		for (int i = 0; i < board.length(); i++)
			cout << board[i];
	}
}
