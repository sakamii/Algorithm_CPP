#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

const int UP = 0, RIGHT = 1, DOWN = 2, LEFT = 3;

int N, T, answer = 1;
vector<pair<int, int>> MAP[100][100];
bool DAT[100][100];

// 상 : 0, 우(->) : 1, 하 : 2, 좌(<-) : 3

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

// 들어가는 방향, T0, T1, T2, T3
vector<int> sig[3][5] = {
    // RIGHT, UP, LEFT, DOWN 
    {{0}, {UP, RIGHT, DOWN}, {LEFT, UP, RIGHT}, {UP, LEFT, DOWN}, {LEFT, DOWN, RIGHT}},
    {{0}, {RIGHT, UP}, {LEFT, UP}, {LEFT, DOWN}, {DOWN, RIGHT}},
    {{0}, {RIGHT, DOWN}, {UP, RIGHT}, {UP, LEFT}, {DOWN, LEFT}},
};

bool isPossible(int X, int D) {
    if(X == 1) return D == RIGHT;
    else if(X == 2) return D == UP;
    else if(X == 3) return D == LEFT;
    else return D == DOWN;
}

void DFS(int level, int y, int x, int D) {
    if(level == T) return;
    int sigY, sigX;
    tie(sigY, sigX) = MAP[y][x][level % 4];
    if(!isPossible(sigX, D)) return;
    for(int i = 0; i < sig[sigY][sigX].size(); i++) {
        int dir = sig[sigY][sigX][i];
        int newY = y + dy[dir];
        int newX = x + dx[dir];
        if(newY < 0 || newY >= N || newX < 0 || newX >= N) continue;
        if(!DAT[newY][newX]) {
            answer++;
            DAT[newY][newX] = true;
        }
        DFS(level + 1, newY, newX, dir);
    }
}

int main(int argc, char** argv) {
    cin >> N >> T;
    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            for(int k = 0; k < 4; k++) {
                int x;
                cin >> x;
                int sigY = (x > 8 ? 2 : x > 4 ? 1 : 0);
                int sigX = (x > 8 ? x - 8 : x > 4 ? x - 4 : x);
                MAP[i][j].push_back({sigY, sigX});
            }
        }
    }
    DAT[0][0] = true;
    DFS(0, 0, 0, UP);
    cout << answer;
    return 0;
}