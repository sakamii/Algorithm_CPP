#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*
    최대 회전 횟수가 N에 따라 고정되어 있고
    N의 최대 크기가 크지 않기 때문에 단순 구현이라 생각 --> 그리디 생각
    for문이 많지만 실제로 돌아가는 횟수 자체는 매우 적음
*/

string str;
vector<char> v;
vector<int> sol;
int T, N, K, M, ans;

int main() {

    cin >> T;

    for (int t = 1; t <= T; t++) {
        cin >> N >> K;

        cin >> str;

        for (int i = 0; i < str.size(); i++) {
            v.push_back(str[i]);
        }

        int size = N / 4;

        for (int r = 0; r < size; r++) {
            for (int i = 0; i < 4; i++) {
                int value = 0;
                for (int j = 0 + i * size; j < size * (i + 1); j++) {
                    // mul은 16진수 자릿수를 의미
                    int mul = 1;
                    for (int k = 1; k < size * (i + 1) - j; k++) {
                        mul *= 16;
                    }
                    // 숫자인 경우
                    if (v[j] >= '0' && v[j] <= '9') value += ((int)v[j] - '0') * mul;
                    // 알파벳인 경우
                    else value += ((int)v[j] - 'A' + 10) * mul;
                }
                // 벡터에 저장
                sol.push_back(value);
            }

            // 회전 시키는 코드
            char temp = v.back();
            for (int j = v.size() - 1; j > 0; j--) {
                v[j] = v[j - 1];
            }
            v[0] = temp;
        }

        // 중복되는 값 제거
        sort(sol.begin(), sol.end());
        for (int i = 1; i < v.size(); i++) {
            if (sol[i] == sol[i - 1]) sol[i] = 0;
        }

        // 내림차순으로 정렬 결과 출력을 위해
        sort(sol.rbegin(), sol.rend());

        cout << "#" << t << " " << sol[K - 1] << endl;
        v.clear();
        sol.clear();
    }

    return 0;
}
