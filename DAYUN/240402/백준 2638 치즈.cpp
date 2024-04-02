#include <iostream>
#include <queue>

using namespace std;

int map[100][100];
bool hole[100][100];
int cheese_num = 0;
queue<pair<int, int>> q;
queue<pair<int, int>> erase_q;
int cnt = 0;

void dfs(int y, int x);

int main(){
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> map[i][j];
            cheese_num +=  map[i][j];
        }
    }

    for(int i = 0; i < n; i++){
        hole[i][0] = true;
        hole[i][m - 1] = true;
    }    
    
    for(int i = 0; i < m; i++){
        hole[0][i] = true;
        hole[n - 1][i] = true;
    }  

    for(int i = 1; i < (n - 1); i++){
        for(int j = 1; j < (m - 1); j++) {
            if(map[i][j] == 0) {
                if(hole[i - 1][j] || hole[i][j - 1]) {
                    hole[i][j] = true;
                }
            }
        }
    }

    for(int i =  n - 1; i > 0; i--){
        for(int j = m - 1; j > 0; j--) {
            if(map[i][j] == 0) {
                if(hole[i + 1][j] || hole[i][j + 1]) {
                    hole[i][j] = true;
                }
            }
        }
    }

    for(int i =  n - 1; i > 0; i--){
        for(int j = m - 1; j > 0; j--) {
            if(map[i][j] == 0 && !hole[i][j]) {
                map[i][j] = 2;
                q.push({i, j});
            }
        }
    }

    int t = 0;
    while(true){
        // cout << "\n";
        // for(int i = 0; i < n; i++) {
        //     for(int j = 0; j < m; j++) {
        //         cout << map[i][j] << " ";
        //     }
        //     cout << "\n";
        // }
        
        if(cheese_num <= 0) break;
        t++;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                int air = 0;
                //4칸 중에 2칸 이상이 공기 일 경우, 소멸
                if(map[i][j] == 1){
                    if(map[i - 1][j] == 0) air++;
                    if(map[i + 1][j] == 0) air++;
                    if(map[i][j - 1] == 0) air++;
                    if(map[i][j + 1] == 0) air++;
                    if(air >= 2)   {
                        erase_q.push({i, j});
                        hole[i][j] = true;
                        cheese_num--;
                    }
                }
                
            }
        } 




        while(!erase_q.empty()){
            map[erase_q.front().first][erase_q.front().second] = 0;
            erase_q.pop();
        }


        int q_size = q.size();
        for(int i = 0; i < q_size; i++){
            int y = q.front().first;
            int x = q.front().second;
            q.pop();
            // false : 0으로 바꾸기 true 계속 빈공간
            bool flag = false;
            if(hole[y][x]) continue;
            if(hole[y - 1][x] || hole[y + 1][x] || hole[y][x - 1] || hole[y][x + 1]) {
                dfs(y, x);
            } 
            else {
                q.push({y, x});
            }
        }
    }  

    cout << t << endl; 
}

void dfs(int y, int x) {
    map[y][x] = 0;
    hole[y][x] = true;
    if(map[y - 1][x] == 2) dfs(y - 1, x);
    if(map[y + 1][x] == 2) dfs(y + 1, x);
    if(map[y][x - 1] == 2) dfs(y, x - 1);
    if(map[y][x + 1] == 2) dfs(y, x + 1);
} 