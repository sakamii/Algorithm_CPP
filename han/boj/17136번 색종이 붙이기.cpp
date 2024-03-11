// @START 24.03.11:15:33
// @END FAIL

#include <iostream>
#include <algorithm>
#include <tuple>
#include <limits.h>

using namespace std;

int vect[10][10];
bool used[10][10];
int cnt[6] = { 0, 5, 5, 5, 5, 5 };
int T, answer = INT_MAX;

// 색종이를 사용한 횟수(문제의 답)
int getCounts() {
    int sum = 0;
    for (int i = 1; i <= 5; i++) {
        sum += (5 - cnt[i]) * i * i;
    }
    return sum;
}

// 현재까지 색종이로 덮은 영역의 개수
int getCost() {
    int sum = 0;
    for (int i = 1; i <= 5; i++) {
        sum += 5 - cnt[i];
    }
    return sum;
}

// 현재 (y, x) 부터 level x level 크기의 색종이로 덮을 수 있는지 확인
bool isPossible(int y, int x, int level) {
    for (int i = y; i < y + level; i++) {
        for (int j = x; j < x + level; j++) {
            if (used[i][j] || vect[i][j] == 0) return false;
        }
    }
    return true;
}

// 현재 (y, x)부터 level x level 크기의 색종이로 덮는 함수
// visited 배열 처리를 위함
void setUsed(int y, int x, int level, bool target) {
    for (int i = y; i < y + level; i++) {
        for (int j = x; j < x + level; j++) {
            used[i][j] = target;
        }
    }
}

// DFS(재귀함수)를 활용한 완전 탐색
void DFS(int level) {
    if (answer <= getCost()) return; // 가지치기 (현재 탐색중인 케이스에서 사용한 종이의 수 >= 현재까지 나온 모든 케이스 중 가장 작은 종이의 수) 이면 return
    if (T == getCounts() || level == 0) { // 현재 탐색중인 케이스에서 사용한 종이의 수 == 현재까지 나온 모든 케이스 중 가장 작은 종이의 수
        if(level == 0 && T != getCounts()) return;
        answer = min(answer, getCost());
        return;
    }
    bool flag = false; // 다음 사이즈로의 탐색 여부를 결정하는 flag, 현재 영역에서 아무 곳도 덮을 수 없다면 true가 되어 다음 영역 탐색으로 넘어갈 수 있게 함
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (used[i][j] || vect[i][j] == 0) continue;
            if (isPossible(i, j, level)) {
                flag = true;
                setUsed(i, j, level, true);
                cnt[level]--;
                DFS(cnt[level] == 0 ? level - 1 : level); // cnt[level] == 0 의 의미 : 현재 level 크기의 색종이 5장을 모두 사용하였기 때문에 다음 level로 가야 함
                cnt[level]++;
                setUsed(i, j, level, false);
            }
        }
    }
    if (!flag) {
        DFS(level - 1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cin >> vect[i][j];
            if (vect[i][j] == 1) T++;
        }
    }

    DFS(5);
    cout << (answer == INT_MAX ? -1 : answer);
    return 0;
}
