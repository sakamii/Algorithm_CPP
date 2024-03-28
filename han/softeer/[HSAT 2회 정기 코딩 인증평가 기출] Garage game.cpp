#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <tuple>
#include <limits.h>

using namespace std;

int N, score, answer;

int dy[4] = { 1, 0, -1, 0 };
int dx[4] = { 0, 1, 0, -1 };

int getScore(vector<vector<int>> garage) {
    int maxY = 0, maxX = 0, minY = INT_MAX, minX = INT_MAX, y, x, cnt = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            y = N * 2 + i;
            x = j;
            if (garage[y][x] == 0) {
                cnt++;
                maxY = max(maxY, y);
                maxX = max(maxX, x);
                minY = min(minY, y);
                minX = min(minX, x);
            }
        }
    }

    return (maxY - minY + 1) * (maxX - minX + 1) + cnt;
}

void pushDown(vector<vector<int>> &garage) {
    queue<int> q;

    for (int j = 0; j < N; j++) {
        for (int i = N * 3 - 1; i >= 0; i--) {
            if (garage[i][j] == 0) continue;
            q.push(garage[i][j]);
        }
        for (int i = N * 3 - 1; i >= 0; i--) {
            if (q.empty()) garage[i][j] = 0;
            else {
                garage[i][j] = q.front();
                q.pop();
            }

        }
    }
}

vector<vector<int>> getGarageAfterPop(vector<vector<int>> garage, int y, int x, vector<vector<bool>> &visited, int level) {
    int target = garage[y][x];
    int maxY = y, maxX = x, minY = y, minX = x, cnt = 1;

    queue<pair<int, int>> q;
    q.push(make_pair(y, x));
    garage[y][x] = 0;
    visited[y][x] = true;

    while (!q.empty()) {
        int nowY, nowX;
        tie(nowY, nowX) = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int newY = nowY + dy[i];
            int newX = nowX + dx[i];
            if (newY < N * 2 || newY >= N * 3 || newX < 0 || newX >= N || garage[newY][newX] != target) continue;
            garage[newY][newX] = 0;
            visited[newY][newX] = true;
            cnt++;
            maxY = max(maxY, newY);
            maxX = max(maxX, newX);
            minY = min(minY, newY);
            minX = min(minX, newX);
            q.push(make_pair(newY, newX));
        }
    }
    score = (maxY - minY + 1) * (maxX - minX + 1) + cnt;
    if(level < 2) pushDown(garage);
    return garage;
}

void printGarage(vector<vector<int>> garage) {
    for(int i = 0; i < N * 3; i++) {
        for(int j = 0; j < N; j++) {
            cout << garage[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

void simulate(int level, vector<vector<int>> garage, int result) {
    if((3 - level) * N * N * 2 + result < answer) return;

    vector<vector<bool>> visited;
    visited.resize(N * 3, vector<bool>(N, false));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int y = N * 2 + i;
            int x = j;
            int target = garage[y][x];
            if (target == 0) continue;
            if (visited[y][x]) continue;
            if(level >= 2) {
                int target = garage[y][x];
    int maxY = y, maxX = x, minY = y, minX = x, cnt = 1;

    queue<pair<int, int>> q;
    q.push(make_pair(y, x));
    garage[y][x] = 0;
    visited[y][x] = true;

    while (!q.empty()) {
        int nowY, nowX;
        tie(nowY, nowX) = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int newY = nowY + dy[i];
            int newX = nowX + dx[i];
            if (newY < N * 2 || newY >= N * 3 || newX < 0 || newX >= N || garage[newY][newX] != target) continue;
            garage[newY][newX] = 0;
            visited[newY][newX] = true;
            cnt++;
            maxY = max(maxY, newY);
            maxX = max(maxX, newX);
            minY = min(minY, newY);
            minX = min(minX, newX);
            q.push(make_pair(newY, newX));
        }
    }
    score = (maxY - minY + 1) * (maxX - minX + 1) + cnt;
    if(level < 2) pushDown(garage);
                answer = max(answer, result + score);
            } else {
                vector<vector<int>> nextGarage = getGarageAfterPop(garage, y, x, visited, level);
                simulate(level + 1, nextGarage, result + score);
            }
        }
    }
}

int main(int argc, char** argv) {
    cin >> N;

    vector<vector<int>> garage;
    garage.resize(N * 3, vector<int>(N));


    for (int i = 0; i < N * 3; i++) {
        for (int j = 0; j < N; j++) {
            cin >> garage[i][j];
        }
    }
    simulate(0, garage, 0);
    cout << answer;
    return 0;
}