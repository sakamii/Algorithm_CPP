#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;

int main() {
	vector<int>minute;
	vector<int>answer;
	cin >> N >> M;
	minute.resize(M);
	for (int i = 0; i < M; i++) {
		cin >> minute[i];
	}
	if (N <= M) {
		cout << N;
		return 0;
	}
	long long int s = 0, mid, e = 60000000000;
	long long t;
	long double temp;
	while (s <= e) {
		mid = (s + e) / 2;
		temp = M;
		for (int i = 0; i < M; i++) {
			temp += mid / minute[i];
		}
		if (temp >= N) {
			e = mid - 1;
			t = mid;
		}
		else s = mid + 1;
	}

	int nowStudent = M;
	for (int i = 0; i < M; i++) {
		nowStudent += (t - 1) / minute[i];
		answer.push_back((t - 1) % minute[i]);
	}
	for (int i = 0; i < M; i++) {
		answer[i] += 1;
		if (answer[i] % minute[i] == 0) nowStudent++;
		if (nowStudent == N) {
			cout << i + 1;
			break;
		}
	}
}

//예제 3번
//1초 : 1 0 0 0 0
//2초 : 2 1 0 0 0
//3초 : 3 1 1 0 0
//4초 : 4 2 1 1 0
//5초 : 5 2 1 1 1
//6초 : 6 3 2 1 1
//7초 : 7 3 2 1 1
//8초 : 8 4 2 2 1 - 0 0 2 0 3
//9초 : 9 4 3 2 1 - 0 1 0 1 4
