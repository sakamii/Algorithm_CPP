#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int n, m;
int map[201][201];
int visited[201][201];
int minDist = 2134567890;
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };

struct Node
{
	int y, x;
};

struct Move
{
	int y, x;
	int dist;

	bool operator<(Move a) const
	{
		if (dist < a.dist)
			return false;
		if (dist > a.dist)
			return true;
		return false;
	}
};

vector<Node> restau[2];

void bfs(int y, int x, int id, int idx)
{
	queue<Node> q;
	q.push({ y, x });
	visited[y][x] = 1;
	while (!q.empty())
	{
		Node now = q.front();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int ny = now.y + dy[i];
			int nx = now.x + dx[i];
			if (map[ny][nx] == 0 || visited[ny][nx] == 1)
				continue;
			if (map[ny][nx] != id)
				continue;
			visited[ny][nx] = 1;
			restau[idx].push_back({ny, nx});
			q.push({ ny, nx });
		}
	}
}

void findMinDist(Node& start)
{
	priority_queue<Move> pq;
	pq.push({ start.y, start.x, 0 });
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			visited[i][j] = 2134567890;
	}
	visited[start.y][start.x] = 0;
	while (!pq.empty())
	{
		Move now = pq.top();
		pq.pop();
		if (map[now.y][now.x] > 0 && map[now.y][now.x] != map[start.y][start.x])
		{
			minDist = min(minDist, visited[now.y][now.x] - 1);
			break;
		}
		for (int i = 0; i < 4; i++)
		{
			int ny = now.y + dy[i];
			int nx = now.x + dx[i];
			if (ny < 0 || nx < 0 || ny >= n || nx >= m)
				continue;
			if (map[ny][nx] == map[start.y][start.x])
				continue;
			int nextDist = now.dist + 1;
			if (nextDist >= visited[ny][nx])
				continue;
			visited[ny][nx] = nextDist;
			pq.push({ ny, nx, nextDist });
		}
	}
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cin >> map[i][j];
	}

	int flag = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (visited[i][j])
				continue;
			if (map[i][j] == 0)
				continue;
			bfs(i, j, map[i][j], flag);
			flag++;
		}
		if (flag == 2)
			break;
	}

	for(int i = 0; i < restau[0].size(); i++)
	{
		for (int i = 0; i < n; i++)
			memset(visited, 0, sizeof(visited));
		findMinDist(restau[0][i]);
	}
	cout << minDist;
	return 0;
}