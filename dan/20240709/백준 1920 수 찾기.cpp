#include <iostream>
#include<unordered_map>
#include<vector>
using namespace std;
int n, m;
unordered_map<long long, int>um;
vector<int>answer;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		long long num;
		cin >> num;
		um[num]++;
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		long long num;
		cin >> num;
		if (um[num]) answer.push_back(1);
		else answer.push_back(0);
	}
	for (auto i : answer)
		cout << i << "\n";
}
