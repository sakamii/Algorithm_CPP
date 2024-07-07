#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
/*
첫 풀이 : 순열 + bfs => 순열으로 먼저 방문할 먼지덩어리 순서를 정하고, 다 정했으면 bfs로 탐색
=> bfs의 중복 연산으로 인한 시간초과

두번째 풀이 : bfs 메모이제이션 + 순열
=> 매번 순열을 돌리면서 bfs를하는건 중복연산 -> 메모이제이션으로 해결해보자 -> AC
*/
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};

struct item{
    int y,x;
};
int n,m;
int sy,sx;

vector<item> v;
vector<int> itemLst;
int itemVisited[12];
char map[21][21];
int visited[21][21];
int result;
int dist[12][12];

void func(int cnt){
    if(cnt == v.size()-1){
        int length = dist[cnt][itemLst[0]];
        //cout << cnt << " " << itemLst[0] << "\n";
        for(int i=0; i<cnt-1; i++){
            int fidx = itemLst[i];
            int sidx = itemLst[i+1];
            length += dist[fidx][sidx];
            //cout << itemLst[i] << " " << itemLst[i+1] << "\n";
        }
        //cout << "-------------" << endl;
        result = min(result,length);
        return ;
    }

    for(int i=0; i<v.size()-1; i++){
        if(itemVisited[i] != 0) continue;
        itemVisited[i] = 1;
        itemLst.push_back(i);
        func(cnt+1);
        itemLst.pop_back();
        itemVisited[i] = 0;
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    while(true){
        cin >> m >> n;
        if(m == 0 && n == 0) break;
        memset(itemVisited,0,sizeof(itemVisited));
        memset(dist,0,sizeof(dist));
        v.clear();
        itemLst.clear();
        result = 99999999;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin >> map[i][j];
                if(map[i][j] == 'o'){
                    sy = i;
                    sx = j;
                }
                if(map[i][j] == '*'){
                    v.push_back({i,j});
                }
            }
        }
        v.push_back({sy,sx});
        int exit_flag = 0;
        for(int t=0; t<v.size(); t++){
            for(int tt=0; tt<v.size(); tt++){
                memset(visited,0,sizeof(visited));
                if(dist[t][tt] != 0){
                    continue;
                }
                int y1 = v[t].y;
                int x1 = v[t].x;
                int y2 = v[tt].y;
                int x2 = v[tt].x;
                visited[y1][x1] = 1;
                queue<pair<int,int>> q;
                q.push({y1,x1});
                while(!q.empty()){
                    int cy = q.front().first;
                    int cx = q.front().second;
                    q.pop();

                    if(cy == y2 && cx == x2){
                        dist[t][tt] = visited[cy][cx] - 1;
                        dist[tt][t] = visited[cy][cx] -  1;
                        break;
                    }

                    for(int i=0; i<4; i++){
                        int ny = cy + dy[i];
                        int nx = cx + dx[i];

                        if(ny < 0 || ny >= n || nx >= m || nx < 0) continue;
                        if(visited[ny][nx] != 0) continue;
                        if(map[ny][nx] == 'x') continue;
                        visited[ny][nx] = visited[cy][cx] + 1;
                        q.push({ny,nx});
                    }
                }
                //cout << t << " " << tt << endl;
                //cout << dist[t][tt] << endl;
                if(dist[t][tt] == 0 && t != tt) exit_flag = 1;
                if(exit_flag) break;
            }
            if(exit_flag) break;
        }
        if(exit_flag){
            cout << -1 << "\n";
            continue;
        }
        func(0);
        cout << result << "\n";
    }
    return 0;
}