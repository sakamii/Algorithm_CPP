
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int t, n, x, y, d, k, ans, arr[4001][4001];

typedef struct {
    int x, y;
}point;

typedef struct {
    point p;
    int d, k;
}atom;

vector<atom> v;
queue<point> q;
int dx[] = {0,0,-1,1}, dy[]={1,-1,0,0};

int main() {
    cin >> t;

    for (int tc = 1; tc <= t; tc++) {
        cin >> n;
        ans = 0;
        for (int i = 1; i <= n; i++) {
            cin >> x >> y >> d >> k;
            v.push_back({{(x + 1000) * 2,(y + 1000) * 2},d,k});
        }

        vector<atom>::iterator it;

        for (int z = 0; z <= 4000; z++) {
            for (it = v.begin(); it != v.end();) {
                it->p.x += dx[it->d];
                it->p.y += dy[it->d];

                if (it->p.x < 0 || it->p.y < 0 || it->p.x >= 4000 || it->p.y >= 4000) {
                    it = v.erase(it);
                    continue;
                }
                arr[it->p.y][it->p.x]++;
                it++;
            }

            for (it = v.begin(); it != v.end();) {
                if (arr[it->p.y][it->p.x] > 1) {
                    ans += it->k;
                    q.push(it->p);
                    it = v.erase(it);
                    continue;
                }
                arr[it->p.y][it->p.x] = 0;
                it++;
            }

            while(!q.empty()){
                arr[q.front().y][q.front().x] = 0;
                q.pop();
            }
        }

        cout << "#" << tc << " " << ans << endl;
        v.clear();
    }
}
