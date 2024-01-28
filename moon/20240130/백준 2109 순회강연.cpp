#include <iostream>
#include <queue>
using namespace std;

priority_queue<int> q[10001];
int check[10001] = { 0, };


/* 
	 그리디 알고리즘에 대해서 잘 이해하지 못해 오래걸린 문제
	 그리디 알고리즘이라는 것을 알고 다른 조건 보다도 매순간 
	 주어진 상황에서 제일 높은 값을 선택해야 한다는 것에 집중
 */
int main() {

	int n, p, d;

	int count = 1;
	int sum = 0;

	int max_value = 0;
	int max_day = 0;
	int max = 0;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> p >> d;
		q[d].push(p);
		// 제일 마지막 날짜를 찾아서 for문 돌아가는 횟수 보정
		if (max_day < d) max_day = d;
	}

	while (count <= n) {
		// 현재 상황에서 제일 큰 pay 찾기
		for (int i = 1; i <= max_day; i++) {
			if (q[i].empty()) continue;
			// max_value = 최대값
			// max = 최대값의 Index
			if (max_value < q[i].top()) {
				max_value = q[i].top();
				max = i;
			}
		}
		// max_value에 이미 저장 했기 때문에 pop
		q[max].pop();

		/*
			버릇처럼 항상 Index를 check할 때 0번부터 조사를 
			진행했었는데 지나온 날짜의 value는 필요 없기 
			때문에 강연을 할 수 있는 마지막 날짜부터 조사
		*/
		for (int i = max; i > 0; i--) {
			if (check[i] == 0) {
				sum += max_value;
				check[i] = 1;
				break;
			}
		}

		max_value = 0;
		max = 0;
		count++;

	}

	cout << sum;

	return 0;
}
