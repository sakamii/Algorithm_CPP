#include <iostream>
#include <algorithm>

using namespace std;

const unsigned int MAX = 1 << 31;
const int LEN = 502;

unsigned int memo[LEN][LEN];
unsigned int matrix[LEN][2];

unsigned int devide_conquer(int s, int e);

int main(){
    int n;
    cin >> n;
    fill(&memo[0][0], &memo[n - 1][n], MAX);
    for(int i = 0; i < n; i++) {
        cin >> matrix[i][0] >> matrix[i][1];
    }

    for(int i = 0; i < (n - 1); i++) {
        memo[i][i + 1] = matrix[i][0] * matrix[i][1]  * matrix[i + 1][1];
    }
    
    if( n == 1) {
        cout << 1;
        return 0;
    }

    cout <<  devide_conquer(0, n - 1) << endl;
}

unsigned int devide_conquer(int s, int e) {
    if(s == e)
        return 0;
    if(memo[s][e] != MAX)
        return memo[s][e];

    unsigned int dc = MAX;
    for(int i = s; i < e; i++) {
        dc = min(dc, matrix[s][0] * matrix[i][1] * matrix[e][1] + devide_conquer(s, i) + devide_conquer(i + 1, e));
    }
    memo[s][e] = dc;
    return dc;
}