#include<iostream>
#include<vector>
using namespace std;

int w, h, p, q, t;


// 2020KB, 72ms
int main() {

	cin >> w >> h;

	cin >> p >> q;

	cin >> t;

	int d = 1;
	int nowd = 0;
	
	// 원하는 시간보다 더 길게 이동한 경우를 기준으로 스탑
	// 오버된 시간으로 먼저 구하고 오버된 시간만큼 빼줌
	// d는 오른쪽 위 방향 대각선부터 시계방향을 기준 
	while (t > 0) {

		int de = -1;
		if (d == 1) {
			int x = p;
			int y = q;
			nowd = d;
			// 첫번째 if는 가로벽을 먼저 만난 경우
			if ((w - p) > (h - q)) {
				t -= (h - q);
				p += (h - y);
				q += (h - y);
				d = 2;
			}
			// 세로 벽을 만난 경우
			else if ((w - p) < (h - q)) {
				t -= (w - p);
				p += (w - x);
				q += (w - x);
				d = 4;
			}
			// 꼭지점으로 향한 경우
			else {
				t -= (w - p);
				p = w;
				q = h;
				d = 3;
			}
		}
		else if (d == 2) {
			int x = p;
			int y = q;
			nowd = d;
			if ((w - p) > q) {
				t -= q;
				p += q;
				q = 0;
				d = 1;
			}
			else if ((w - p) < q) {
				t -= (w - x);
				p += (w - x);
				q -= (w - x);
				d = 3;
			}
			else {
				t -= (w - p);
				p = w;
				q = 0;
				d = 4;
			}
		}
		else if (d == 3) {
			int x = p;
			int y = q;
			nowd = d;
			if (p > q) {
				t -= q;
				p -= q;
				q = 0;
				d = 4;
			}
			else if (p < q) {
				t -= x;
				p = 0;
				q -= x;
				d = 2;
			}
			else {
				t -= p;
				p = 0;
				q = 0;
				d = 1;
			}
		}
		else if (d == 4) {
			int x = p;
			int y = q;
			nowd = d;
			if (p > (h - q)) {
				t -= (h - q);
				p -= (h - q);
				q = h;
				d = 3;
			}
			else if (p < (h - q)) {
				t -= p;
				p = 0;
				q += x;
				d = 1;
			}
			else {
				t -= p;
				p = 0;
				q = h;
				d = 2;
			}
		}
	}

	int dy = 0;
	int dx = 0;
	// 오버된 방향의 정반대 방향으로 바꿔주기 위해 방향 체크
	// nowd 는 while문을 탈출 할 때의 마지막 방향
	if (nowd == 1) {
		dy = -1;
		dx = -1;
	}
	else if (nowd == 2) {
		dy = 1;
		dx = -1;
	}
	else if (nowd == 3) {
		dy = 1;
		dx = 1;
	}
	else if (nowd == 4) {
		dy = -1;
		dx = 1;
	}

	// 좌표 복구
	for (int i = t; i != 0; i++) {
		p += dx;
		q += dy;
	}

	cout << p << " " << q;

	return 0;
}
