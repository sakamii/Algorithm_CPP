#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;

struct node {
    int y;
    int x;
    int d;
    int k;
};

vector<node> v;

int visited[5001][5001];
int T, N, ans, flag;
int dir[4][2] = { {1,0}, {-1, 0}, {0,-1}, {0,1} };

void solution(int sol) {

    while (1) {

        int len = v.size();

        flag = 1;
        for (int i = 0; i < len; i++) {
            node now = v[i];
           
            int dy = now.y + dir[now.d][0];
            int dx = now.x + dir[now.d][1];

            if (dy == 5000 || dx == 5000) continue;
            visited[now.y][now.x] -= 1;
            if (dy > 4000 || dx > 4000 || dy < 0 || dx < 0) continue;
    
            visited[dy][dx] += 1;     
            v[i] = { dy, dx, now.d, now.k };
            flag = 0;
        }

        if (flag == 1) break;

        for (int i = 0; i < len; i++) {
            if (visited[v[i].y][v[i].x] > 1) {
                ans += v[i].k;
                visited[v[i].y][v[i].x] = 0;
                
                for (int j = 1 + i; j < len; j++) {
                    if (v[j].y == v[i].y && v[j].x == v[i].x) {
                        ans += v[j].k;
                        v[j].y = 5000; v[j].x = 5000;
                    }
                }
                v[i].y = 5000; v[i].x = 5000;
            }
        }
    }
}

void input(int x) {

    cin >> N;

    ans = 0;
    flag = 0;
    

    for (int i = 0; i < N; i++) {
        int X, Y, DIR, K;
        cin >> X >> Y >> DIR >> K;
        X = (X + 1000) * 2;
        Y = (Y + 1000) * 2;
        v.push_back({ Y, X, DIR, K });
        visited[Y][X] = 1;
    }
    
}

int main() {

    cin >> T;

    for (int t = 1; t <= T; t++) {

        input(0);

        solution(0);

        cout << "#" << t << " " << ans << endl;
        v.clear();
    }


    return 0;
}
