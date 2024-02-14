#include <string>
#include <vector>
#include <iostream>
using namespace std;

int cnt = 0;
int arr[1010][1010];

int solution(vector<vector<int>> board, vector<vector<int>> skill) {

for (int i = 0; i < skill.size(); i++) {
    int type = skill[i][0];
    int y1 = skill[i][1];
    int x1 = skill[i][2];
    int y2 = skill[i][3];
    int x2 = skill[i][4];
    int degree = skill[i][5];

    if (type == 1) degree = -1 * degree;

    arr[y1][x1] += degree;
    arr[y2 + 1][x2 + 1] += degree;
    arr[y1][x2 + 1] -= degree;
    arr[y2 + 1][x1] -= degree;
}

for (int j = 0; j <= board.size(); j++) {
    for (int k = 0; k < board[0].size(); k++) {
        arr[j][k + 1] += arr[j][k];
    }
}

for (int j = 0; j <= board[0].size(); j++) {
    for (int k = 0; k < board.size(); k++) {
        arr[k + 1][j] += arr[k][j];
    }
}


for (int i = 0; i < board.size(); i++) {
    for (int j = 0; j < board[0].size(); j++) {
        if (board[i][j] + arr[i][j] > 0) cnt++;
    }
}

return cnt;
}

