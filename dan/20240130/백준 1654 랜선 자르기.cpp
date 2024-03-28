#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;
int k, n, lanList[10001];
int lan_sum = 0, max_value=0, answer;

int main() {
	cin >> k >> n;
	for (int i = 0; i < k; i++) {
		cin >> lanList[i];
		max_value = max(max_value, lanList[i]);
	}
	unsigned int left = 1, right = max_value, mid;
	while (left <= right) {
		mid = (left + right) / 2;
		lan_sum = 0;
		for (int i = 0; i < k; i++) {
			lan_sum += lanList[i] / mid;
		}
		if (lan_sum >= n) {
			left = mid + 1;
			answer = mid;
		}
		else {
			right = mid - 1;
		}
	}
	cout << answer;
}
