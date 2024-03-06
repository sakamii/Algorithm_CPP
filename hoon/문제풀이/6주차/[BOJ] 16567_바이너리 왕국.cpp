#include <iostream>
#include <vector>
using namespace std;
int n, m;
/*
직선 좌표계에서만 고려하면 되는 문제라서 양옆의 있는 값들만 비교해서 1이면 cnt를 빼주면 끝
다만 시작 n 배열이 전부 0이 아니기 때문에
인풋을 받으면서 초기값 세팅이 필수.

또한 이미 1인곳의 좌표가 중복으로 주어지는 경우도 있어서
이미 1인곳은 continue 해주면 끝
*/
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    vector<int> v;
    v.resize(n);
    int flip_cnt = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        if (v[i] == 1)
        {
            flip_cnt += 1;
            if (i > 0 && v[i - 1] == 1)
                flip_cnt -= 1;
        }
    }
    for (int i = 0; i < m; i++)
    {
        int a;
        cin >> a;
        if (!a)
            cout << flip_cnt << "\n";
        else
        {
            int b;
            cin >> b;
            b = b - 1;
            if (v[b] == 1)
                continue;
            flip_cnt += 1;
            v[b] = 1;
            if (b > 0 && v[b - 1] == 1)
                flip_cnt -= 1;
            if (b < n - 1 && v[b + 1] == 1)
                flip_cnt -= 1;
        }
    }
}