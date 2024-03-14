/*
    1. 모든 행과 열에 대해 더한 값을 미리 저장해준다.
    2. 따로 저장하지 않고 그 더한 값을 더해 결과를 print한다.
*/

#include<iostream>
#include<vector>

using namespace std;

vector<int> vr;
vector<long long> vc;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, q;
    cin >> n >> m >> q;
    vr.resize(n + 1);
    vc.resize(m + 1);

    for(int i = 0; i < q; i ++) {
        int a, b, c;
        cin >> a >> b >> c;
        if(a == 1) {
            vr[b] += c; 
        }
        else if(a == 2){
            vc[b] += c;
        }
    }
//50 000 000
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cout << vr[i] + vc[j] << " ";
        }
        // endl하면 시간초과.....
        // cout << endl;
        cout << "\n";
    }
}