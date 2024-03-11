// @START 24.03.11:15:33
// @END 24.03.11:19:29
// @TOTAL 4MIN
// @FAIL 1

#include <iostream>

using namespace std;

int N, M, cnt;
int vect[1000001];

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        cin >> vect[i];
        if (vect[i] == 1) {
            cnt++;
            int left = i - 1;
            int right = i + 1;

            if (left != 0 && vect[left] == 1) {
                cnt--;
            }
            if (right != N + 1 && vect[right] == 1) {
                cnt--;
            }
        }
    }

    for (int i = 0; i < M; i++) {
        int type;
        cin >> type;
        if (type == 1) {
            int target;
            cin >> target;
            if (vect[target] == 1) continue;
            vect[target] = 1;
            cnt++;

            int left = target - 1;
            int right = target + 1;

            if (left >= 0 && vect[left] == 1) {
                cnt--;
            }
            if (right <= N && vect[right] == 1) {
                cnt--;
            }
        }
        else {
            cout << cnt << "\n";
        }
    }
    return 0;
}
