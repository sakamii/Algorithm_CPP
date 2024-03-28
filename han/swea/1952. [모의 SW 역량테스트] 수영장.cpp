// @start 24.02.17:15:33
// @end 24.02.17:15.53
// @total 20MIN

#include <limits.h>

#include <algorithm>
#include <iostream>
#include <tuple>

using namespace std;

int T, answer = INT_MAX;
int type[4];
int plan[13];

void DFS(int cost, int next) {
  bool flag = true;
  if (next > 12) {
    answer = min(answer, cost);
    return;
  }
  if (plan[next] != 0) {
    DFS(cost + plan[next] * type[0], next + 1);
    DFS(cost + type[1], next + 1);
    DFS(cost + type[2], next + 3);
    DFS(cost + type[3], 13);
  } else {
    DFS(cost, next + 1);
  }
}

int main() {
  cin >> T;
  for (int t = 0; t < T; t++) {
    answer = INT_MAX;
    for (int i = 0; i < 4; i++) {
      cin >> type[i];
    }
    for (int i = 1; i <= 12; i++) {
      cin >> plan[i];
    }
    DFS(0, 1);
    cout << "#" << t + 1 << " " << answer << "\n";
  }
  return 0;
}
