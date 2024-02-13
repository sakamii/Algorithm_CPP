#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

int total_popular = 0, group_popular = 0;
int N;
int popular[8];
bool group[8];
int route[8][8];
bool visited[8] = { false };
int result;
queue<int> q;

void dfs(int now);
bool valid();

int main() {
    int T;
    cin >> T;
    for (int test_case = 1; test_case <= T; test_case++) {
        total_popular = 0;
        group_popular = 0;
        cin >> N;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cin >> route[i][j];
            }
        }
        for (int i = 0; i < N; i++) {
            cin >> popular[i];
            total_popular += popular[i];
            group[i] = false;
        }
        result = total_popular;

        dfs(0);
        cout << "#" << test_case << " " << result << endl;
    }
}

void dfs(int now) {

    if (now == N) {
        if (valid()) {
            result = min(abs(total_popular - (group_popular * 2)), result);
        }
        return;
    }
    if (((group_popular * 2) - total_popular) > result) {
        return;
    }

    //gruop에 포함
    group_popular += popular[now];
    group[now] = true;
    dfs(now + 1);

    //gruop에 포함 안함
    group_popular -= popular[now];
    group[now] = false;
    dfs(now + 1);
}

bool valid() {
    for (int i = 0; i < N; i++) {
        visited[i] = false;
    }

    int first = -1;
    while (!group[first]) first++;
    if ((first < N) && (first > -1)) {
        q.push(first);
        visited[first] = true;
    }
    int popular_test = group_popular;
    while (!q.empty()) {
        int i = q.front();
        q.pop();
        popular_test -= popular[i];
        for (int j = 0; j < N; j++) {
            if (group[j] && route[i][j] && !visited[j]) {
                visited[j] = true;
                q.push(j);
            }
        }
    }
    if (popular_test != 0) {
        return false;
    }

    first = 0;
    while (group[first]) first++;
    if ((first < N) && (first > -1)) {
        q.push(first);
        visited[first] = true;
    }


    popular_test = total_popular - group_popular;
    while (!q.empty()) {
        int i = q.front();
        q.pop();
        popular_test -= popular[i];
        for (int j = 0; j < N; j++) {
            if (!group[j] && route[i][j] && !visited[j]) {
                visited[j] = true;
                q.push(j);
            }
        }
    }
    if (popular_test != 0) {
        return false;
    }

    return true;
}
