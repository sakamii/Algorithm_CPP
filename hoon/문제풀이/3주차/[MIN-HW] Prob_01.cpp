#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
#define INF 20000001

/*
저작권 -> 문제 비공개
bfs를 방향까지 고려한 3차원 배열로 완전탐색
우측 회전만 가능하므로, 방향 회전은 한가지 방향만 고려하면 됨.
*/
int map[11][11];
int visited[4][11][11];
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};
int n;
int direc[] = {0,1,2,3};

struct robot{
    int direct;
    int y;
    int x;
    int cnt;
};
robot bfs(int drec, int sy, int sx, int ey, int ex){
    for(int z=0; z<4; z++){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                visited[z][i][j] = 0;
            }
        }
    }
    visited[drec][sy][sx] = 1;
    queue<robot> q;
    q.push({drec,sy,sx,0});
    while(!q.empty()){
        int current_y = q.front().y;
        int current_x = q.front().x;
        int current_direct = q.front().direct;
        int current_cnt = q.front().cnt;
        if(current_y == ey && current_x == ex){
            return q.front();
        }
        q.pop();
        int next_direct[2] = {current_direct,(current_direct+1)%4};
        for(int i=0; i<2; i++){
            int next_y = current_y + dy[next_direct[i]];
            int next_x = current_x + dx[next_direct[i]];
            if(next_y < 0 || next_y >= n || next_x < 0 || next_x >=n) continue;
            if(visited[next_direct[i]][next_y][next_x] == 1) continue;
            visited[next_direct[i]][next_y][next_x] = 1;
            if(next_direct[i] == current_direct) q.push({next_direct[i],next_y,next_x,current_cnt});
            else q.push({next_direct[i],next_y,next_x,current_cnt+1});
        }
    }

}

int main() {
    int t;
    cin >> t;
    for(int i=1; i<=t; i++){
        cin >> n;
        priority_queue<pair<int,pair<int,int>>> pq;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cin >> map[i][j];
                if(map[i][j] != 0){
                    pq.push({-map[i][j],{i,j}});
                }
            }
        }
        int start_y = 0;
        int start_x = 0;
        int start_direct = 0;
        int cnt = 0;
        while(!pq.empty()){
            int end_y = pq.top().second.first;
            int end_x = pq.top().second.second;
            pq.pop();

            robot temp = bfs(start_direct, start_y, start_x, end_y, end_x);
            cnt += temp.cnt;
            start_direct = temp.direct;
            start_y = temp.y;
            start_x = temp.x;
        }
        cout << "#"<< i << " "<< cnt << endl;


    }
}