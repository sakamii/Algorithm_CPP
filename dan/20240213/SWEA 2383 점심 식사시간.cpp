#include <iostream>
#include <queue>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

bool team[11];
int room[11][11];
vector<pair<int, int>> person;
vector<tuple<int, int, int>>stair;
int N, personNum;
int s1x, s1y, s1time, s2x, s2y, s2time;
int total;

void input() {
	person.clear();
	stair.clear();
	person.push_back({ 0,0 });
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> room[i][j];
			if (room[i][j] == 1) {
				person.push_back({ i,j });
			}
			if (room[i][j] > 1) {
				stair.push_back(make_tuple(i, j, room[i][j]));
			}
		}
	}
}

int cal() {
	vector<int>Await;
	vector<int>Bwait;
	for (int i = 1; i < person.size(); i++) {
		if (team[i]) {
			Await.push_back(abs(person[i].first - s1x) + abs(person[i].second - s1y));
		}
		else {
			Bwait.push_back(abs(person[i].first - s2x) + abs(person[i].second - s2y));
		}
	}
	sort(Await.begin(), Await.end());
	sort(Bwait.begin(), Bwait.end());
	int atemp = 0, aindex = Await.size() - 1;
	while (aindex >= 3) {
		if (Await[aindex] - Await[aindex - 3] < s1time) {
			atemp += s1time - (Await[aindex] - Await[aindex - 3]);
		}
		aindex -= 3;
	}
	int aanswer;
	if (Await.size() == 0) aanswer = 0;
	else aanswer = Await[Await.size() - 1] + atemp + s1time + 1;

	int btemp = 0, bindex = Bwait.size() - 1;
	while (bindex >= 3) {
		if (Bwait[bindex] - Bwait[bindex - 3] < s2time) {
			btemp += s2time - (Bwait[bindex] - Bwait[bindex - 3]);
		}
		bindex -= 3;
	}
	int banswer;
	if (Bwait.size() == 0) banswer = 0;
	else banswer = Bwait[Bwait.size() - 1] + btemp + s2time + 1;
	int temptotal = max(aanswer, banswer);
	return temptotal;
}

void DFS(int a) {
	for (int i = a; i < person.size(); i++) {
		if (!team[i]) {
			team[i] = true;
			total = min(total, cal());
			DFS(i + 1);
			team[i] = false;
		}
	}
}

int main() {
	int tc;
	cin >> tc;
	for (int x = 1; x <= tc; x++) {
		total = 2e9;
		cin >> N;
		input();
		s1x = get<0>(stair[0]);
		s1y = get<1>(stair[0]);
		s1time = get<2>(stair[0]);
		s2x = get<0>(stair[1]);
		s2y = get<1>(stair[1]);
		s2time = get<2>(stair[1]);
		total = min(total, cal());//다 두번째로 들어갈때
		DFS(1);
		cout << '#' << x << ' ' << total << '\n';
	}
}
