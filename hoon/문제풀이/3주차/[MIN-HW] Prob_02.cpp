#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#include <vector>
#define INF 200000001

using namespace std;

/*
문제 비공개
첫 접근 : dfs로 인접된 마을 찾고, 포함되있지 않는 마을이 연결되있는지 체크하자.
-> 인접된 마을만 체크하지 않는 경우가 있음 -> 조합으로 풀자

풀이 : 조합을 통해 마을을 정하고
다음번 dfs를 넘어가기 이전에, bfs를 통해 각 마을이 연결되어 있는지 판단
visted2 -> 조합으로 고른 마을 판단
visted3 -> 조합으로 고르지 않은 마을 판단
not 연산자를 통해 각 visted 배열의 check하는 마을을 반전시킬수 있음.
*/
int n;
int t;
int map[9][9];
int vill[9];
int visited[9];
int mini = INF;
int total = 0;

void dfs(int idx, int ateamScore){
    if(idx == n){
        return ;
    }
    int flag = 0;
    int flag2 = 0;
    if(idx >= 1){
        int bteamScore = total-ateamScore;
        vector<int> visited2(9,0);
        vector<int> visited3(9,0);
        int check_idx;
        int check_idx2;
        for(int i=0; i<n; i++){
            visited2[i] = visited[i];
            visited3[i] = !visited[i];
            if(visited2[i] == 0){
                check_idx = i;
            }
            if(visited3[i] == 0){
                check_idx2=i;
            }
        }
        queue<int> q;
        q.push(check_idx);
        visited2[check_idx] = 1;
        while(!q.empty()){
            int current_idx = q.front();
            q.pop();
            for(int i=0; i<n; i++){
                if(map[current_idx][i] == 0) continue;
                if(visited2[i] == 1) continue;
                //cout << current_idx << " " << i << endl;
                visited2[i] = 1;
                q.push(i);
            }
        }
        q.push(check_idx2);
        visited3[check_idx2] = 1;
        while(!q.empty()){
            int current_idx = q.front();
            q.pop();
            for(int i=0; i<n; i++){
                if(map[current_idx][i] == 0) continue;
                if(visited3[i] == 1) continue;
                //cout << current_idx << " " << i << endl;
                visited3[i] = 1;
                q.push(i);
            }
        }
        for(int i=0; i<n; i++){
            if(visited2[i] != 1){
                flag = 1;
                break;
            }
        }
        for(int i=0; i<n; i++){
            if(visited3[i] != 1){
                flag2 = 1;
                break;
            }
        }
        if(flag == 0 && flag2 == 0) {
            mini = min(mini,abs(bteamScore-ateamScore));
        }
        else return;
    }
    for(int i=0; i<n; i++){
        if(visited[i] == 1) continue;
        visited[i] = 1;
        dfs(idx+1, ateamScore+vill[i]);
        visited[i] = 0;
    }

}
int main() {
    cin >> t;
    
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    for(int test_case = 1; test_case <= t; test_case++){
        cin >> n;
        total = 0;
        mini = INF;
        for(int i=0; i<n; i++){
            visited[i] = 0;
            for(int j=0; j<n; j++){
                cin >> map[i][j];
            }
        }
        for(int i=0; i<n; i++){
            cin >> vill[i];
            total += vill[i];
        }
        for(int i=0; i<n; i++){
            visited[i] = 1;
            dfs(1,vill[i]);
            visited[i] = 0;
        }
        cout << "#" << test_case << " " << mini << endl;
    }    
    return 0;
}