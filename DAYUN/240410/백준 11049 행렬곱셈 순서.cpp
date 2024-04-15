#include <iostream>
#include <algorithm>

using namespace std;

const unsigned int MAX = 1 << 31;

unsigned int memo[501][501];
unsigned int matrix[501][2];

int devide_conquer(int s, int e);

int main(){
    int n;
    cin >> n;
    fill(&memo[0][0], &memo[n - 1][n], MAX);
    for(int i = 0; i < n; i++) {
        cin >> matrix[i][0] >> matrix[i][1];
    }
    // fill(&matrix[0][0], &matrix[n][0], 1);

    for(int i = 0; i < n; i++) {
        memo[i][i + 1] = matrix[i][0] * matrix[i][1]  * matrix[i + 1][1];
    }
    
    if( n == 1) {
        cout << matrix[0][0] * matrix[0][1];
        return 0;
    }

    cout <<  devide_conquer(0, n - 1) << endl;

    // for(int i = 0; i < n; i++) {
    //     for(int j = 0; j < n; j++){
    //         if(memo[i][j] != MAX)
    //              cout << memo[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // cout <<  devide_conquer(0, n - 1) << endl;
    

}

int devide_conquer(int s, int e) {
    if(memo[s][e] != MAX)
        return memo[s][e];
    
    unsigned int dc = MAX;
    unsigned int temp = matrix[s][0] * matrix[s][1] * matrix[e][1]; 
    if(memo[s + 1][e] != MAX) {
        temp += memo[s + 1][e];
    }
    else {
        temp += devide_conquer(s + 1, e);
    }
    dc = temp;

    temp = matrix[s][0] * matrix[e][0] * matrix[e][1]; 
    if(memo[s][e - 1] != MAX) {
        temp += memo[s][e - 1];
    }
    else {
        temp += devide_conquer(s, e - 1);
    }
    dc = min(dc, temp);

    if(s + 1 == e) return memo[s][e];

    for(int i = s + 2; i < (e - 1); i++) {
        temp = matrix[s][0] * matrix[i][0] * matrix[i][1] + matrix[i][0] * matrix[i][1] * matrix[e][1];
        temp += memo[s][i - 1];
        temp += memo[i + 1][e];

        dc = min(dc, temp);
    }

    memo[s][e] = dc;
    return dc;
}