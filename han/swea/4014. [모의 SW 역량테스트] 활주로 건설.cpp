// @START 24.02.17:16:35
// @END 24.02.17:17:05
// @TOTAL 30MIN

#include <iostream>

using namespace std;

int T, N, X, answer;
int MAP[20][20];

void checkColumn(int x) {
  bool used[20] = {false};
  for (int i = 1; i < N; i++) {
    if (MAP[i][x] == MAP[i - 1][x] + 1) {
      if (i - X < 0) return;
      int temp = MAP[i - 1][x];
      if (used[i - 1]) return;
      used[i - 1] = true;

      for (int j = i - 2; j >= i - X; j--) {
        if (used[j]) return;
        used[j] = true;
        if (MAP[j][x] != temp) return;
      }
    } else if (MAP[i][x] + 1 == MAP[i - 1][x]) {
      if (i + X > N) return;
      int temp = MAP[i][x];
      if (used[i]) return;
      used[i] = true;

      for (int j = i + 1; j < i + X; j++) {
        if (used[j]) return;
        used[j] = true;
        if (MAP[j][x] != temp) return;
      }
    } else if (MAP[i][x] == MAP[i - 1][x]) {
      continue;
    } else {
      return;
    }
  }
  answer++;
}

void checkRow(int y) {
  bool used[20] = {false};
  for (int i = 1; i < N; i++) {
    if (MAP[y][i] == MAP[y][i - 1] + 1) {
      if (i - X < 0) return;
      int temp = MAP[y][i - 1];
      if (used[i - 1]) return;
      used[i - 1] = true;

      for (int j = i - 2; j >= i - X; j--) {
        if (used[j]) return;
        used[j] = true;
        if (MAP[y][j] != temp) return;
      }
    } else if (MAP[y][i] + 1 == MAP[y][i - 1]) {
      if (i + X > N) return;
      int temp = MAP[y][i];
      if (used[i]) return;
      used[i] = true;

      for (int j = i + 1; j < i + X; j++) {
        if (used[j]) return;
        used[j] = true;
        if (MAP[y][j] != temp) return;
      }
    } else if (MAP[y][i] == MAP[y][i - 1]) {
      continue;
    } else {
      return;
    }
  }
  answer++;
}

int main() {
  cin >> T;
  for (int t = 0; t < T; t++) {
    answer = 0;
    cin >> N >> X;
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        cin >> MAP[i][j];
      }
    }
    for (int i = 0; i < N; i++) {
      checkColumn(i);
      checkRow(i);
    }
    cout << "#" << t + 1 << " " << answer << "\n";
  }
  return 0;
}
