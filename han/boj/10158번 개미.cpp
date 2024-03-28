// @START 24.03.09:16:30
// @END FAIL

#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

int W, H, P, Q, T;

int dy[4] = {1, -1, 1, -1}; // 우하, 우상, 좌하, 좌상
int dx[4] = {1, 1, -1, -1};

vector<pair<int, int>> PATH;

int isBoundPosition(int y, int x) {
    // 튕길 수 있는 벽이라면 해당 벽의 위치를 반환
    // 벽의 위치 : 상(0), 우(1), 하(2), 좌(3)
    // 아니면 -1
    if(y == 0) {
        return 0;
    } else if(x == W) {
        return 1;
    } else if(y == H) {
        return 2;
    } else if(x == 0) {
        return 3;
    }
    return -1;
}

int getDir(int y, int x, int dir) {
    if(y == 0 && x == 0) {
        // 좌상 꼭지점
        return 0;
    } else if(y == 0 && x == W) {
        // 우상 꼭지점
        return 2;
    } else if(y == H && x == W) {
        // 우하 꼭지점
        return 3;
    } else if(y == H && x == 0) {
        // 좌하 꼭지점
        return 1;
    }
    
    int pos = isBoundPosition(y, x); // 벽의 위치 : 상(0), 우(1), 하(2), 좌(3)
    // 우하(0), 우상(1), 좌하(2), 좌상(3)
    
    if(pos != -1) {
        if(dir == 0) {
            // 우하 : 0, 오른쪽(1) > 좌하(2), 아래(2) > 우상(1), 우하꼭지점 > 좌상(3)
            if(pos == 1) {
                return 2;
            } else {
                return 1;
            }
        } else if(dir == 1) {
            // 우상 : 1, 위(0) > 우하(0), 오른쪽(1) > 좌상(3), 우상꼭지점 > 좌하(2)
            if(pos == 0) {
                return 0;
            } else {
                return 3;
            }
        } else if(dir == 2) {
            // 좌하 : 2, 왼쪽(3) > 우하(0), 아래(2) > 좌상(3), 좌하꼭지점 > 우상(1)
            if(pos == 3) {
                return 0;
            } else {
                return 3;
            }
        } else {
            // 좌상 : 3, 왼쪽(3) > 우상(1), 위(0) > 좌하(2), 좌상꼭지점 > 우하(0)
            if(pos == 3) {
                return 1;
            } else {
                return 2;
            }
        }
    }
    
    return dir;
}

int main() {
    cin >> W >> H >> P >> Q >> T;
    int t = 0;
    int nowY = Q, nowX = P, dir = 0;
    PATH.push_back({nowY, nowX});
    while(t < T) {
        // 우하(0), 우상(1), 좌하(2), 좌상(3)
        // 우하 : 0, 오른쪽 > 좌하(2), 아래 > 우상(1), 우하꼭지점 > 좌상(3)
        // 우상 : 1, 위 > 우하(0), 오른쪽 > 좌상(3), 우상꼭지점 > 좌하(2)
        // 좌하 : 2, 왼쪽 > 우하(0), 아래 > 좌상(3), 좌하꼭지점 > 우상(1)
        // 좌상 : 3, 왼쪽 > 우상(1), 위 > 좌하(2), 좌상꼭지점 > 우하(0)
        dir = getDir(nowY, nowX, dir);
        
        nowY += dy[dir];
        nowX += dx[dir];
        
        if(nowY == Q && nowX == P && dir == 0) {
            tie(nowY, nowX) = PATH[T % PATH.size()];
            break;
        }
        PATH.push_back({nowY, nowX});
        t++;
        // cout << t << " : " <<  nowY << nowX << "\n";
    }
    cout << nowX << " " << nowY;
    return 0;
}
