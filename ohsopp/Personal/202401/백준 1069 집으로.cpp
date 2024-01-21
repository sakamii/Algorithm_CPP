
// https://www.acmicpc.net/problem/1069
/*
5가지의 경우의 수. j: (0,0) 전까지의 최대 점프 횟수
1. (0,0)까지 걸어가는 경우
2. (0,0) 전까지 j번 점프하고 남은 거리만큼 걸어가는 경우
3. (0,0) 지나서 j+1번 점프하고 지나친 거리만큼 걸어가는 경우
4. 방향을 요리조리 꺾어서 j+1번 점프만 해서 (0,0)에 가는 경우 (점프거리(d)가 시작 거리보다 작아야 함)
5. 1회 점프거리(d)가 시작할 때의 거리보다 클 때, 2번 점프해서 (0,0)에 가는 경우
*/

#include <iostream>
#include <cmath>
using namespace std;

int x, y, d, t, j;
double dist, ans, walk;

int main() {
	cin >> x >> y >> d >> t;

	dist = sqrt(x * x + y * y);
	j = dist / d;
	walk = dist - j * d;

	ans = min(dist, walk + j * t);

	ans = min(ans, (j + 1) * d - dist + (j + 1) * t);

	if (j) ans = min(ans, double(j + 1) * t);
	else if (dist < d) ans = min(ans, t * 2.0);

	cout << fixed; cout.precision(10);
	cout << ans;
}
