#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, robotA, robotB;
long long int minPath = 2134567890;
bool visited[100001];

struct Node
{
	int roomNum, pathLen;

	bool operator<(Node a) const
	{
		if (pathLen < a.pathLen)
			return true;
		if (pathLen > a.pathLen)
			return false;
		return false;
	}
};

vector<Node> connection[100001];

void dfs(long long int pathLength, int roomNum, long long int maxPath)
{
	if (roomNum == robotB)
	{
		minPath = min(minPath, pathLength - maxPath);
		return;
	}
	for (int i = 0; i < connection[roomNum].size(); i++)
	{
		Node nowRoom = connection[roomNum][i];
		if (visited[nowRoom.roomNum])
			continue;
		visited[nowRoom.roomNum] = true;
		dfs(pathLength + nowRoom.pathLen, nowRoom.roomNum, max(maxPath, (long long int)nowRoom.pathLen));
	}
}

int main()
{
	cin >> n >> robotA >> robotB;
	for (int i = 0; i < n - 1; i++)
	{
		int a, b, path;
		cin >> a >> b >> path;
		connection[a].push_back({ b, path });
		connection[b].push_back({ a, path });
	}

	dfs(0, robotA, 0);
	cout << minPath;
	return 0;
}