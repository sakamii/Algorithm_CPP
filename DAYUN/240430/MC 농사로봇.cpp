/*
    1.모든위치, 모든 방향에 대해 탐색한다.
    1.1 시키는 액션을 한다.
*/



#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int map[9][9];
int dir[4][2] = {{0, 1}, {-1, 0}, {0, -1}, {0, 1}};

void init();
int harvest(int i, int j, int d);

int main() {
    int T;
    for(int test_case  = 1; test_case <= T; ++test_case) {
        int result = 0;
        
        init();

        for(int i = 1; i < (N - 1); i++) {
            for(int j = 1; j < (N -1); j++) {
                if(map[i][j] == 0) {
                    for(int d = 0; d < 4; ++d) {
                        result = max(result, harvest(i, j, d));
                    }
                }
            }
        }

        cout << "#" << " " << test_case << " " << result << "\n";
    }
}

void init() {
    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; ++j) {
            cin >> map[i][j];
        }
    }
}

int harvest(int i, int j, int d) {
    int result = 0;

    f

    return result;
}