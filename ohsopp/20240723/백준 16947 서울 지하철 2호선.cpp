#include <iostream>
#include <vector>
#include <queue>
#define N 3001
using namespace std;

vector<int> gr[N];
int n, c[N], cy[N], w[N];

void f() {
    queue <int> q;
    for (int i = 1; i <= n; i++)
        if (c[i] == 1)
            cy[i] = 1, q.push(i);
    while (q.size()) {
        int x = q.front();
        q.pop();
        for (int i : gr[x])
            if (--c[i] == 1 && !cy[i])
                cy[i] = 1, q.push(i);
    }
}

void f(int p, int q, int we) {
    for (int i : gr[p])
        if (i ^ q && cy[i])
            w[i] = we, f(i, p, we + 1);
}

int main() {
    cin >> n;
    for (int o = 0, i, j; o++ < n; c[i]++, c[j]++) {
        cin >> i >> j;
        gr[i].push_back(j);
        gr[j].push_back(i);
    }

    f();
    for (int i = 1; i <= n; i++)
        if (!cy[i]) f(i, i, 1);
    
    for (int i = 1; i <= n; cout << w[i++] << " ");
}
