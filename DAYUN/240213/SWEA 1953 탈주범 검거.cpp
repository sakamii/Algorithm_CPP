#include<iostream>
#include<cstring>
#include<vector>
#include<queue>

using namespace std;

int map[50][50];
bool visited[50][50];
vector<int> tunnel_el_y[8];
vector<int> tunnel_el_x[8];
int N, M, L;
int result;

void make_tunnel_el();

int main(int argc, char** argv)
{
    make_tunnel_el();
	int test_case;
	int T;
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
        result = 0;
        int R, C;
        cin >> N >> M >> R >> C >> L;
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                cin >> map[i][j];
            }
        }
        memset(visited, false, sizeof(visited));
        visited[R][C] = true;
        result++;

        priority_queue<pair<int, pair<int, int>>> pq;
        pq.push({-1, {R, C}});
        while(!pq.empty())
        {
            int num = -pq.top().first;
            int y = pq.top().second.first;
            int x = pq.top().second.second;
            int el = map[y][x];
            pq.pop();
            
            if(num == L) continue;

            for(int i = 0; i < tunnel_el_y[el].size(); i++) {
               int next_y = y + tunnel_el_y[el][i];
               int next_x = x + tunnel_el_x[el][i];

                //nex_y next_x 와 y, x가 연결 되어 있는지 확인
                bool flag = false;
                int next_el = map[next_y][next_x];
                for(int i = 0; i < tunnel_el_y[next_el].size(); i++) {
                    if((y == (next_y + tunnel_el_y[next_el][i])) && (x == (next_x + tunnel_el_x[next_el][i]))) {
                        flag = true;
                        break;
                    }
                }
                if(!flag) continue;

                if((next_y >= 0) && (next_y < N) && (next_x >= 0) && (next_x < M) && (!visited[next_y][next_x])) {
                    visited[next_y][next_x] = true;
                    result++;
                    pq.push({-num - 1, {next_y, next_x}});
                }
            }
            
        }


        cout << "#" << test_case << " " << result <<endl;
	}
	return 0;

void make_tunnel_el() {
    tunnel_el_y[1] = {-1, 0, 1, 0};
    tunnel_el_x[1] = {0, 1, 0, -1};
    tunnel_el_y[2] = {-1, 1};
    tunnel_el_x[2] = {0, 0};
    tunnel_el_y[3] = {0, 0};
    tunnel_el_x[3] = {1, -1};
    tunnel_el_y[4] = {-1, 0};
    tunnel_el_x[4] = {0, 1};
    tunnel_el_y[5] = {0, 1};
    tunnel_el_x[5] = {1, 0};
    tunnel_el_y[6] = {1, 0};
    tunnel_el_x[6] = {0, -1};
    tunnel_el_y[7] = {-1, 0};
    tunnel_el_x[7] = {0, -1};
}