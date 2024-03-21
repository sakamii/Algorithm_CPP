/*
    DNA 4종류 a c g t
    염기서열 N개 길이 M 
    와일드 카드 . (무엇이든 들어와도 좋다)
    염기서열 조건을 만족할 수 있는 염기서열 : 초염기서열
    초 염기서열을 만들어 여러 그룹의 연기서열 커버
    최소 갯수의 초 염기서열?
    모든
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int map[15][20];
vector<pair<long long, long long>> range[15];
bool visited[15] = {false};
vector<vector<vector<int>>> v;
int n, m;

void dfs(int level);
int min_result;

int main(int argc, char** argv)
{
    cin >> n >> m;
    v.resize(n);
    for(int i = 1; i < n; i++) {
        for(int j = 0; j < m; j++) {
            char ch;
            cin >> ch;
            if(ch == 'a') map[i][j] = 0;
            else if(ch == 'c') map[i][j] = 1;
            else if(ch == 'g') map[i][j] = 2;
            else if(ch == 't') map[i][j] = 3;
            else map[i][j] = -1;
        }
    }

    for(int i = 0; i < (1 << n); i++) {
        bool flag = true;
        int s[20];
        memset(s, -1, sizeof(int) * m);
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < m; k++) {
                if((i << j) & 1) {
                    if(s[k] == -1 || map[j][k] == s[k]) {
                        s[k] = map[j][k];
                    }
                    else {
                        flag = false;
                    }
                }
            }
        }

        if(flag) {
            for(int j = 0; j < n; j++) {
                if((i >> j) & 1){
                    v[j].push_back(i);
                }
            }
        }
    }

    dfs(0, 0);
   return 0;
}

void dfs(int result, int visited){
    int i ;
    for(i = 0; i < n; i++) {
        if(!((visited >> i) & 1)) {
            
        }
    }

    for(int i : v[level]) {
        int next_visited = visited | i;

        for(int j = 0; j < n; j++) {
            if(i ) {
                dfs(level, result + 1, nextvi);
                flag = true;
                break;
            }
        }
        
        if(!flag) {
            min_result = min(result, min_result);
        }
    }

}