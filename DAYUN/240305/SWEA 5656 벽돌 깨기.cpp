/*
    구슬 벽돌
    구슬은 좌우로만 움직일 수 있음
    항상 맨 위의 벽돌만 깨트림
    벽돌은 1~9로 표현
    구슬이 명중한 벽돌은 상하좌우 -1칸 만큼 제거
    벽돌 밑으로 떨어짐
*/

#include<iostream>
#include<cstring>
#include<queue>

using namespace std;

int n, w, h;
int result;
int loc[4];
int map[15][12];
int copy_map[15][12];
int ydir[4] = {-1, 1, 0, 0};
int xdir[4] = {0, 0, -1, 1};

void dfs(int level);
void boom();
void erase(int y, int x, int info);

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        result = 1e9;
        cin >> n >> w >> h;
        for(int i = 0; i < h; i++) {
            for(int j = 0; j < w; j++) {
                cin >> map[i][j];
            }
        }
        
        memcpy(copy_map, map, sizeof(map));
        dfs(0);

        cout << "#" << test_case << " " << result <<endl;
	}
	return 0;
}

void dfs(int level) {
    // cout << level << " " << n << endl;
    if(level == n) {
        //count block
        // cout << cnt++ << " ";
        boom();

        return;
    }

    for(int i = 0; i < w; i++) {
        loc[level] = i;
        dfs(level + 1);
    }

    return;
}

void boom() {
    // cnt++;
    // if(cnt > 900)  {
    //     cout << endl;
    //     for(int i = 0; i < n; i++) {
    //         cout << loc[i] << " ";
    //     }
    //     cout << endl;
    // }
    
    for(int l = 0; l < n; l++) {
        queue<pair<int, int>> q;
        int y = h - 1;

        while(copy_map[y][loc[l]] == 0){
            y--;
            if(y < 0) break;
        }
        cout << y << " ";
        if(y < 0) return;
        int info = copy_map[y][loc[l]];
        copy_map[y][loc[l]] = 0;
        if(info > 1) {
            erase(y, loc[l], info);

            for(int j = 0; j < w; j++) {
                for(int i = h - 1; i >= 0; i--) {
                    
                    if(copy_map[i][j] == 0) {
                        int tempi = i;
                        while(copy_map[tempi][j] == 0) {
                            tempi--;
                            if(tempi < 0) break;
                        }
                        if(tempi < 0) break;
                        copy_map[i][j] =  copy_map[tempi][j];
                        copy_map[tempi][j] = 0;
                    }
                    
                    
                }
            }

        }
        

    }


    int count = 0;
    for(int j = 0; j < w; j++) {
        for(int i = h - 1; i >= 0; i--) {
            if(copy_map[i][j] > 0) count++;
            else break; 
        }   
    }      


    if(result > count) {
        cout << endl;
        cout << count << endl;

        for(int i = 0; i < h; i++) {
            for(int j = 0; j < w; j++) {
                cout << copy_map[i][j] << " ";
            }
            cout << endl;
        }       
    }
    result = min(count, result);
    memcpy(copy_map, map, sizeof(map));
}

void erase(int y, int x, int info) {
    for(int dir = 0; dir < 4; dir++) {
        for(int i = 1; i < info; i++) {
            int next_y = y + ydir[dir] * i;
            int next_x = x + xdir[dir] * i;

            if(next_y < h && next_y >= 0 && next_x < w && next_x >= 0) {
                int next_info = copy_map[next_y][next_x];
                copy_map[next_y][next_x] = 0;

                if(next_info > 1) {
                    erase(next_y, next_x, next_info);
                }
            }
            else {
                break;
            }
        }   
    } 
}