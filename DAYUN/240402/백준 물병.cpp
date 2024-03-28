/*
    물병의 비트로 바꿨을 때 1의 갯수 : 최소 물병 갯수
    1부터 셋을 때 1의 갯수 가 원하는 수를 충족했을때 그 이후로 나오는 숫자 중 0이 나오는 경우
    그때 +1 하고 나온 수 - 기존의 수 // 아래 자리만
*/

#include <iostream>

using namespace std;

int main()
{

    int result = 0;
    int n, k;

    cin >> n >> k;
    if (k < n)
    {

        int jar = 0;
        int i;
        for (i = 1; i < n; i <<= 1) {}
        int max_2pow = i;
        while(k != jar) {
            i >>= 1;
            if(i == 0) break;
            if(i & n) jar++;
        }

        if(k )


        if (jar > k)
        {
            int cnt = 0;
            bool flag = false;
            for (int i = 1;; i <<= 1)
            {
                //11001010
                //만약 두개의 1을 1개의 1로 만들고 싶다 
                // 11010000

                 if (i & n)
                {
                    cnt++;
                    if ((jar - k) == (cnt + 1))
                    {
                        flag = true;
                    }
                }
                else if(flag){
                    result = i - ((i - 1) & n);
                    break;
                }
                else if(i > n) {
                    result = i - n;
                    break;
                }
            }
        }
    }

    cout << result;
}