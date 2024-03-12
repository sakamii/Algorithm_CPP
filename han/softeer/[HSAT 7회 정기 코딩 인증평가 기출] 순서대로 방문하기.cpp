#include <iostream>
#include <vector>

using namespace std;

int N, M, answer;
vector<vector<int>> MAP;
vector<vector<bool>> visited;
vector<pair<int, int>> vect;

int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};

void DFS(int y, int x, int level) {
    if(level == M) {
        answer++;
        return;
    }

    for(int i = 0; i < 4; i++) {
        int newY = y + dy[i];
        int newX = x + dx[i];

        if(newY < 0 || newY >= N || newX < 0 || newX >= N
            || visited[newY][newX] || MAP[newY][newX] == 1) continue;
        
        visited[newY][newX] = true;
        DFS(newY, newX, (vect[level].first == newY && vect[level].second == newX ? level + 1 : level));
        visited[newY][newX] = false;
    }
}

int main(int argc, char** argv) {
    cin >> N >> M;
    MAP.resize(N, vector<int>(N));
    visited.resize(N, vector<bool>(N, false));
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> MAP[i][j];
        }
    }
    for(int i = 1; i <= M; i++) {
        int y, x;
        cin >> y >> x;
        vect.push_back(make_pair(y - 1, x - 1));
    }

    visited[vect[0].first][vect[0].second] = true;
    DFS(vect[0].first, vect[0].second, 1);
    cout << answer;
    return 0;
}