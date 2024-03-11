/*
영희 점수: a, 동수 점수: b
영희가 동수보다 먼저 던지기 때문에 영희는 남은 라운드(r), 동수는 남은 라운드(r) + 1 만큼 더 점수를 얻을 수 있다.
나머지 라운드를 동수나 영희가 모두 이기는 경우의 점수차가 1보다 큰 점수는 될 수 없다. => 이미 끝나야 하기 때문
*/

#include <iostream>
using namespace std;

int k, c, a, b, r;

int main() {
    cin >> k >> c;
    for (int i = 0; i < c; i++) {
        scanf("%d %d", &a, &b);
        r = k - max(a, b);
        if (a - (r + b + 1) > 1 || b - (r + a) > 1)
            cout << "0\n";
        else cout << "1\n";
    }
}
