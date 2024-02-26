#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
int t, n, k;
string str;
// 한 변의 길이만큼 돌면서 숫자를 vector에 쌓으면서 
// 만약 dat에 있는 값이 나온 경우 pass함 
// for문 끝나면 벡터 소트해서 k번째 수 구함


int main() {
	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		cin >> n >> k >> str;
		vector<int>v;
		map < long long , int > m;
		int r = n / 4;
		int start = 0;
		// 총 r번 이동하면서 
		for (int i = 0; i < r; i++) {
			// 4개의 변 탐색
			for (int j = 0; j < 4; j++) {
				char sen[30];
				for (int m = 0; m < r; m++) {
					int idx = (i + j * r + m) % n;
					sen[m] = str[idx];
				}
				long long num = strtol(sen, NULL, 16);
				// 겹치는 숫자 있으면 넘어감 
				int de = -1;
				if (m[num]==1) continue;
				m[num] = 1;
				v.push_back(num);
			}
		}
		sort(v.rbegin(), v.rend());
		cout << "#" << tc << " " << v[k - 1]<<endl;
	}
}
