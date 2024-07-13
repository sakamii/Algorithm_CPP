#include <iostream>
#include <queue>
#include <cstring>
#include <vector>

using namespace std;

int map[20][20];
int N, M, fuel;
vector<pair<pair<int, int>, int > > guestDist;
bool visited[20][20];
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int calDist(pair<int, int>, pair<int, int>);

int main(){
    cin >> N >> M >> fuel;
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
            cin >> map[i][j];
        }
    }

    pair<int, int> driver;
    cin >> driver.first >> driver.second;
    
    guestDist.resize(M);
    for(int i = 0; i < M; ++i) {
        pair<int, int> start;
        pair<int, int> end;
        cin >> start.first >> start.second >> end.first >> end.second;
        map[start.first][start.second] = i + 2;
        guestDist[i].first = end;
        guestDist[i].second = calDist(start, end);
        if(guestDist[i].second == -1) {
            cout << -1 << "\n";
            return 0;
        }
    }

    


}

int calDist(pair<int, int> start, pair<int, int> end){
    memset(visited, false, sizeof(visited));
    priority_queue<pair<int, pair<int, int> > > pq;

    pair<int, pair<int, int> > p;
    p.first = 0;
    p.second = start;
    pq.push(p);
  
    visited[start.first][start.second] = true;

    while(!pq.empty()) {
        int y = pq.top().second.first;
        int x = pq.top().second.second;
        int dist = pq.top().first - 1;
        
        for(int i = 0; i < 4; ++i) {
            int nextY = y + dir[i][0];
            int nextX = x + dir[i][1];

            if(nextY < 0  || nextY >= N || nextX < 0 || nextX >= N) continue;
            if(visited[nextY][nextX]) continue;
            if(map[nextY][nextX] == 1) continue;
            if(nextY == end.first && nextY == end.second) {
                return -dist;
            }
            pq.push({dist, {nextY, nextX}});
            visited[nextY][nextX] = true;
        }
    }
    
    return -1;
}


