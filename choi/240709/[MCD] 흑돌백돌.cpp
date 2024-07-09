#include <iostream>
#include <cstring>

using namespace std;

char badook[9][9];
int dy[] = { -1, 0, 1, 0, -1, 1, -1, 1 };
int dx[] = { 0, 1, 0, -1, 1, -1, -1, 1 };

void checkChange(int y, int x)
{
	int nowStone = badook[y][x];
	char tmpBadook[9][9];
	for (int i = 0; i < 8; i++)
	{
		int offset = 1;
		int flag = 0;
		memcpy(tmpBadook, badook, sizeof(tmpBadook));
		while (1)
		{
			int ny = y + dy[i] * offset;
			int nx = x + dx[i] * offset;
			if (ny < 0 || nx < 0 || ny >= 8 || nx >= 8)
				break;
			if (tmpBadook[ny][nx] == nowStone)
			{
				if (offset == 1)
					flag = 1;
				else
					flag = 2;
				break;
			}
			else if (tmpBadook[ny][nx] == '_')
			{
				flag = 1;
				break;
			}
			tmpBadook[ny][nx] = nowStone;
			offset++;
		}
		if (flag == 2)
			memcpy(badook, tmpBadook, sizeof(badook));
	}
}

int main()
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
			badook[i][j] = '_';
	}
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int y, x;
		cin >> x >> y;
		if (i % 2 == 0)
			badook[y][x] = '@';
		else
			badook[y][x] = 'O';
		checkChange(y, x);
	}

	for (int i = 7; i >= 0; i--)
	{
		for (int j = 0; j < 8; j++)
			cout << badook[i][j];
		cout << "\n";
	}
	return 0;
}