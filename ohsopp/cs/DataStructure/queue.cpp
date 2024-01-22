
#include <iostream>
#include <queue>
using namespace std;

queue<int> q;  // queue
priority_queue<int> pq;  // priority_queue, 기본값은 내림차순
// priority_queue<int, vector<int>, greater<int>> pq2;    // 오름차순 우선순위 큐

int main() {
	for (int i = 1; i < 10; i++)
		q.push(i);

	while (!q.empty()) {  // 1 2 3 4 5 6 7 8 9
		cout << q.front() << " ";
		q.pop();
	}
	cout << endl;
  
	int arr[10] = { 12,3,6,37,45,32,64,21,79,53 };

	for (int i = 0; i < 10; i++)
		pq.push(arr[i]);

	while (!pq.empty()) {  // 79 64 53 45 37 32 21 12 6 3
		cout << pq.top() << " ";
		pq.pop();
	}
}
