#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
#define INF 20000001
int map[31][31];
int dx[] = {1,-1,0,0};
int dy[] = {0,0,-1,1};
int dist[31][31];
int n;

void dijkstra(){

    priority_queue<pair<int,pair<int,int>>> pq;
    pq.push({0,{0,0}});
    dist[0][0] = 0;

    while(!pq.empty()){
        int current_y = pq.top().second.first;
        int current_x = pq.top().second.second;
        int current_cost = -pq.top().first;
        int current_height = map[current_y][current_x];
        pq.pop();
        for(int i=0; i<4; i++){
            int next_y = current_y + dy[i];
            int next_x = current_x + dx[i];
            if(next_y < 0 || next_x < 0 || next_y >= n || next_x >= n) continue;
            int next_cost;
            int next_height = map[next_y][next_x];
            if(current_height > next_height){
                next_cost = current_cost;
            }
            else if(current_height == next_height){
                next_cost = current_cost + 1;
            }
            else{
                next_cost = current_cost + (next_height-current_height)*2;
            }

            if(next_cost < dist[next_y][next_x]){
                dist[next_y][next_x] = next_cost;
                pq.push({-next_cost,{next_y,next_x}});
            }
        }
    }

}

int main() {
    int t;
    cin >> t;
    for(int test_case=1; test_case<=t; test_case++){
        
        cin >> n;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cin >> map[i][j];
                dist[i][j] = INF;
            }
        }
        dijkstra();
        int answer = dist[n-1][n-1];
        cout << "#"<< test_case << " "<< answer << endl;


    }
}