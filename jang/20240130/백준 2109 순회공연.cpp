#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

vector<int>isHere;
int answer;

int main() {
	int N;
	cin >> N;
	priority_queue<pair<int, int>, vector<pair<int, int>>, less<>>A; //less 매개변수를 넣어준다면 첫번째 인자를 오름차순으로 정렬한다
	isHere.resize(10001, 0); //총 10000일에서만 일어나는 문제
	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		A.push({ a,b });
	}

	for (int i = 0; i < N; i++) {
		pair<int, int>temp = A.top();
		A.pop();

		//강연료 순서대로 최대 일수부터 1번째 날까지 탐색하여
		//비어있다면 Arr 갱신
		for (int j = temp.second; j >= 1; j--) {
			if (isHere[j] == 0) {
				isHere[j] = temp.first;
				break;
			}
		}
	}

	//최대 10000일까지의 강연료를 모두 더한 값이 최대값
	int answer = 0;
	for (int i = 1; i <= 10000; i++) {
		answer += isHere[i];
	}
	cout << answer;
}
