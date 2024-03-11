/*
개미가 움직이는 시간이 최대 2억까지 들어오므로 입력값 그대로 반복문 돌면 시간초과 발생.
시간이 너비의 2배, 높이의 2배의 배수일 때는 시작지점과 동일.
따라서 너비, 높이로 각각 나머지 계산을 통해 남은 시간만큼만 반복문 진행.
처음에 무조건 오른쪽 위로 움직이기 때문에 ofs은 1로 초기화.
개미가 맵의 끝부분에 도달했을때는 진행방향을 반대로 바꿔주기.
*/

#include <iostream>
using namespace std;

int w, h, p, q, t, pt, qt, ofs;

int main() {
    cin >> w >> h >> p >> q >> t;

    pt = t % (2 * w);
    qt = t % (2 * h);

    ofs = 1;
    while (pt--) {
        if (p == w || !p) ofs *= -1;
        p += ofs;
    }

    ofs = 1;
    while (qt--) {
        if (q == h || !q) ofs *= -1;
        q += ofs;
    }

    cout << p << " " << q;
}
