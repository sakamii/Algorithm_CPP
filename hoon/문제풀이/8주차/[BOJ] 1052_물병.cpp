#include <iostream>
using namespace std;

/*
물병 모두가 1로 시작하고, 2 4 8 순서로 합쳐지게됨
=> 비트마스킹 or mod 2연산으로 해결해보자

실패한 방법 : n을 2의 거듭제곱으로 나누면서 나머지가 0이 아니라면, sum에 더해주고 n/2의 거듭제곱 이 2^k 보다 작아지면(그럼 k개로 표현가능) 중단후 sum 출력
ex) 13
13 : 2^0 + 2^1 * 6 => 1더해줌. n=14
14 : 2^1 + 2^2 * 3 => 2^1 더해줌, n=16

==> k가 1000이므로 2^k를 찾을수 없음.

수정한 풀이 : bit를 이용하자.
13 -> 1101 => 8 + 4 + 1 => 3개의 물병으로 표현이 가능하다는뜻
13,2 => 13을 하나씩 늘리면서 bit가 2개 이하가 되는 순간을 출력해주면 됨 => 10000 => 16, 16-13 => 3.
*/

int n,k;
int main(){
    cin >> n >> k;
    if(n <= k){
        cout << 0 << endl;
        return 0;
    }
    int N = n;
    while(true){
        int temp = n;
        int cnt = 0;
        while(temp != 0){
            if(temp % 2 == 1)
                cnt ++;
            if(cnt > k) break;
            temp /= 2;
        }
        if(cnt <= k) break;
        n++;
    }
    cout << n-N << endl;

    return 0;
}