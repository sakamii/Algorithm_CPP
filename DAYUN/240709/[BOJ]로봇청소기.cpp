// https://www.acmicpc.net/problem/4991

// 모든 경우의 길찾기 
// A-> B가는 경우 


#include <queue>
#include <string.h>
#include <iostream>

using namespace std;

int w;
int h;
int numDirty;
int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {0, -1}};
int dist[10][10];
int startDist[10];
char room[20][20];
bool visited[20][20];
pair<int,int> dirty[10];
priority_queue<pair<int, int>> pq;


//return Robot start posion
pair<int, int> init();
void find(pair<int, int>);


int main() {
    while(true) {
        int result = 0;
        pair<int, int> start = init();
        if(w == 0) break;
        
        find(start);

        while(!pq.empty()) {
            int cost = -pq.top().first;
            pair<int, int> nextPosition = dirty[pq.top().second];
            char nextDirtyPlayNum = room[nextPosition.first][nextPosition.second];
            room[nextPosition.first][nextPosition.second] = '/';
            pq.pop();

            if(nextDirtyPlayNum == '/' ) continue;
            result += cost;
            cout << cost << " ";
            find(nextPosition);
            cout << ",";
        }   

        cout << result << endl;
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
    //start BFS
    while(!q.empty()) {
        pair<int, int> now = q.top().second;
        int cost = -q.top().first + 1;
        for(int i = 0; i < 4; ++i) {
            pair<int, int> next = {now.first + dir[i][0], now.second + dir[i][0]};
            if(next.first < 0 || next.first >= h || next.second < 0 || next.second >= w) continue;
            if(visited[next.first][next.second]) continue;
            if(room[next.first][next.second] == 'x') continue;
            if(room[next.first][next.second] >= 0 && room[next.first][next.second] <= 9 ) {
                startDist[room[next.first][next.second]] = cost;
            }
            q.push({-cost, next});
        } 
    }

    //next dirty place
    for(int dp = 0; dp <)
    
    visited[p.first][p.second] = true;
    priority_queue<pair<int, pair<int, int>>> q;
    q.push({0, p});
    while(!q.empty()) {
        pair<int, int> now = q.top().second;
        int cost = -q.top().first + 1;
        cout << cost;
        q.pop();
        for(int i = 0; i < 4; i++){
            pair<int , int> next = {now.first + dir[i][0], now.second + dir[i][1]};
            if(next.first < 0 || next.second < 0 || next.first >= h || next.second >= w) continue;
            if(visited[next.first][next.second]) continue;
            if(room[next.first][next.second] == '/') continue;    
            if(room[next.first][next.second] == 'x') continue;    
                pq.push({-cost, (int)(room[next.first][next.second] - '0')});
                continue;
            }
            visited[next.first][next.second] = true;
            q.push({-cost, next});
        }
    }
}




// 다음 후보 https://www.acmicpc.net/problem/14500 (쌉구현)
// https://www.acmicpc.net/problem/1429
