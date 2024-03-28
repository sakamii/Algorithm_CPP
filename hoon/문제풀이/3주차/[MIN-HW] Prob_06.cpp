#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
#define INF 20000001


int n,k;
vector<int> people;
vector<int> visited;
int cnt = 0;
void dfs(int prev,int num){
    if(num == n){
        cnt += 1;
        return;
    }

    for(int i=0; i<n; i++){
        if(visited[i] == 1) continue;
        if(prev == people[i]) continue;
        if(abs(prev-people[i]) > k) continue;
        visited[i] = 1;
        dfs(people[i], num+1);
        visited[i] = 0;

    }

}
int main() {
    cin >> n >> k;
    for(int i=0; i<n; i++){
        int temp;
        cin >> temp;
        people.push_back(temp);
        visited.push_back(0);
    }

    for(int i=0; i<n; i++){
        visited[i] = 1;
        dfs(people[i],1);
        visited[i] = 0;
    }

    cout << cnt << endl;
}