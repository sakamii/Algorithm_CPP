#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;

vector<int> v[10];

int visited[10];
int vote[10];
int T, N, ans, total;

void solution(int x) {
    if (x > N) return;

    vector<int> v1(10,0);
    vector<int> v2(10,0);
    int v1_idx = 0, v2_idx = 0;
    int flag_1 = 0, flag_2 = 0;
    int score_1 = 0, score_2 = 0;

    for (int i = 1; i <= N; i++) {
        v1[i] = visited[i];
        v2[i] = !visited[i];
        if (v1[i] == 1) v1_idx = i;
        if (v2[i] == 1) v2_idx = i;
    }

    queue<int> q;
    q.push(v1_idx);
    v1[v1_idx] = 0;

    while (!q.empty()) {
        int now = q.front();
        q.pop();
        for (int i = 0; i < v[now].size(); i++) {
            int next = v[now][i];
            if (v1[next] == 0) continue;
            v1[next] = 0;
            q.push(next);
        }
    }

    q.push(v2_idx);
    v2[v2_idx] = 0;

    while (!q.empty()) {
        int now = q.front();
        q.pop();
        for (int i = 0; i < v[now].size(); i++) {
            int next = v[now][i];
            if (v2[next] == 0) continue;
            v2[next] = 0;
            q.push(next);
        }
    }

    for (int i = 1; i <= N; i++) {
        if (v1[i] == 1) flag_1 = 1;
        if (v2[i] == 1) flag_2 = 1;
        if (visited[i] == 1) {
            score_1 += vote[i];
        }
    }

    score_2 = total - score_1;

    if (flag_1 != 1 && flag_2 != 1) {
        ans = min(ans, abs(score_1 - score_2));
    }

    for (int i = x; i < N; i++) {
        visited[i] = 1;
        solution(i + 1);
        visited[i] = 0;
    }
    
}

void input(int x) {

    cin >> N;

    ans = 2134567890;
    total = 0;

    for (int i = 1; i <= N; i++) {
        v[i].clear();
        for (int j = 1; j <= N; j++) {
            int to;
            cin >> to;
            if (to == 1) v[i].push_back(j);
       }
    }

    for (int i = 1; i <= N; i++) {
        cin >> vote[i];
        total += vote[i];
    }

}

int main() {

    cin >> T;

    for (int t = 1; t <= T; t++) {

        input(0);

        
        for (int i = 1; i <= N; i++) {
            visited[i] = 1;
            solution(i + 1);
            visited[i] = 0;
        }
        
        cout << "#" << t << " " << ans << endl;
        
        
    }


    return 0;
}
