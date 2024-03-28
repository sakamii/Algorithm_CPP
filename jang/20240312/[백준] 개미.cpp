#include <iostream>
using namespace std;

int main() {
	int w, h;
	cin >> w >> h;
	int x, y;
	cin >> x >> y;
	int k;
	cin >> k;
	int tox, toy;
	tox = k % (w * 2);
	toy = k % (h * 2);
	bool nowRight = true;
	if (x == w) nowRight = false;
	while (tox != 0) {
		tox--;
		if (nowRight) {
			x++;
			if (x == w) nowRight = false;
		}
		else {
			x--;
			if (x == 0) nowRight = true;
		}
	}

	bool nowUp = true;
	if (y == h) nowUp = false;
	while (toy != 0) {
		toy--;
		if (nowUp) {
			y++;
			if (y == h) nowUp = false;
		}
		else {
			y--;
			if (y == 0) nowUp = true;
		}
	}
	cout << x << ' ' << y;
}
