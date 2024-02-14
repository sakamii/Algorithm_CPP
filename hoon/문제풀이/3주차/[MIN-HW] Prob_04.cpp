#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#include <vector>
#define INF 200000001

using namespace std;

int n;
int t;
int map[11];
int visited[11];
int maxi = -1;

void dfs(int size, int score){
    if(size == n){
        maxi = max(maxi,score);
        return;
    }
    for(int i=1; i<=n; i++){
        if(visited[i] == 1) continue;
        visited[i] = 1;
        int left = i-1;
        int right = i + 1;
        int left_balloon = -1;
        int right_balloon = -1;
        while(left >= 1){
            if(visited[left] != 1){
                left_balloon = map[left];
                break;
            }
            left -= 1;
        }
        while(right <= n){
            if(visited[right] != 1){
                right_balloon = map[right];
                break;
            }
            right += 1;
        }

        if(left_balloon != -1 && right_balloon != -1){
            dfs(size+1, score+right_balloon*left_balloon);
        }
        else if(left_balloon == -1 && right_balloon != -1){
            dfs(size+1, score+right_balloon);
        }
        else if(left_balloon != -1 && right_balloon == -1){
            dfs(size+1, score+left_balloon);
        }
        else{
            dfs(size+1, score+map[i]);
        }
        visited[i] = 0;
    
    }

}
int main() {
    cin >> t;
    
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    for(int test_case = 1; test_case <= t; test_case++){
        cin >> n;
        maxi = -1;
        for(int i=1; i<=n; i++){
            cin >> map[i];
            visited[i] = 0;
        }
        dfs(0,0);
        cout << "#"<<test_case << " " << maxi << endl;
    }    
    return 0;
}