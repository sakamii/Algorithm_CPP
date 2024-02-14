#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#include <vector>
#define INF 200000001

using namespace std;

int n,m;
int t;
int map[16][16];
int visited[16][16];
//index : 4,5 윗대각, 6,7 아랫 대각
//열 index 짝수: 아랫대각 못감
//열 index 홀수: 윗대각 못감
/*
8방향 bfs 문제지만 예외 케이스를 다뤄야함
육각으로 이루어진 벌집을 행렬의 형태로 표현하기 위해서
홀수열과 짝수열에 대각으로 이동할수 있는 케이스와 없는 케이스가 나뉘어짐.

*/
int dy[] = {0,0,1,-1,-1,-1,1,1};
int dx[] = {1,-1,0,0,-1,1,-1,1};
long long int maxi = -1;
void dfs(int cnt, long long int sum, int current_y, int current_x){
    if(cnt == 4){
        if(maxi < sum){
            maxi = sum;
        }
        return;
    }
    for(int i=0; i<8; i++){
        if(current_x % 2 == 0 && (i == 6 || i == 7)) continue;
        if(current_x % 2 == 1 && (i == 4 || i == 5)) continue;
        int next_y = current_y + dy[i];
        int next_x = current_x + dx[i];
        if(next_y < 0 || next_x < 0 || next_y >=n || next_x >=m) continue;
        if(visited[next_y][next_x] == 1) continue;
        visited[next_y][next_x] = 1;
        dfs(cnt+1,sum+map[next_y][next_x], next_y,next_x);
        visited[next_y][next_x] = 0;
    }
}
int main() {
    cin >> t;
    
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    for(int test_case = 1; test_case <= t; test_case++){
        cin >> n >> m;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin >> map[i][j];
                visited[i][j] = 0;
            }
        }
        maxi = -1;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                visited[i][j] = 1;
                dfs(1,map[i][j],i,j);
                visited[i][j] = 0;
                if(j%2==0){
                    //윗Y
                    int flag = 0;
                    long long int sum = map[i][j];
                    vector<int> v1;
                    v1.push_back(4);
                    v1.push_back(5);
                    v1.push_back(2);
                    for(int x=0; x<3; x++){
                        int next_y = i + dy[v1[x]];
                        int next_x = j + dx[v1[x]];
                        if(next_y<0 || next_x < 0 || next_y >=n || next_x >=m){
                            flag = 1;
                            break;
                        }
                        sum += map[next_y][next_x];
                    }
                    if(flag == 0) maxi = max(maxi,sum);
                    //아랫Y
                    sum = map[i][j];
                    flag = 0;
                    vector<int> v2;
                    v2.push_back(0);
                    v2.push_back(1);
                    v2.push_back(3);
                    for(int x=0; x<3; x++){
                        int next_y = i + dy[v2[x]];
                        int next_x = j + dx[v2[x]];
                        if(next_y<0 || next_x < 0 || next_y >=n || next_x >=m){
                            flag = 1;
                            break;
                        }
                        sum += map[next_y][next_x];
                    }
                    if(flag == 0) maxi = max(maxi,sum);
                }
                if(j%2==1){
                    int flag = 0;
                    long long int sum = map[i][j];
                    vector<int> v1;
                    v1.push_back(0);
                    v1.push_back(1);
                    v1.push_back(2);
                    for(int x=0; x<3; x++){
                        int next_y = i + dy[v1[x]];
                        int next_x = j + dx[v1[x]];
                        if(next_y<0 || next_x < 0 || next_y >=n || next_x >=m){
                            flag = 1;
                            break;
                        }
                        sum += map[next_y][next_x];
                    }
                    if(flag == 0) maxi = max(maxi,sum);
                    //아랫Y
                    sum = map[i][j];
                    flag = 0;
                    vector<int> v2;
                    v2.push_back(3);
                    v2.push_back(6);
                    v2.push_back(7);
                    for(int x=0; x<3; x++){
                        int next_y = i + dy[v2[x]];
                        int next_x = j + dx[v2[x]];
                        if(next_y<0 || next_x < 0 || next_y >=n || next_x >=m){
                            flag = 1;
                            break;
                        }
                        sum += map[next_y][next_x];
                    }
                    if(flag == 0) maxi = max(maxi,sum);

                }
            }
        }

        cout << "#"<<test_case << " " << maxi << endl;
    }    
    return 0;
}