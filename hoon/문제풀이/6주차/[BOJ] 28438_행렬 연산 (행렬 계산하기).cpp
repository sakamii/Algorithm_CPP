#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <string>

using namespace std;
/*
열이 더해지는 값 => 무조건 모든 row에 더해지게 되어있음.
그래서 각 더해지는 쿼리에 대한 정보들의 총합을 각자 행, 열 배열에 저장하고
마지막에 한꺼번에 출력
*/
vector<int> row;
vector<int> colu;
int a, b, c, n, m, q;
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> m >> q;
    row.resize(n);
    colu.resize(m);
    for (int i = 0; i < q; i++)
    {
        cin >> a >> b >> c;
        (a == 1) ? row[b - 1] += c : colu[b - 1] += c;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << row[i] + colu[j] << " ";
        cout << "\n";
    }
    return 0;
}