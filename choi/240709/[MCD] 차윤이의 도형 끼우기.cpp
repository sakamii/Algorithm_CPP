#include <iostream>
#include <cstring>

using namespace std;

char figure[4][5][5];
char map[11][11];
int validCnt;
int pieces;

void calcRotation()
{
	for (int y = 0; y < 4; y++)
	{
		for (int x = 0; x < 4; x++)
		{
			if (figure[0][y][x] != '$')
				continue;
			pieces++;
			figure[1][x][3 - y] = figure[0][y][x];
			figure[2][3 - y][3 - x] = figure[0][y][x];
			figure[3][3 - x][y] = figure[0][y][x];
		}
	}
}

void pullOrigin()
{
	int y_ori = 3, x_ori = 3;
	int y_90 = 3, x_90 = 3;
	int y_180 = 3, x_180 = 3;
	int y_270 = 3, x_270 = 3;
	for (int y = 0; y < 4; y++)
	{
		for (int x = 0; x < 4; x++)
		{
			if (figure[0][y][x] == '$')
			{
				if (y_ori > y)
					y_ori = y;
				if (x_ori > x)
					x_ori = x;
			}
			if (figure[1][y][x] == '$')
			{
				if (y_90 > y)
					y_90 = y;
				if (x_90 > x)
					x_90 = x;
			}
			if (figure[2][y][x] == '$')
			{
				if (y_180 > y)
					y_180 = y;
				if (x_180 > x)
					x_180 = x;
			}
			if (figure[3][y][x] == '$')
			{
				if(y_270 > y)
					y_270 = y;
				if (x_270 > x)
					x_270 = x;
			}
		}
	}

	for (int y = 0; y < 4; y++)
	{
		for (int x = 0; x < 4; x++)
		{
			if (figure[0][y][x] == '$')
			{
				figure[0][y][x] = '_';
				figure[0][y - y_ori][x - x_ori] = '$';
			}
			if (figure[1][y][x] == '$')
			{
				figure[1][y][x] = '_';
				figure[1][y - y_90][x - x_90] = '$';
			}
			if (figure[2][y][x] == '$')
			{
				figure[2][y][x] = '_';
				figure[2][y - y_180][x - x_180] = '$';
			}
			if (figure[3][y][x] == '$')
			{
				figure[3][y][x] = '_';
				figure[3][y - y_270][x - x_270] = '$';
			}
		}
	}
}

void checkSameShape()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = i + 1; j < 4; j++)
		{
			int cnt = 0;
			for (int y = 0; y < 4; y++)
			{
				for (int x = 0; x < 4; x++)
				{
					if (figure[i][y][x] != '$')
						continue;
					if (figure[i][y][x] == figure[j][y][x])
						cnt++;
				}
			}
			if (cnt == pieces)
			{
				for (int y = 0; y < 4; y++)
				{
					for (int x = 0; x < 4; x++)
						figure[j][y][x] = '_';
				}
			}
		}
	}
}

void isValid(int y, int x)
{
	char tmpMap[4][4];
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			int ny = y + i;
			int nx = x + j;
			if (ny < 0 || nx < 0 || ny >= 10 || nx >= 10)
				tmpMap[i][j] = '#';
			else
				tmpMap[i][j] = map[ny][nx];
		}
	}
	for (int idx = 0; idx < 4; idx++)
	{
		int valid = 0;
		for (int dy = 0; dy < 4; dy++)
		{
			for (int dx = 0; dx < 4; dx++)
			{
				if (figure[idx][dy][dx] != '$')
					continue;
				if (tmpMap[dy][dx] != '_')
					break;
				valid++;
			}
		}
		if (valid == pieces)
			validCnt++;
	}
}

int main()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cin >> figure[0][i][j];
			figure[1][i][j] = '_';
			figure[2][i][j] = '_';
			figure[3][i][j] = '_';
		}
	}
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
			cin >> map[i][j];
	}
	calcRotation();
	pullOrigin();
	checkSameShape();
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
			isValid(i, j);
	}

	cout << validCnt;
	return 0;
}