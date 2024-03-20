#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <limits.h>

using namespace std;

const int MAX_N = 100, MAX_K = 21, MAX_BOUND = 1000, MIN_BOUND = -1000;

int N, K, answer = INT_MAX;
vector<pair<int, int>> points[MAX_K];
pair<int, int> PATH[MAX_K];

int MIN_X = INT_MAX, MAX_X = INT_MIN, MIN_Y = INT_MAX, MAX_Y = INT_MIN;

int getRectSize(int level) {
    MIN_X = INT_MAX, MAX_X = INT_MIN, MIN_Y = INT_MAX, MAX_Y = INT_MIN;
    for(int i = 1; i <= level; i++) {
        int x, y;
        tie(x, y) = PATH[i];
        MAX_X = max(MAX_X, x);
        MIN_X = min(MIN_X, x);
        MAX_Y = max(MAX_Y, y);
        MIN_Y = min(MIN_Y, y);
    }
    return (MAX_X - MIN_X) * (MAX_Y - MIN_Y);
}

void DFS(int level) {
    if(answer == 0) return;
    if(level == K + 1) {
        answer = min(answer, getRectSize(level - 1));
        return;
    }
    if(getRectSize(level - 1) >= answer) return;

    for(int i = 0; i < points[level].size(); i++) {
        int x, y;
        tie(x, y) = points[level][i];
        PATH[level] = {x, y};
        DFS(level + 1);
    }
}

int main(int argc, char** argv) {
    cin >> N >> K;
    for(int i = 0; i < N; i++) {
        int x, y, k;
        cin >> x >> y >> k;
        points[k].push_back(make_pair(x + MAX_BOUND, y + MAX_BOUND));
    }

    DFS(1);
    cout << answer;
    return 0;
}