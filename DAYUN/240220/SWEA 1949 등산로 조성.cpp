
// SWEA 1949 등산로 조성
/// 막힌다 -> flag 1사용 -> 두번쨰 막힘 -> return  max 계산

#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

int N, K;
int result;
int map[8][8];
//가장 높은 지형이 존재하는 위치 
int highest[5][2];
//방향 : 시계방향 상우하좌
int ydir[4] = {-1, 0, 1, 0};
int xdir[4] = {0, 1, 0, -1}; 
bool visited[8][8];
//깍는 것을 사용했는지 
bool flag;

int dfs(int y, int x, int route);

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
        memset(visited, false, sizeof(visited));
        result = 0;
        cin >> N >> K;
        int num_high = 0;
        int high = 0;
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                cin >> map[i][j];
                if(map[i][j] > high) {
                    highest[0][0] = i;
                    highest[0][1] = j;
                    high = map[i][j];
                    num_high = 1;
                }
                else if(map[i][j] == high) {
                    highest[num_high][0] = i;
                    highest[num_high][1] = j;
                    num_high++;
                }
            }
        }

        for(int h = 0; h < num_high; h++) {
            flag = false;
            dfs(highest[h][0], highest[h][1], 1);
        }

        cout << "#" << test_case << " " << result <<endl;
	}
	return 0;
}

int dfs(int y, int x, int route) {
    visited[y][x] = true;
    for(int i = 0; i < 4; i++) {
        int next_y = y + ydir[i];
        int next_x = x + xdir[i];

        if((next_y >= 0) && (next_y < N) && (next_x >= 0) && (next_x < N)) {
            if((map[next_y][next_x] < map[y][x])) {
                dfs(next_y, next_x, route + 1);
            }
            // 등산로 공사
            else if(((map[next_y][next_x] - K) < map[y][x]) && (flag == false) && !visited[next_y][next_x]) {
                int mm = map[next_y][next_x];
                flag = true;
                map[next_y][next_x] = map[y][x] - 1;
                dfs(next_y, next_x, route + 1);
                map[next_y][next_x] = mm;
                flag = false;
            }
        }
        
    }
    visited[y][x] = false;
    //매번 막혔을 경우 제일 긴 루트인지 확인한다. 
    result = max(result , route);
    return 0;
}