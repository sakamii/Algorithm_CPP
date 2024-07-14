#include <iostream>
#include <queue>
#include <cstring>
#include <vector>

using namespace std;

int map[20][20];
int N, M, fuel;
int guest[400][4];
bool visited[21][21];
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
pair<int, int> driverP;

int findNextGuest();
void calDist(int guestNum);

int main(){
    int result = 0;

    cin >> N;
    cin >> M;
    cin >> fuel;
    for(int i = 1; i <= N; ++i) {
        for(int j = 1; j <= N; ++j) {
            cin >> map[i][j];
        }
        cout << endl;
    }

    cin >> driverP.first >> driverP.second;
    for(int i = 0; i < M; ++i) {
        cin >> guest[i][0] >> guest[i][1] >> guest[i][2] >> guest[i][3];
        map[guest[i][0]][guest[i][1]] = i + 2;
    }

    while(fuel >= 0 && M > 0) {
        int guestNum = findNextGuest();
        calDist(guestNum);
        driverP.first = guest[guestNum][2];
        driverP.second = guest[guestNum][3];
        M--;
    }

    if(fuel < 0) cout << -1;
    else cout << fuel;
}

int findNextGuest(){
    int ret = 500;
    int d = fuel + 1;

    memset(visited, false, sizeof(visited));
    queue<pair<int, pair<int, int>>> position;
    position.push({0, driverP});

    while(!position.empty()) {
        int dist = position.front().first + 1;
        int y = position.front().second.first;
        int x = position.front().second.second;
        position.pop();
        if(dist > d) break;
        
        for(int i = 0; i < 4; ++i) {
            int nextY = y + dir[i][0]; 
            int nextX = x + dir[i][1];

            if(nextY > N || nextY <= 0 || nextX > N || nextX <= 0) continue;
            if(map[nextY][nextX] == 1) continue;
            if(visited[nextY][nextX]) continue;
            visited[nextY][nextX] = true;
            if (map[nextY][nextX] != 0) {
                if(ret > (map[nextY][nextX] - 2)) {
                    ret = map[nextY][nextX] - 2;
                    d = dist;
                } 
            }
            else {
                position.push({dist, {nextY, nextX}});

            }
        }
    }

    fuel -= d;
    map[guest[ret][0]][guest[ret][1]] = 0;
    return ret;

        
}

void calDist(int num){
    int ret = -1;
    int goalY = guest[num][2];
    int goalX = guest[num][3];

    memset(visited, false, sizeof(visited));
    queue<pair<int, pair<int, int>>> position;
    position.push({0, {guest[num][0], guest[num][1]}});

    while(!position.empty()) {
        int dist = position.front().first + 1;
        int y = position.front().second.first;
        int x = position.front().second.second;
        position.pop();
        if(fuel < dist) break;
        
        for(int i = 0; i < 4; ++i) {
            int nextY = y + dir[i][0]; 
            int nextX = x + dir[i][1];

            if(nextY > N || nextY <= 0 || nextX > N || nextX <= 0) continue;
            if(map[nextY][nextX] == 1) continue;
            if(visited[nextY][nextX]) continue;
            visited[nextY][nextX] = true;
            if(goalY == nextY && goalX == nextX) {
                ret = dist;
                break;
            }
        }
    }

    if(ret == 0) fuel = -1;
    else fuel += ret;
}