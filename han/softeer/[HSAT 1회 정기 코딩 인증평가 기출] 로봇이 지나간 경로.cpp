#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <limits.h>

using namespace std;

// dir : 바라보고 있는 방향, L : -1, R : +1
const int UP = 0, RIGHT = 1, DOWN = 2, LEFT = 3;
const int MAX_H = 25, MAX_W = 25;

int H, W;
string MAP[MAX_H];
string answer = "";
int answerL = (int)1e9;
int answerY, answerX, answerD;
int tempY, tempX, tempD;

int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };

string getLRcmd(int d, int tar) {
    if (d == tar) return "";
    else if (d < tar) {
        if (tar - d == 1) return "R";
        else if (tar - d == 2) return "RR";
        else return "L";
    }
    else {
        if (d - tar == 1) return "L";
        else if (d - tar == 2) return "LL";
        else return "R";
    }
}

bool checkComplete() {
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            if(MAP[i][j] == '#') return false;
        }
    }
    return true;
}

void DFS(int y, int x, int d, string cmd) {
    if(checkComplete()) {
        if(answerL > cmd.length()) {
            answer = cmd;
            answerL = cmd.length();
            answerY = tempY;
            answerX = tempX;
            answerD = tempD;
            return;
        }
    }
    int dir = 0;
    for (; dir < 4; dir++) {
        string temp = getLRcmd(d, dir);
        bool flag = false;
        int newY, newX;
        for (int j = 1; j <= 2; j++) {
            newY = y + (dy[dir] * j);
            newX = x + (dx[dir] * j);
            if (newY < 0 || newY >= H || newX < 0 || newX >= W || MAP[newY][newX] == '.') {
                flag = true;
                break;
            }
        }
        if (flag) continue;
        for (int j = 1; j <= 2; j++) {
            newY = y + (dy[dir] * j);
            newX = x + (dx[dir] * j);
            MAP[newY][newX] = '.';
        }
        DFS(newY, newX, dir, cmd + temp + "A");
        for (int j = 1; j <= 2; j++) {
            newY = y + (dy[dir] * j);
            newX = x + (dx[dir] * j);
            MAP[newY][newX] = '#';
        }
    }
}

int main(int argc, char** argv) {
    cin >> H >> W;
    for (int i = 0; i < H; i++) {
        cin >> MAP[i];
    }

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (MAP[i][j] == '.') continue;
            for (int d = 0; d < 4; d++) {
                MAP[i][j] = '.';
                tempY = i;
                tempX = j;
                tempD = d;
                DFS(i, j, d, "");
                MAP[i][j] = '#';
            }
        }
    }
    cout << answerY + 1 << " " << answerX + 1 << "\n";
    cout << (answerD == 0 ? "^" : answerD == 1 ? ">" : answerD == 2 ? "v" : "<") << "\n";
    cout << answer;
    return 0;
}