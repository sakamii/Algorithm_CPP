/*
  dfs 
  0. 벽과 함께 가게도 숫자로 처리한다.  
  1. 시작 위치 부터 한칸 씩 가며  지나간 곳은 벽(1) 처리 한다. (0만 지나갈 수 있음)
  2. 그 후 다음 가게를 마주치면 store변수를 증가 시켜 다음 가게를 찾도록 한다.
  3 더이상 갈 곳이 없거나 순서대로 최종 가게에 도착하면 리턴한다.
  4. 리턴 되면 지나간 곳을 다시 0 처리 한다.
*/

#include<iostream>


using namespace std;

int map[4][4];
int stores[16][2];
int result = 0;
int ydir[4] = {-1, 1, 0, 0};
int xdir[4] = {0, 0, -1, 1};
int n, m;

void dfs(int store, int y, int x);

int main(int argc, char** argv)
{
    //소프티어에서 잊지 않기!!
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> map[i][j];
        }
    }

    for(int i = 0; i < m; i++) {
        cin >> stores[i][0] >> stores[i][1];
        stores[i][0]--;
        stores[i][1]--;
        map[stores[i][0]][stores[i][1]] = i + 1;
        
    }
    dfs(2, stores[0][0], stores[0][1]);

    cout << endl;
    cout << result;
   return 0;
}

void dfs(int store, int y, int x) {
    if(store == (m + 1)) {
        result++;
        return;
    }
    
    for(int i = 0; i < 4; i++) {
        int nexty = y + ydir[i];
        int nextx = x + xdir[i];
        if((nexty < n) && (nextx < n) && (nexty >= 0) && (nextx >= 0)) {
            if(map[nexty][nextx] == 0) {
                map[nexty][nextx] = 1;
                dfs(store, nexty, nextx);
                map[nexty][nextx] = 0;
            }
            // == 확인하기 ..
            else if(map[nexty][nextx] == store) {
                dfs(store + 1, nexty, nextx);
            }
        }        
    }
    
}