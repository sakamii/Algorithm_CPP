#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
vector<vector<int>> work, from;
vector<int> dpA, dpB;

int main(int argc, char** argv) {
    cin >> N;
    dpA.resize(N + 1); dpB.resize(N + 1);
    work.resize(2, vector<int>(N + 1)); from.resize(2, vector<int>(N + 1));
    int A, B, fromA2B, fromB2A;
    for(int i = 1; i <= N - 1; i++) {
        cin >> A >> B >> fromA2B >> fromB2A;
        work[0][i] = A;
        work[1][i] = B;
        from[0][i] = fromA2B;
        from[1][i] = fromB2A;
    }
    cin >> A >> B;
    work[0][N] = A;
    work[1][N] = B;

    A = 0; B = 1;
    dpA[1] = work[A][1];
    dpB[1] = work[B][1];
    
    for(int i = 2; i <= N; i++) {
        // A -> A, B -> A
        dpA[i] = min(dpA[i - 1], dpB[i - 1] + from[B][i - 1]);
        dpA[i] += work[A][i];
        // B -> B, A -> B
        dpB[i] = min(dpB[i - 1], dpA[i - 1] + from[A][i - 1]);
        dpB[i] += work[B][i];
    }
    cout << min(dpA[N], dpB[N]);
    return 0;
}