//원자 소멸 시뮬레이션
#include <iostream>
#include <vector>
using namespace std;

struct Atom {
    int x, y, d, K;
    bool done = false;
};

vector<Atom> atoms;
int N, total;
int map[4001][4001] = { 0, };
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0, 0 };

void play() {
    while (true) {
        bool can = true;
        for (int i = 0; i < atoms.size(); i++) {
            if (!atoms[i].done) {
                can = false;
                break;
            }
        }
        if (can) break;

        for (int i = 0; i < atoms.size(); i++) {
            int nx = atoms[i].x + dx[atoms[i].d];
            int ny = atoms[i].y + dy[atoms[i].d];
            //안부딪히고 빠져나갔을때
            if (nx < 0 || nx > 4000 || ny < 0 || ny > 4000) atoms[i].done = true;
            else if (!atoms[i].done) {
                map[ny][nx]++;
                atoms[i].x = nx;
                atoms[i].y = ny;
            }
        }

        //두개이상이면 부딪힌거 검사. 시간초과 날라나
        for (int i = 0; i < atoms.size(); i++) {
            if (map[atoms[i].y][atoms[i].x] > 1) {
                for (int j = 0; j < atoms.size(); j++) {
                    if (atoms[j].done) continue;
                    if (atoms[i].x == atoms[j].x && atoms[i].y == atoms[j].y) {
                        total += atoms[j].K;
                        atoms[j].done = true;
                    }
                }
            }
            map[atoms[i].y][atoms[i].x] = 0;
        }
    }
}

int main() {
    int tc;
    cin >> tc;
    for (int x = 1; x <= tc; x++) {
        total = 0;
        cin >> N;
        for (int i = 0; i < N; i++) {
            Atom atom;
            cin >> atom.x >> atom.y >> atom.d >> atom.K;
            atom.x = 2 * (atom.x + 1000);
            atom.y = 2 * (atom.y + 1000);
            atom.done = false;
            atoms.push_back(atom);
        }
        play();
        cout << '#' << x << ' ' << total << '\n';
        atoms.clear();
    }
}
