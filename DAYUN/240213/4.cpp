#include<iostream>
#include<algorithm>

using namespace std;

int ballon[10];
int result = 0;
int N;
bool visited[10];
int turn[10] = {0};

int dfs(int n);
int score();

int main() {
    int T;
    cin >> T;
    for(int test_case = 1; test_case <= T; test_case++) {
        result = 0;
        cin >> N;
        for(int i = 0; i < N; i++) {
            cin >> ballon[i];
        }
        fill(visited, visited + N, false);
        dfs(0);

        cout << "#" << test_case << " " << result << endl;
    }
}

int dfs(int n) {
    if(n == N) {
        result = max(score(), result);
    }

    for(int i = 0; i < N; i++) {
        if(!visited[i]) {
            turn[n] = i;
            visited[i] = true;
            dfs(n + 1);
            visited[i] = false;
        }
    }

}

int score() {
    int sc = 0;
    int ballon_test[10];
    for(int i = 0; i < N; i++) {
        ballon_test[i] = ballon[i];
    }
    for(int t = 0; t < N; t++) {
        int i = turn[t];
        int left_ballon = 0, right_ballon = 0;
        int flag = 0;
        for(int j = i - 1; j >= 0; j--) {
            if(ballon_test[j] != 0) {
                left_ballon = ballon_test[j];
                flag++;
                break;
            }
        }
        
        for(int j = i + 1; j < N; j++) {
            if(ballon_test[j] != 0) {
                right_ballon = ballon_test[j];
                flag++;
                break;
            }
        }
        if(flag == 2) {
                 sc += (left_ballon * right_ballon);
        }
        else if(flag == 1) {
            sc += (left_ballon + right_ballon);
        }
        else {
            sc += ballon_test[i];
        }
        ballon_test[i] = 0;
    }
    return sc;
}