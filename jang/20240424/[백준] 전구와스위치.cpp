//전구와 스위치 2138
#include <iostream>
#include <cmath>
using namespace std;

int N, answer1, answer2;
string now, toMake, now1, now2;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	cin >> N;
	cin >> now >> toMake;
	now1 = now;
	now2 = now;
	for (int i = 1; i < toMake.length(); i++) {
		if (now1[i - 1] != toMake[i - 1]) {
			answer1++;
			if (now1[i - 1] == '0') now1[i - 1] = '1';
			else now1[i - 1] = '0';
			if (now1[i] == '0') now1[i] = '1';
			else now1[i] = '0';
			if (i != toMake.length() - 1) {
				if (now1[i + 1] == '0') now1[i + 1] = '1';
				else now1[i + 1] = '0';
			}
		}
	}
	if (toMake != now1) answer1 = 1e9;

	answer2 = 1;
	//요기가 0번 switch 눌렀을때 
	if (now2[0] == '0') now2[0] = '1';
	else now2[0] = '0';
	if (now2[1] == '0') now2[1] = '1';
	else now2[1] = '0';
	for (int i = 1; i < toMake.length(); i++) {
		if (now2[i - 1] != toMake[i - 1]) {
			answer2++;
			if (now2[i - 1] == '0') now2[i - 1] = '1';
			else now2[i - 1] = '0';
			if (now2[i] == '0') now2[i] = '1';
			else now2[i] = '0';
			if (i != toMake.length() - 1) {
				if (now2[i + 1] == '0') now2[i + 1] = '1';
				else now2[i + 1] = '0';
			}
		}
	}
	if (toMake != now2) answer2 = 1e9;
	if (answer1 == 1e9 && answer2 == 1e9) cout << -1;
	else cout << min(answer1, answer2);
}
