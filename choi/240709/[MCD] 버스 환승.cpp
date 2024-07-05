#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

struct BusInfo
{
	int busNum;
	int sy, sx;
	int ey, ex;
};

struct Node
{
	int busNum;
	int y, x;
}start, dest;

struct Person
{
	int busNum, transfer;
	int y, x;
};

int m, n, k;
int minTransfer = 2134567890;
vector<BusInfo> buses;
vector<Node> connection[5001];
bool destBus[5001];

void bfs(int num)
{
	queue<Person> q;
	q.push({ num, 1, start.y, start.x });
	bool visited[5001];
	memset(visited, 0, sizeof(visited));
	visited[num] = true;
	while (!q.empty())
	{
		Person now = q.front();
		q.pop();
		if (destBus[now.busNum])
		{
			minTransfer = min(minTransfer, now.transfer);
			break;
		}
		for (int i = 0; i < connection[now.busNum].size(); i++)
		{
			Node nextBus = connection[now.busNum][i];
			if (visited[nextBus.busNum])
				continue;
			visited[nextBus.busNum] = true;
			q.push({ nextBus.busNum, now.transfer + 1, nextBus.y, nextBus.x });
		}
	}
}

int main()
{
	cin >> m >> n;
	cin >> k;
	for (int i = 0; i < k; i++)
	{
		int b, x1, y1, x2, y2;
		cin >> b >> x1 >> y1 >> x2 >> y2;
		buses.push_back({ b, y1, x1, y2, x2 });
	}
	cin >> start.x >> start.y >> dest.x >> dest.y;

	// 연결된 버스 노선 찾기
	for (int i = 0; i < k - 1; i++)
	{
		BusInfo now = buses[i];
		for (int j = i + 1; j < k; j++)
		{
			BusInfo target = buses[j];
			if ((target.sy == target.ey) && (now.sy <= target.sy && target.sy <= now.ey))
			{
				if (target.sx <= now.sx && now.sx <= target.ex)
				{
					connection[now.busNum].push_back({ target.busNum, target.sy, now.sx });
					connection[target.busNum].push_back({ now.busNum, now.sy, now.sx });
				}
				else if (target.sx <= now.ex && now.ex <= target.ex)
				{
					connection[now.busNum].push_back({ target.busNum, target.sy, now.ex });
					connection[target.busNum].push_back({ now.busNum, now.sy, now.ex });
				}
			}
			else if ((target.sx == target.ex) && (now.sx <= target.sx && target.sx <= now.ex))
			{
				if (target.sy <= now.sy && now.sy <= target.ey)
				{
					connection[now.busNum].push_back({ target.busNum, now.sy, target.sx });
					connection[target.busNum].push_back({ now.busNum, now.sy, now.sx });
				}
				else if (target.sy <= now.ey && now.ey <= target.ey)
				{
					connection[now.busNum].push_back({ target.busNum, now.ey, target.sx });
					connection[target.busNum].push_back({ now.busNum, now.ey, now.sx });
				}
			}
		}
	}

	// 목적지와 연결된 버스 찾기
	for (int i = 0; i < k; i++)
	{
		BusInfo now = buses[i];
		if ((now.sx == dest.x && now.sy <= dest.y && dest.y <= now.ey) || (now.sy == dest.y && now.sx <= dest.x && dest.x <= now.ex))
			destBus[now.busNum] = true;
	}
	
	for (int i = 0; i < k; i++)
	{
		BusInfo now = buses[i];
		if (now.sy == now.ey && now.sy == start.y && now.sx <= start.x && start.x <= now.ex)
			bfs(now.busNum);
		else if (now.sx == now.ex && now.sx == start.x && now.sy <= start.y && start.y <= now.ey)
			bfs(now.busNum);
	}
	cout << minTransfer;
	return 0;
}