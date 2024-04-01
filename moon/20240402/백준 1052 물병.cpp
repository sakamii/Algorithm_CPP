#include <iostream>
#include <queue>
using namespace std;

/*
    현재 가지고 있는 물병으로 최대한 합쳤을 때,
    병의 갯수를 최소로 줄이기 위해서는 크기가 작은 물병부터 합치는 것이
    가장 물병을 적게 구매하는 방법이기 때문에 그리디 문제로 생각하고 접근

    13을 이진수로 1101로 표현할 수 있다. 이때 1의 개수가 물병의 개수이다.
    8 + 4 + 1 로 13으로 가장 적게 만들 수 있는 물병의 개수는 3개이다.
    여기서 물병의 개수를 줄일려면 자릿수가 가장 작은 1을 물병을 구매해서 4와 합치는 것이다.

*/

priority_queue<int, vector<int>, greater<int>> q;
int N, K, ans;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> K;

    int cnt = 0;

    // 이진수로 1의 자릿수를 q에 저장
    for (int i = 0; 0 < (N >> i); i++) {
        if ((N >> i) & 1) {
            q.push(i);
            // cnt : 사용된 물병의 수
            cnt++;
        }
    }

    while (cnt > K) {
        int now = q.top();
        q.pop();
        // 자릿수만큼 물병이 필요하기 떄문에 ans++:
        ans += (1 << now);

        // 해당 자릿수가 비어있으면 또 합쳐야 하기 때문에 continue;
        while (q.top() == now + 1) {
            now = q.top();
            q.pop();
            cnt--;
            if (q.empty()) break;
            // 물병의 개수가 K를 만족하면 return;
            if (cnt <= K) {
                cout << ans;
                return 0;
            }
        }
        q.push(now + 1);

    }


    cout << ans;

    return 0;
}
