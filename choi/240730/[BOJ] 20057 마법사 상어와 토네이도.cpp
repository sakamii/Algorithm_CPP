#include <iostream>

using namespace std;

int A[500][500];
int r, c;
int d = 0;
int n;

int out_sand = 0;

// 토네이도 움직이는 방향
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

// 모래 날리는 비율
double sandP[9] = { 0.01, 0.01, 0.02, 0.02, 0.07, 0.07, 0.1, 0.1, 0.05 };

// 모래 이동 방향(왼->아->오->위)
// 1 -> 2 -> 7 -> 10 -> 5 -> a 순서
int sandX[4][10] = { {0, 0, -1, -1, -1, -1, -2, -2, -3, -2},
					 {-1, 1, -2, 2, -1, 1, -1, 1, 0, 0},
					 {0, 0, 1, 1, 1, 1, 2, 2, 3, 2},
					 {1, -1, 2, -2, 1, -1, 1, -1, 0, 0} };
int sandY[4][10] = { {-1, 1, -2, 2, -1, 1, -1, 1, 0, 0},
					 {0, 0, 1, 1, 1, 1, 2, 2, 3, 2},
					 {1, -1, 2, -2, 1, -1, 1, -1, 0, 0 },
					 {0, 0, -1, -1, -1, -1, -2, -2, -3, -2} };

void calc_sand(int x, int y, int dir)
{
	// y위치
	int yx = x + dx[dir];
	int yy = y + dy[dir];

	int ySand = A[yy][yx];

	if (ySand == 0)
		return;

	for (int i = 0; i < 9; i++)
	{
		int nx = x + sandX[dir][i];
		int ny = y + sandY[dir][i];
		int nSand = ySand * sandP[i];

		if (nx < 1 || nx > n || ny < 1 || ny > n)
			out_sand += nSand;
		else
			A[ny][nx] += nSand;

		A[yy][yx] -= nSand;
	}

	// a 위치
	int nx = x + sandX[dir][9];
	int ny = y + sandY[dir][9];

	if (nx < 1 || nx > n || ny < 1 || ny > n)
		out_sand += A[yy][yx];
	else
		A[ny][nx] += A[yy][yx];

	A[yy][yx] = 0;
}

int main(void)
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			cin >> A[i][j];
	}

	// 시작 좌표
	r = n / 2 + 1;
	c = n / 2 + 1;

	int cnt = 1;
	while (r >= 1 && c >= 1)
	{
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < cnt; j++)
			{
				calc_sand(r, c, d);
				r += dx[d];
				c += dy[d];
			}
			d = (d + 1) % 4;
		}
		cnt++;
	}
	cout << out_sand;
	return 0;
}