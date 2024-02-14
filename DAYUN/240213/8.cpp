#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

int lamp[18];
int button[18][18];
int result = 19;
int press_button[18];
int N, M, K;


void dfs(int num);
int calculate();

int main() {
    cin >> N >> M >> K;
    for(int i = 0; i < N; i++) {
        cin >> lamp[i] ;
    }
    for(int i = 0; i < M; i++) {
        for(int j = 0; j < K; j++) {
            cin >> button[i][j] ;
        }
    }

    dfs(0);
    cout << result;
}

void dfs(int num) {
    if(num == M) {
        result = min(calculate(), result);
        return;
    }

    press_button[num] = 1;
    dfs(num + 1);

    press_button[num] = 0;
    dfs(num + 1);
}

int calculate() {
    int cal[8];
    int count = 0;
    for(int i = 0; i < N; i++) {
        cal[i] = lamp[i];
    }

    for(int i = 0; i < M; i++) {
        if(press_button[i] == 1) {
            count++;
            for(int j = 0; j < K; j++) {
                cal[button[i][j]  - 1] += 1;
            }
        }

    }

    for(int i = 0; i < N; i++) {
        if((cal[i] % 2) == 0) {
            return M + 1;
        }
    }

    return count;
}
