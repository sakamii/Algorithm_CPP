// https://www.acmicpc.net/problem/4991

#include <queue>
#include <string.h>
#include <iostream>

using namespace std;

int w;
int h;
int numCleaned;
pair<int,int> cleaned[10];
char room[20][20];
bool visited[20][20];
priority_queue<pair<int, int>> pq;
int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {0, -1}};


//return Robot start posion
pair<int, int> init();
void find(pair<int, int>);


int main() {
    while(true) {
        int result = 0;
        pair<int, int> start = init();
        if(w == 0) break;
        
        //find next node dist (start Node) -> input prioiryty queue
        find(start);

        while(!pq.empty()) {
            int cost = -pq.top().first;
            pair<int, int> nextPosition = cleaned[pq.top().second];
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
    int roomNum = 0;
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            cin >> room[i][j];
            if(room[i][j] == 'o')  {
                ret = {i, j};
                room[i][j] = '/';
            }
            if(room[i][j] == '*')  {
                cleaned[roomNum] = {i, j};
                room[i][j] = '0' + roomNum++ ;
            }
        }
    }

    return ret;
}

void find(pair<int, int> p){
    memset(visited, false, sizeof(visited));

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
            if(room[next.first][next.second] >= '0' && room[next.first][next.second] <= '9' ) {
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
