#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N;	
vector<int> array1;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	cin >> N;
	array1.resize(N, 0);
	for (int i = 0; i < N; i++) {
		cin >> array1[i];
	}
	sort(array1.begin(), array1.end());
	int answer = 0;
	for (int i = 0; i < N; i++) {
		int nowNum = array1[i];
		int s = 0, e = N - 1;
		while (s < e) {
			int mid = array1[s] + array1[e];
			if (nowNum == mid) {
				if (s != i && e != i) {
					answer++;
					break;
				}
				else if (s == i) s++;
				else if (e == i) e--;
			}
			else if (nowNum > mid) {
				s++;
			}
			else if (nowNum < mid) {
				e--;
			}
		}
	}
	cout << answer;
}
