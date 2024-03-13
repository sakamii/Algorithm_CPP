#include<iostream>
#include<vector>
using namespace std;

/*
  n의 크기가 크지 않고 경우의 수를 찾는 문제이기 때문에
  dfs로 탐색하면서 가지치기를 잘한다면 해결 할 수있다고 생각
*/

struct node{
    int y;
    int x;
};

vector<node> v;
int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
int visited[5][5];
int pass[5][5];
int map[5][5];
int N, M;
int cnt;
int ans;

// level은 방문지를 찾은 횟수
void dfs(int y, int x, int level){
    if(level>=M) {
        ans++;
        return;
    }
    // next는 다음으로 방문해야 하는 노드
    node next = {v[level].y, v[level].x};
        
    for(int i=0; i<4;i++){
        int flag = 0;
        int dy = y + dir[i][0];
        int dx = x + dir[i][1];
        if(dy > N || dx > N || dy<=0||dx<=0) continue;
        if(visited[dy][dx]) continue;
        if(map[dy][dx]) continue;
        // 방문해야 하는 노드 이면서 다음으로 방문해야 하는 노드임을 확인하는 부분
        // 방문해야 하는 노드인데 다음 노드가 아니라면 의미 x
        if(pass[dy][dx]){
            if(next.y == dy && next.x == dx) {
                level++;
                flag = 1;
                }
            else continue;
        }
        visited[dy][dx] = 1;
        dfs(dy, dx, level);
        visited[dy][dx] = 0;
        if(flag) level--;
    }
}

int main(){

    cin >> N >> M;

    for(int i=1; i<=N;i++){
        for(int j=1; j<=N;j++){
            cin >> map[i][j];
        }
    }

    for(int i=0; i<M;i++){
        int y, x;
        cin >> y >> x;
        v.push_back({y,x});
        // 방문이 필요한 노드임을 표시
        pass[y][x] = 1;
    }

    dfs(v[0].y, v[0].x, 1);

    cout << ans;

    
   return 0;
}
