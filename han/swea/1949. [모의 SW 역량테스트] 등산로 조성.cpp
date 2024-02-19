#include <iostream>
#include <tuple>
#include <vector>

using namespace std;

int T, N, K, MAX_HEIGHT, answer;
int MAP[8][8];
bool visited[8][8];

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

bool canGo(int nowY, int nowX, int newY, int newX) {
  return MAP[nowY][nowX] > MAP[newY][newX];
}

void DFS(int level, int y, int x, bool useK) {
  if (level > answer) {
    answer = level;
  }

  for (int i = 0; i < 4; i++) {
    int newY = y + dy[i];
    int newX = x + dx[i];

    if (newY < 0 || newY >= N || newX < 0 || newX >= N || visited[newY][newX])
      continue;
    visited[newY][newX] = true;

    if (!useK) {
      for (int k = K; k >= 0; k--) {
        MAP[newY][newX] -= k;
        if (canGo(y, x, newY, newX)) {
          DFS(level + 1, newY, newX, true);
        }

        MAP[newY][newX] += k;
      }
    }

    if (canGo(y, x, newY, newX)) {
      DFS(level + 1, newY, newX, useK);
    }
    visited[newY][newX] = false;
  }
}

int main() {
  cin >> T;

  for (int t = 0; t < T; t++) {
    vector<pair<int, int>> vect[21];
    answer = 0;
    MAX_HEIGHT = 0;
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        cin >> MAP[i][j];
        vect[MAP[i][j]].push_back(make_pair(i, j));
        if (MAX_HEIGHT < MAP[i][j]) {
          MAX_HEIGHT = MAP[i][j];
        }
      }
    }

    for (int i = 0; i < vect[MAX_HEIGHT].size(); i++) {
      int y, x;
      tie(y, x) = vect[MAX_HEIGHT][i];
      visited[y][x] = true;
      DFS(1, y, x, false);
      visited[y][x] = false;
    }

    cout << "#" << t + 1 << " " << answer << "\n";
  }
  return 0;
}