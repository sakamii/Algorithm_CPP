#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <deque>
#include <math.h>
#include <string>
#include <stack>
#include <set>
using namespace std;

int n, m;
/*
for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        if ((m - (max(a, b))) >= abs(a - b) - 1)
            cout << 1 << "\n";
        else
            cout << 0 << "\n";
    }
처음에 영희와 동수가 같은 턴을 사용한다고 생각하고 단순히 max로 풀었지만
영희가 무조건 먼저 시작한다는 뜻을 다르게 해석해야했다.

영희가 먼저 시작한다 -> 동수보다 1턴을 더 많이 쓴다는 뜻

그래서 케이스를 나눠서 풀어야함

영희 > 동수 => 동수는 아직 동전을 던지지 않았다고 가정할수 있음. 그래서 턴이 2개가 남음
영희 < 동수 => 영희는 이미 동전을 던짐. 그래서 턴이 1개밖에 남지 않음.

남은 턴 => k - max(m,n)
영희 > 동수 : 남은 턴 - 둘 점수의 차 <= 2
영희 < 동수 : 남은 턴 - 둘 점수의 차 <= 1
*/
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> m >> n;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        if (a == b)
        {
            cout << 1 << "\n";
            continue;
        }
        int rest = m - max(a, b);
        int diff = abs(a - b);
        if (a > b)
        {
            if (diff - rest <= 2)
                cout << "1\n";
            else
                cout << "0\n";
        }
        else
        {
            if (diff - rest <= 1)
                cout << "1\n";
            else
                cout << "0\n";
        }
    }
}