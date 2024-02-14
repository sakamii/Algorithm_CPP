#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector<int> v[100];
vector<int> n;
int visited[100];
int N, M, K;
int cnt;
int min_cnt = 2134567890;
int on_cnt;
int ans;

// 버튼에 연결된 전구 중에서 꺼진 전구가 있는 check
int on_enalbe(int x) {
    int flag;

    for (int i = 0; i < v[x].size(); i++) {
        if (n[v[x][i]] == 0) {
            flag = 1;
            return flag;
        }
        else flag = 0;
    }
    return flag;
}

// 버튼 누르고 toggle 진행
void toggle(int x) {
    for (int i = 0; i < v[x].size(); i++) {
        if (n[v[x][i]] == 0) {
            n[v[x][i]] = 1;
            on_cnt++;
        }
        else {
            on_cnt--;
            n[v[x][i]] = 0;
        }
    }
    return;
}

void dfs(int x) {
    
    if (on_cnt == N) {
        min_cnt = min(min_cnt, cnt);
        ans = 1;
        return;
    }
   
    
    
    for (int i = 0; i < M; i++) {
        int check = on_enalbe(i);
        if (visited[i] == 1) continue;
        if (check == 0) continue;
        visited[i] = 1;
        toggle(i);
        cnt++;
        dfs(x + 1);
        visited[i] = 0;
        toggle(i);
        cnt--;

    }

}


int main() {

    cin >> N >> M >> K;

    n.push_back(0);
    for (int i = 0; i < N; i++) {
        int light;
        cin >> light;
        n.push_back(light);
        if (light == 1) on_cnt++;
    }

    for (int i = 0; i <M; i++) {
        for (int j = 0; j < K; j++) {
            int line;
            cin >> line;
            v[i].push_back(line);
        }
    }

    dfs(0);

    if (ans == 1) cout << min_cnt;
    else cout << "-1";

    return 0;
}
