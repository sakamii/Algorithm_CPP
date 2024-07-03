#include <iostream>
#include <algorithm>

using namespace std;

const unsigned int MAX = 1 << 31;
const int LEN = 502;

unsigned int memo[LEN][LEN];
unsigned int matrix[LEN][2];

unsigned int cal(int s, int e);

int main(){
    int n;
    cin >> n;
    fill(&memo[0][0], &memo[n - 1][n], MAX);
    for(int i = 0; i < n; i++) {
        cin >> matrix[i][0] >> matrix[i][1];
    }

/////////////////////////////////////////////////////////////////////////////////// 
/////////1.두 행렬만 곱하는 경우, 비교할 대상이 없으므로 연산해서 미리 계산해준다. /////
    for(int i = 0; i < (n - 1); i++) {
        memo[i][i + 1] = matrix[i][0] * matrix[i][1]  * matrix[i + 1][1];
    }
/////////////////////////////////////////////////////////////////////////////////// 
    if( n == 1) {
        cout << 1;
        return 0;
    }

    cout <<  cal(0, n - 1) << endl;
}

/////////////////////////////////////////////////////////////////////////////////// 
////////2. cal(s, e) :  index s 부터 e까지 곱할 때, 최소의 곱셈 합을 리턴해준다. /////
unsigned int cal(int s, int e) {
    if(s == e)
        return 0;
    if(memo[s][e] != MAX)
        return memo[s][e];

    unsigned int dc = MAX;
    for(int i = s; i < e; i++) {
        dc = min(dc, matrix[s][0] * matrix[i][1] * matrix[e][1] + cal(s, i) + cal(i + 1, e));
    }
    memo[s][e] = dc;
    return dc;
}
/////////////////////////////////////////////////////////////////////////////////// 