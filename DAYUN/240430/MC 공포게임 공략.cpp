/*
    1. 이동하는 최소의 루트를 찾는다.
    2. 최소의 루트의 모든 경우의 수를 찾는다.
    3. 귀신이 만약 홀수/짝수 고려할떄 아니면 패스 한다.
    4. 귀신이 이동하면서 해당 시간동안 부딛히지 않고 움직일 수 있는지 확인한다.

*/

#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int N, M;
int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int map[100][100];
int visited[100][100] = {false};
pair<int, int> end_point;
queue<pair<int, int>> q_person, q_ghost;


void init();
bool possible();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;
    for(int test_case = 1; test_case <= T; ++test_case) {
        int result = -1;
        bool flag = false;
        init();

        if(!possible()) {
            cout << "#" << test_case << " " << result << "\n";
            continue;
        }

        int time = 0;
        while(!q_person.empty() ) {
            time++;
            int q_ghost_size = q_ghost.size();
            for(int q = 0; q < q_ghost_size; ++q) {
                int y = q_ghost.front().first;
                int x = q_ghost.front().second;
                q_ghost.pop();
                map[y][x] = 0;
                for(int i = 0; i < 4; ++i) {
                    int next_y = y + dir[i][0];
                    int next_x = x + dir[i][1];
                    if(next_y < 0 || next_y >= N || next_x < 0 || next_x >= M || map[next_y][next_x] == -1 || map[next_y][next_x] == time) continue;
                    map[next_y][next_x] = time;
                    q_ghost.push({next_y, next_x});
                }
            }
            
            int q_person_size = q_person.size();
            for(int q = 0; q < q_person_size; ++q) {
                int y = q_person.front().first;
                int x = q_person.front().second;

                q_person.pop();
                for(int i = 0; i < 4; ++i) {
                    int next_y = y + dir[i][0];
                    int next_x = x + dir[i][1];
                    if(next_y < 0 || next_y >= N || next_x < 0 || next_x >= M || map[next_y][next_x] == -1) continue;
                    if(map[next_y][next_x] == time || map[next_y][next_x] == (-time)) continue;
                    map[next_y][next_x] = -time;
                    if(next_y == end_point.first && next_x == end_point.second) {
                        result = time;
                        q = q_person_size;
                        while(!q_person.empty()) {
                            q_person.pop();
                        }
                        break;
                    }
                    q_person.push({next_y, next_x});
                }
            }
        }
        cout << "#" << test_case << " " << result << "\n";
    }
}

void init() {
    char in;
cin >> N >> M;
    while(!q_ghost.empty()) {
        q_ghost.pop();
    }

    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < M; ++j) {
            cin >> in;
            switch (in)
            {
            case '#':
                map[i][j] = -1;
                break;
            case 'C':
                q_ghost.push({i, j});
                map[i][j] = 0;
                break;
            case '.':
                map[i][j] = 0;
                break;
            case 'E':
                end_point = {i, j};
                map[i][j] = 0;
                break;
            case 'S':
                q_person.push({i, j});
                map[i][j] = 0;
                break;
            default:
                break;
            }
        }
    }
    memset(visited, false, sizeof(visited));
}

bool possible() {
    queue<pair<int, int>>  q;
    q.push(q_person.front());

    while(!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;

        q.pop();
        for(int i = 0; i < 4; ++i) {
            int next_y = y + dir[i][0];
            int next_x = x + dir[i][1];
            if(next_y < 0 || next_y >= N || next_x < 0 || next_x >= M || map[next_y][next_x] == -1 || visited[next_y][next_x]) continue;
            if(next_y == end_point.first && next_x == end_point.second) { return true; }
            q.push({next_y, next_x});
            visited[next_y][next_x] = true;
        }
    }
    
    return false;
}