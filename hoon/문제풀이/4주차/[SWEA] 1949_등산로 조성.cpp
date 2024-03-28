#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int t;
int n,k;
int map[9][9];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int visited[9][9];
int answer = 0;
/*
dfs를 통해 풀이함.
문제조건에서 모든 조건을 가지치기로 풀어야 함을 알고, BFS 대신 DFS로 풀이했음.
공사 가능한 부분은 한부분밖에 주어지지 않으므로
dfs의 매개변수로 flag를 주어, 공사를 진행한 재귀 반복문에서는 더이상 공사를 진행하지 않도록 설계
그 이외에는 그냥 dfs와 동일.
*/
void dfs(int y, int x, int height,int cnt, int flag){
	answer = max(answer,cnt);
	for(int i=0; i<4; i++){
		int next_x = x + dx[i];
		int next_y = y + dy[i];
		if(next_x < 0 || next_y < 0 || next_x >= n || next_y >= n) continue;
		if(visited[next_y][next_x] == 1) continue;
		visited[next_y][next_x] = 1;
		if(map[next_y][next_x] < height){
			dfs(next_y,next_x,map[next_y][next_x], cnt+1, flag);
		}
		else{
			int temp = map[next_y][next_x];
			if(flag == 0){
			for(int j=0; j<k; j++){
				temp -= 1;
				if(temp < height){
					dfs(next_y,next_x,temp,cnt+1, !flag);
				}
			}
			}
		}
		visited[next_y][next_x] = 0;
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> t;
	for(int test_case = 1; test_case<=t; test_case++){
		
		cin >> n >>k;
		int highest = 0;
		answer = 0;
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				cin >> map[i][j];
				visited[i][j] = 0;
				highest = max(highest,map[i][j]);
			}
		}

		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				if(map[i][j] == highest){
					visited[i][j] = 1;
					dfs(i,j,map[i][j],1,0);
					visited[i][j] = 0;
				}
			}
		}

		cout << "#" << test_case <<" " << answer << endl;
	}
}