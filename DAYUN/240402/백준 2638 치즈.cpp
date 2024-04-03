#include <iostream>
#include <queue>

using namespace std;

void cheeseOutside(int i, int j);

int monun[100][100];
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

queue<pair<int, int>> del_cheese;
int n, m;


int main(){
    int cheese_num = 0;
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> monun[i][j];
            cheese_num += monun[i][j];
        }
    }

    //치즈 밖 부분 -1로 처리
    monun[0][0] = -1;
    cheeseOutside(0, 0);
    int t = 0;
    while(cheese_num  != 0) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(monun[i][j] == 1) {
                    int outside = 0;
                    for(int k = 0; k < 4; k++) {
                        if(monun[i + dy[k]][j + dx[k]] == -1) outside++;
                    }
                    if(outside >= 2) del_cheese.push({i, j});
                }
            }
        }

        cheese_num -= del_cheese.size();
        while(!del_cheese.empty()) {
            monun[del_cheese.front().first][del_cheese.front().second] = -1;
            cheeseOutside(del_cheese.front().first, del_cheese.front().second);
            del_cheese.pop();
        }
        t++;
    }
    cout << t;

    return 0;
}

void cheeseOutside(int i, int j){
    queue<pair<int, int>> outs;
    outs.push({i, j});

    while(!outs.empty())
    {
        for(int k = 0; k < 4; k++) {
            int nextI = outs.front().first + dy[k];
            int nextJ = outs.front().second + dx[k];
            // cout << nextI << nextJ << " ";
            if(nextI >= 0 && nextI < n && nextJ >= 0 && nextJ < m) {
                if(monun[nextI][nextJ] == 0) {
                    monun[nextI][nextJ] = -1;
                    outs.push({nextI, nextJ});
                }
            }
        }
        outs.pop();
    }
    return;
}