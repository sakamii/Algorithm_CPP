#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

priority_queue<int, vector<int>, less<int>>pq1;
priority_queue<int, vector<int>, greater<int>>pq2;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int temp, N; 
	cin >> N;
	
	cin >> temp;
	cout << temp << '\n';
	pq1.push(temp);
	for (int i = 2; i <= N; i++) {
		cin >> temp;
		if (temp >= pq1.top()) {
			pq2.push(temp);
		}
		else {
			pq1.push(temp);
		}
		if (pq1.size() < pq2.size()) {
			pq1.push(pq2.top());
			pq2.pop();
		}
		else if (pq1.size() - 2 == pq2.size()) {
			pq2.push(pq1.top());
			pq1.pop();
		}
		cout << pq1.top() << '\n';
	}
}
