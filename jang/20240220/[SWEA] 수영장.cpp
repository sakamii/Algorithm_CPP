#include <iostream>
using namespace std;

int tc, day, month, thmonth, year, answer;
bool visited[13];
int much[13];

void cal(int startMonth, int use, int tempSum) {
	int startM = startMonth;
	if (startM > 12) {
		answer = min(tempSum, answer);
		return;
	}
	while (true) {
		if (!visited[startM]) break;
		startM++;
		if (startM > 12) {
			answer = min(tempSum, answer);
			return;
		}
	}
	if (use == 1) {
		cal(startM + 1, 1, tempSum + much[startM] * day);
		cal(startM + 1, 2, tempSum + much[startM] * day);
		cal(startM + 1, 3, tempSum + much[startM] * day);
	}
	else if (use == 2) {
		cal(startM + 1, 1, tempSum + month);
		cal(startM + 1, 2, tempSum + month);
		cal(startM + 1, 3, tempSum + month);
	}
	else if (use == 3) {
		cal(startM + 3, 1, tempSum + thmonth);
		cal(startM + 3, 2, tempSum + thmonth);
		cal(startM + 3, 3, tempSum + thmonth);
	}
}

int main() {
	cin >> tc;
	for (int x = 1; x <= tc; x++) {
		answer = 2e9;
		cin >> day >> month >> thmonth >> year;
		for (int i = 1; i <= 12; i++) {
			cin >> much[i];
			if (much[i] == 0) {
				visited[i] = true;
			}
		}
		int tempSt = 0;
		for (int i = 1; i <= 12; i++) {
			if (!visited[i]) {
				tempSt = i;
				break;
			}
		}
		cal(tempSt, 1, 0);
		cal(tempSt, 2, 0);
		cal(tempSt, 3, 0);
		answer = min(year, answer);
		cout << '#' << x << ' ' << answer << '\n';

		for (int i = 1; i <= 12; i++) {
			visited[i] = false;
		}
	}
}
