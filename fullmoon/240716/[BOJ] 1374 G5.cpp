#include <iostream>
#include <queue>
using namespace std;

struct Room{
	int t, n;
	bool operator<(Room right) const {
		return t > right.t;
	}
};

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N;
	cin >> N;
	priority_queue<Room> start;
	priority_queue<Room> end;
	for (int i = 0; i < N; i++) {
		int num, s, e;
		cin >> num >> s >> e;
		start.push({ s, num });
		end.push({ e, num });
	}

	int ans = 0;
	while (!start.empty()) {
		Room now = start.top();
		start.pop();
		if (now.t < end.top().t) {
			ans++;
		}
		else {
			end.pop();
		}
	}
	cout << ans << "\n";
	return 0;
}
