#include <iostream>

using namespace std;

long long  m, n;
long long t[100000];

int main() {
    //3079 입국심사
    //상근이 오스트레일리아 여행
    //친구 M명 입국 심사대 N 사람마다 심사 시간 Tk
    //맨 처음 심사대 는 비ㅓㅇ 있다.
    // 심사 최소값
    cin >> n >> m;
    for (long long i = 0; i < n; i++) {
        cin >> t[i];
    }

    //bynary search
    long long maxt = 1000000000000000000;
    long long mint = 0;
    long long result = 0;
    while (mint <= maxt) {
        long long mt = 0;
        long long midt = (maxt + mint) / 2;
        //cout << midt << endl;
        for (long long i = 0; i < n; i++) {
            mt += (midt / t[i]);
        }
        if (mt >= m) {
            maxt = midt - 1;
            result = midt;
        }
        else {
            mint = midt + 1;
        }

    }

    cout << result;

}