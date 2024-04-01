#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

/*
    민코딩에서 풀어봤던 문제였기 때문에 쉽게 해결함
    안풀어 봤더라면 이진탐색으로 문제를 해결하려고 했을 거 같음
    중간 값을 찾는 문제라면 우선순위큐 2개 사용하는 방법을 떠올려볼것!
*/

priority_queue<int, vector<int>, greater<int>> q;
priority_queue<int> p;


vector<int> v;
int n, m;
int mid;


int main() {
    ios::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);

    cin >> n;


    v.resize(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }

    mid = v[1];

    for (int i = 2; i <= n; i++) {
        if (mid > v[i]) {
            p.push(v[i]);
        }
        else q.push(v[i]);



        if (p.size() > q.size()) {
            q.push(mid);
            mid = p.top();
            p.pop();
        }
        else if (p.size() + 1 < q.size()) {
            p.push(mid);
            mid = q.top();
            q.pop();
        }

        v[i] = mid;
    }

    for (int i = 1; i <= n; i++) {
        cout << v[i] << "\n";
    }


    return 0;
}
