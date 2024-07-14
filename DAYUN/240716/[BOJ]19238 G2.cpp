#include <iostream>
#include <queue>
#include <cstring>
#include <vector>

using namespace std;

int map[30][30];
int N, M, fuel;
int guest[420][4];
bool visited[30][30];
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
pair<int, int> driverP;

int findNextGuest();
void calDist(int guestNum);

int main(){
    cin >> N;
    cin >> M;
    cin >> fuel;
    for(int i = 1; i <= N; ++i) {
        for(int j = 1; j <= N; ++j) {
            cin >> map[i][j];
        }
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
    int row = 30;
    int col = 30;

    memset(visited, false, sizeof(visited));
    queue<pair<int, pair<int, int> > > position;
    pair<int, pair<int, int> > p;
    p.first = 0;
    p.second = driverP;
    position.push(p);

    if(map[driverP.first][driverP.second] != 0) {
        ret = map[driverP.first][driverP.second] - 2;
        map[driverP.first][driverP.second] = 0;
        return ret;
    }

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
                if(row > nextY) {
                    ret = map[nextY][nextX] - 2;
                    col = nextX;
                    row = nextY;
                    d = dist;
                } 
                else if(row == nextY) {
                    if(col > nextX) {
                        ret = map[nextY][nextX] - 2;
                        col = nextX;
                        row = nextY;
                        d = dist;
                    }
                }
            }
            else {
                pair<int, pair<int, int> > temp;
                temp.first = dist;
                temp.second.first = nextY;
                temp.second.second = nextX;
                position.push(temp);
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
    queue<pair<int, pair<int, int> > > position;

    pair<int, pair<int, int> > p;
    p.first = 0;
    p.second.first = guest[num][0];
    p.second.second = guest[num][1];
    position.push(p);

    if(goalY == guest[num][0] && goalX == guest[num][1]) {
        return;
    }


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
            else {
                pair<int, pair<int, int> > temp;
                temp.first = dist;
                temp.second.first = nextY;
                temp.second.second = nextX;
                position.push(temp);
            }

        }
    }

    
    if(ret == -1) {
        fuel = -1;
    }
    else fuel += ret;
}