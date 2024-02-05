#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int N;
int cnt = 0, ans, index, len;
string str;

// XYXYAAYXY 또는 acbccba 또는 abccbca 경우 예외 처리
void check(int s, int e) {
	cnt++;

	if (str[s + cnt] != str[e - 1 - cnt]) {
		index++;
		return;
	}
	else if (str[s + 1 + cnt] != str[e - cnt]) {
		len--;
		return;
	}
	else {
		check(s, e);
	}
}

int main() {

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> str;
		len = str.length() - 1;
		ans = 0;
		index = 0;

		for (int j = 0; j < str.length() / 2; j++) {
			int start = j + index;
			int end = len - j;

			if (str[start] != str[end]) {
				ans++;
				// start 와 end가 같은 경우는 어차피 같으므로 break;
				if (start + 1 == end) break;
				else if (str[start] == str[end - 1] && str[start + 1] == str[end]) {
					check(start , end);
				}
				// end 방향에 불필요한 문자 감지
				else if (str[start] == str[end - 1]) {
					len--;
				}
				// start 방향에 불필요한 문자 감지
				else if (str[start + 1] == str[end]) {
					index++;
				}
				// 문자 하나를 지워도 해결 안되는 경우
				else {
					ans = 100;
				}
			}
		}

		if (ans == 0) cout << "0" << endl;
		else if (ans == 1) cout << "1" << endl;
		else cout << "2" << endl;

	}


	return 0;
}
