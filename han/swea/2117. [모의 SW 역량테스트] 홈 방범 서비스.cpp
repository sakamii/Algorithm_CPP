// @START 24.02.17:15:57
// @END 24.02.17:16:27
// @TOTAL 30MIN
// @FAIL 1

#include <limits.h>

#include <algorithm>
#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int T, N, M, K, cnt, answer;
int MAP[20][20];
bool visited[20][20];

int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, -1, 0, 1};

int getCost() { return K * K + (K - 1) * (K - 1); }

void BFS(pair<int, int> now) {
  if (MAP[now.first][now.second] == 1)
    cnt = 1;
  else
    cnt = 0;

  size_t depth;
  K = 1;
  queue<pair<int, int>> q;
  q.push(now);

  while (!q.empty()) {
    depth = q.size();

    if (getCost() <= cnt * M) {
      answer = max(answer, cnt);
    }
    while (depth--) {
      int y, x;
      tie(y, x) = q.front();
      q.pop();

      for (int i = 0; i < 4; i++) {
        int newY = y + dy[i];
        int newX = x + dx[i];

        if (newY < 0 || newY >= N || newX < 0 || newX >= N ||
            visited[newY][newX])
          continue;
        visited[newY][newX] = true;
        if (MAP[newY][newX] == 1) cnt++;
        q.push(make_pair(newY, newX));
      }
    }
    K++;
  }
}

int main() {
  cin >> T;
  for (int t = 0; t < T; t++) {
    answer = 0;
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        cin >> MAP[i][j];
      }
    }
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        fill(&visited[0][0], &visited[N][N], false);
        visited[i][j] = true;
        BFS(make_pair(i, j));
        visited[i][j] = false;
      }
    }
    cout << "#" << t + 1 << " " << answer << "\n";
  }
  return 0;
}
