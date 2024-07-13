// https://www.acmicpc.net/problem/4991

// 모든 경우의 길찾기 
// A-> B가는 경우 


#include <queue>
#include <vector>
#include <string.h>
#include <iostream>

using namespace std;

int w;
int h;
int ret;
int numDirty;
int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int dist[10][10];
int startDist[10];
char room[20][20];
bool visited[20][20];
bool visitedSpot[10];
pair<int,int> dirty[10];
priority_queue<pair<int, int>> pq;


//return Robot start posion
pair<int, int> init();
void find(pair<int, int>);
void dfs(int restDirty, int startPoint, int cost);

int main() {
    while(true) {
        ret = 4000000;
        
        pair<int, int> start = init();
        if(w == 0) break;
        fill(startDist, startDist + numDirty, ret);
        fill(&dist[0][0], &dist[0][0] + (numDirty * 10), ret);
        find(start);

        for(int dp = 0; dp < numDirty; ++dp) {
            visitedSpot[dp] = true;
            dfs(numDirty - 1, dp, startDist[dp]);
            visitedSpot[dp] = false;
        }

        if(ret >= 400000) ret = -1;

        cout << ret << "\n";

    }
}

pair<int, int> init() {
    pair<int, int> ret;

    cin >> w >> h;
    numDirty = 0;
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            cin >> room[i][j];
            if(room[i][j] == 'o')  {
                ret = {i, j};
            }
            if(room[i][j] == '*')  {
                dirty[numDirty] = {i, j};
                room[i][j] = numDirty++ ;
            }
        }
    }

    return ret;
}

void find(pair<int, int> start){
    memset(visited, false, sizeof(visited));
    priority_queue<pair<int, pair<int, int>>> q;
    visited[start.first][start.second] = true;
    q.push({0, start});
    while(!q.empty()) {
        pair<int, int> now = q.top().second;
        int cost = -q.top().first + 1;
        q.pop();

        for(int i = 0; i < 4; ++i) {
            pair<int, int> next = {now.first + dir[i][0], now.second + dir[i][1]};
            if(next.first < 0 || next.first >= h || next.second < 0 || next.second >= w) continue;
            if(visited[next.first][next.second]) continue;
            if(room[next.first][next.second] == 'x') continue;
            if(room[next.first][next.second] >= 0 && room[next.first][next.second] <= 9 ) {
                startDist[room[next.first][next.second]] = cost;
            }
            visited[next.first][next.second] = true;
            q.push({-cost, next});
        } 
    }

    //next dirty place
    for(int dp = 0; dp < numDirty; dp++) {
        memset(visited, false, sizeof(visited));
        visited[dirty[dp].first][dirty[dp].second] = true;
        q.push({0, dirty[dp]});
        while(!q.empty()) {
            pair<int, int> now = q.top().second;
            int cost = -q.top().first + 1;
            q.pop();
            for(int i = 0; i < 4; ++i) {
                pair<int, int> next = {now.first + dir[i][0], now.second + dir[i][1]};
                if(next.first < 0 || next.first >= h || next.second < 0 || next.second >= w) continue;
                if(visited[next.first][next.second]) continue;
                if(room[next.first][next.second] == 'x') continue;
                if(room[next.first][next.second] >= 0 && room[next.first][next.second] <= 9 ) {
                    dist[dp][room[next.first][next.second]] = cost;
                    dist[room[next.first][next.second]][dp] = cost;
                }
                visited[next.first][next.second] = true;
                q.push({-cost, next});
            } 
        }
        room[dirty[dp].first][dirty[dp].second] = 'x';
    }
}

void dfs(int restDirty, int startPoint, int cost) {
    if(restDirty == 0 ) {
        ret = ret < cost ? ret : cost;
        return;
    }
    if(ret <= cost) {
        return;
    }

    for(int i = 0; i < numDirty; ++i) {
        if(visitedSpot[i]) continue;
        visitedSpot[i] = true;
        dfs(restDirty - 1, i, cost + dist[startPoint][i]);
        visitedSpot[i] = false;
    }
}

