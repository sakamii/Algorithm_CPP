#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

/*
    그리디? 1년치 이용권 1~12월의 정보를 모두 비교해 보아야하기 때문에 패스
    DP? 100%가능하다고 생각하지만 역량 부족으로 패스
    범위가 1 ~ 12월, 이용권 경우의수 4가지 밖에 없기 때문에
    backtracking으로 해결 가능하다고 생각하고 접근
*/

vector<int> fee;
vector<int> year;

int T, ans;

void solution(int x, int sum) {
    if (x > 12) {

        ans = min(ans, sum);
        return;
    }

    for (int i = 0; i < fee.size(); i++) {
        if (sum >= ans) continue;

        if (year[x] != 0) {
            if (i == 0) solution(x + 1, sum + fee[i] * year[x]);
            else if (i == 1) solution(x + 1, sum + fee[i]);
            else if (i == 2) solution(x + 3, sum + fee[i]);
            else if (i == 3) solution(x + 12, sum + fee[i]);
        }
        else solution(x + 1, sum);

    }

}

void input() {

    ans = 2134567890;
    year.push_back(0);

    for (int i = 0; i < 4; i++) {
        int c;
        cin >> c;
        fee.push_back(c);
    }

    for (int i = 0; i < 12; i++) {
        int m;
        cin >> m;
        year.push_back(m);
    }

}

int main() {

    cin >> T;

    for (int t = 1; t <= T; t++) {

        input();

        solution(1, 0);


        cout << "#" << t << " " << ans << endl;

        fee.clear();
        year.clear();
    }


    return 0;
}
