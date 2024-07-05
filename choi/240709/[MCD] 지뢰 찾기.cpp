#include <iostream>
#include <queue>

using namespace std;

int n, m;
char map[51][51];
bool visited[51][51];
int x, y;
int dy[] = { -1, 0, 1, 0, -1, -1, 1, 1 };
int dx[] = { 0, -1, 0, 1, -1, 1, -1, 1 };

struct Node
{
	int y, x;
};

void bfs(int y, int x)
{
	queue<Node> q;
	vector<Node> tmp;
	q.push({ y, x });
	visited[y][x] = true;
	while (!q.empty())
	{
		Node now = q.front();
		q.pop();
		visited[now.y][now.x] = true;
		int booms = 0;
		tmp.clear();
		if (map[now.y][now.x] == 'M')
			continue;
		for (int i = 0; i < 8; i++)
		{
			int ny = now.y + dy[i];
 			int nx = now.x + dx[i];
			if (ny < 0 || nx < 0 || ny >= n || nx >= m)
				continue;
			if (map[ny][nx] == 'B')
				continue;
			if (map[ny][nx] == 'M')
			{
				booms++;
				continue;
			}
			if (visited[ny][nx])
				continue;
			tmp.push_back({ ny, nx });
		}
		if (booms == 0)
		{
			map[now.y][now.x] = 'B';
			for (int i = 0; i < tmp.size(); i++)
				q.push(tmp[i]);
		}
		else
			map[now.y][now.x] = booms + '0';
	}
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> map[i];
	cin >> y >> x;

	if (map[y][x] == 'M')
		map[y][x] = 'X';
	else
		bfs(y, x);

	for (int i = 0; i < n; i++)
		cout << map[i] << "\n";
	return 0;
}