#include<iostream>
#include<algorithm>

using namespace std;

int N, K;
int arr[10];
int cnt = 0;
int visited[10] = {false};
int map[10][10];

void dfs(int before, int num);

int main() {
    cin >> N >> K;
    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    //작은 수부터 시작 160으로 시작  -160으로 끝
    //16.으로 시작, 끝 인 경우의 수 제거
    //2차원 배열
    // 원래 자리수 (가로)
    // 세로 : 설 수 있는 자리 수 
    //route : 가능하면 1, 불가능하면 0
    // 1 -> 2 -> 

    for(int i = 0; i < N; i++){
        for(int j = i + 1; j < N; j++) {
            if((abs(arr[i] - arr[j]) <= K) && (arr[i] != arr[j])) {
                map[i][j] = 1;
                map[j][i] = 1;
            }
            else {
                map[i][j] = 0;
                map[j][i] = 0;
            }
        }    
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++) {
            // cout << map[i][j] << " ";
        }    
        // cout << endl;
    }

    

    for(int i = 0; i < N; i++) {
        visited[i] = true;
        // cout << i << " ";
        dfs(i, 1);
        visited[i] = false;
    }
    
    cout << cnt;
}

void dfs(int before, int num) {
    if(num == N) {
        cnt++;
    }

    for(int i = 0; i < N; i++) {
        if(map[before][i] && !visited[i]) {
            visited[i] = true;
            //  cout << i << " ";
            dfs(i, num + 1);
            visited[i] = false;
        }
    }
}