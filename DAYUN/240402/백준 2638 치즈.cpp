#include <iostream>
#include <queue>

using namespace std;

int map[102][102];
int cheese_num = 0;
queue<pair<int, int>> q;

int main(){
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> map[i][j];
            cheese_num +=  map[i][j];
        }
    }    

    //치즈 안쪽(2) 확인
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(map[i][j] == 0) {
                if(!map[i - 1][j] && !map[i][j - 1]) {
                    //오른쪽 방향
                    int k;
                    for(k = j + 1; k < m; k++){
                        if(map[i][k] == 0) continue;
                        if(map[i][k] == 1) break; 
                    }
                    if(k == m) break;
                    //아래 방향
                    for(k = i + 1; k < n; k++) {
                        if(map[k][j] == 0) continue;
                        if(map[k][j] == 1) break; 
                    }
                    if(k == n) break;
                    map[i][j] = 2;
                    q.push({i , j});
                }
            }
        }
    } 

    int t = 0;
    while(true){
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                cout << map[i][j] << " ";
            }
            cout << endl;
        } 


        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                int air = 0;
                //4칸 중에 2칸 이상이 공기 일 경우, 소멸
                if(map[i][j] == 1){
                    if(map[i - 1][j] == 0) air++;
                    if(map[i + 1][j] == 0) air++;
                    if(map[i][j - 1] == 0) air++;
                    if(map[i][j + 1] == 0) air++;
                    if(air >= 2)   {
                        map[i][j] = 0;
                        cheese_num--;
                    }
                }
                
            }
        } 
        if(cheese_num <= 0) break;
        t++;

        int q_size = q.size();
        for(int i = 0; i < q_size; i++){
            int y = q.front().first;
            int x = q.front().second;
            q.pop();
            // false : 0으로 바꾸기 true 계속 빈공간
            bool flag = false;
            if(map[y - 1][x] && map[y][x - 1]) {
                //오른쪽 방향
                int k;
                for(k = x + 1; k < m; k++){
                    if(map[y][k] == 2) continue;
                    if(map[y][k] == 0) break;
                    if(map[y][k] > 0) flag = true; break; 
                }
                if(k == m) flag = true; break;
                //아래 방향
                for(k = y + 1; k < m; k++){
                    if(map[k][x] == 2) continue;
                    if(map[k][x] == 0) break;
                    if(map[k][x] > 0) flag = true; break; 
                }
                if(k == n) flag = true; break;
            }

            if(flag) {
                q.push({y, x});
            }
            else {
                map[y][x] = 0;
            }
        }
    }  

    cout << t << endl; 
}