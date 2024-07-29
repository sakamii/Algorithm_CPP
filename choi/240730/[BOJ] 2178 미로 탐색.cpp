#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>

using namespace std;

int n, m;
queue<pair<int, int>> q;
int graph[100][100];
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

int bfs(int _x, int _y)
{
	q.push(pair<int, int>(_x, _y));

	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m)
				continue;
			if (graph[nx][ny] == 1)
			{
				graph[nx][ny] = graph[x][y] + 1;
				q.push(pair<int, int>(nx, ny));
			}
		}
	}
	return graph[n - 1][m - 1];
}

int main(void)
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			scanf("%1d", &graph[i][j]);
	}

	cout << bfs(0, 0);
	return 0;
}