#include <iostream>
#include <queue>

using namespace std;

int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

int map[500][500];
int route[500][500];
priority_queue<pair<int, pair<int, int>>> pq;


int main(){
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> map[i][j]; 
            pq.push({map[i][j], {i, j}});
        }
    }

    route[0][0] = 1;
    while(!pq.empty()){
        int y = pq.top().second.first;
        int x = pq.top().second.second;
        pq.pop();
        for(int i = 0; i < 4; i++) {
            int nextY = y + dy[i];            
            int nextX = x + dx[i];
            if(nextY >= 0 && nextY < n && nextX >= 0 &&  nextX < m)
            {
                if(map[y][x] < map[nextY][nextX]) {
                    route[y][x] += route[nextY][nextX];
                }
            }

        }
    }

    cout << route[n - 1][m - 1];


}