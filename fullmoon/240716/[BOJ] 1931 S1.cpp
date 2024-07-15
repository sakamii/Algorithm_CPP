#include <iostream>
#include <algorithm>
using namespace std;

struct Meeting {
	int s, e;
	bool operator<(Meeting right)const {
		if (s == right.s) {
			return e < right.e;
		}
		return s < right.s;
	}
};

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N;
	cin >> N;
	Meeting meet[100000] = { 0, };
	for (int i = 0; i < N; i++) {
		int start, end;
		cin >> start >> end;
		meet[i] = { start, end };
	}
	sort(meet, meet + N);
	
	int ans = 1;
	int end = meet[0].e;
	for (int i = 1; i < N; i++) {
		if (end <= meet[i].s) {
			end = meet[i].e;
			ans++;
		}
		else if (end > meet[i].e) {
			end = meet[i].e;
		}
	}
	cout << ans << "\n";

	return 0;
}
