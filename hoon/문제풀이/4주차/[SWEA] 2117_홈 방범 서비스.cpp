#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <math.h>
using namespace std;
int t,n,m;
int map[21][21];
int answer;
int dy[] = {0,0,1,-1};
int dx[] = {1,-1,0,0};
int visited[21][21];

/*
모든 지점 k만큼 bfs 탐색 -> 시간초과
홈 방범 서비스의 모양이 bfs 탐색의 모양으로 늘어나는것  확인 가능
=> level별로 bfs를 진행해주면 되겠구나

BFS 특성상 레벨별로 queue에 들어가게 되니, 각 queue size만큼 돌려주면서 k를 늘려주고, max 갱신.

*/
void bfs(int sy,int sx){
	queue<pair<int,int>> q;
	q.push({sy,sx});
	visited[sy][sx] = 1;
	int cnt = 0;
	if(map[sy][sx] == 1) cnt = 1;
	int k = 1;
	while(!q.empty()){
		if(k > n + 1) break;
		if(m*cnt - (k*k + (k-1)*(k-1)) >= 0) answer = max(answer,cnt);
		int size = q.size();

		for(int i=0; i<size; i++){
			int cy = q.front().first;
			int cx = q.front().second;
			q.pop();
			for(int j=0; j<4; j++){
				int ny = cy + dy[j];
				int nx = cx + dx[j];
				if(ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
				if(visited[ny][nx] == 1) continue;
				visited[ny][nx] = 1;
				q.push({ny,nx});
				if(map[ny][nx] == 1) cnt++;
			}
		}
		k++;
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> t;
	for(int test_case = 1; test_case<=t; test_case++){
		cin >> n >> m;
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				cin >> map[i][j];
			}
		}
		answer = 0;
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				memset(visited,0,sizeof(visited));
				bfs(i,j);
			}
		}

		cout << "#" << test_case <<" " << answer << endl;
	}
}