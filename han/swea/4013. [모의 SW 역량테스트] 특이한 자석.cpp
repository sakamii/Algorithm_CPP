// @START 24.02.17:17:30
// @END 24.02.17:18:30
// @TOTAL 1H

#include <math.h>

#include <iostream>

using namespace std;

int T, K, answer;
int vect[5][8];

void setScore() {
  for (int i = 1; i < 5; i++) {
    if (vect[i][0] != 0) {
      answer += pow(2, i - 1);
    }
  }
}

bool isLeftSynced(int target) { return vect[target][6] != vect[target - 1][2]; }

bool isRightSynced(int target) {
  return vect[target][2] != vect[target + 1][6];
}

void rotate(int target, bool dir, int force) {
  int left = target - 1;
  int right = target + 1;
  if (left > 0 && force != 1) {
    if (isLeftSynced(target)) {
      rotate(left, !dir, -1);
    }
  }
  if (right < 5 && force != -1) {
    if (isRightSynced(target)) {
      rotate(right, !dir, 1);
    }
  }

  if (dir) {
    int temp[8];
    for (int i = 0; i < 8; i++) {
      temp[i] = vect[target][i];
    }
    for (int i = 1; i < 8; i++) {
      vect[target][i] = temp[i - 1];
    }
    vect[target][0] = temp[7];
  } else {
    // 반시계
    int temp[8];
    for (int i = 0; i < 8; i++) {
      temp[i] = vect[target][i];
    }
    for (int i = 7; i > 0; i--) {
      vect[target][i - 1] = temp[i];
    }
    vect[target][7] = temp[0];
  }
}

int main() {
  cin >> T;
  for (int t = 0; t < T; t++) {
    answer = 0;
    cin >> K;
    for (int i = 1; i < 5; i++) {
      for (int j = 0; j < 8; j++) {
        cin >> vect[i][j];
      }
    }
    for (int i = 0; i < K; i++) {
      int target, dir;
      cin >> target >> dir;
      rotate(target, (dir == 1 ? true : false), 0);
    }
    setScore();
    cout << "#" << t + 1 << " " << answer << "\n";
  }
  return 0;
}
