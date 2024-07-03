/*
    물병의 비트로 바꿨을 때 1의 갯수 : 최소 물병 갯수
    -1이 나오는 경우 없다?
    최소 물병의 갯수 가 k보다 클 때
    1. 앞자리 수부터 1의 갯수를 센다. (k만큼)
    2. 해당위치 에서 큰 자리 수 중에서 제일 가까운 0을 찾는다.
    3. 원래수 와 & -> 최종 1l 물병수
*/

#include <iostream>
#include <bitset>

using namespace std;

int main()
{
    unsigned int n, k;

    cin >> n >> k;
    int num_jar = 0;

    if(n < k){
        cout << 0;
        return 0;
    }

    int i;
    for(i = 1; i < n; i <<= 1){
        if(i & n) {
            num_jar++;
        }
    }

    if(num_jar <= k){
        cout << 0;
        return 0;
    }

    int save_jar  = k;
    int j;
    for(j = (i >> 1); j >= 0; j >>= 1) {
        if(n & j) {
            save_jar--;
            if(save_jar == 0) break;
        }
    }

    for(; j <= i; j <<= 1){
        if((j & n) == 0) {
            break;
        }
    }

    if(j == i) cout << j - n << "\n";
    else {
        unsigned int nj = n | j;
        j = i - j;
        cout << (j & nj) - n <<"\n";
    }

}