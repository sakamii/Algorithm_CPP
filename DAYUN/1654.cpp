#include<iostream>

using namespace std;

int main() {
    //성원 - N개의 랜선 만들기
    //영식 - 가지고 있는 k개 랜선 길이 각각
    //랜선은 N개의 같은 길이 랜선 0> 랜선 자르기
    //bynarysearch

    int k, n;
    int young[10000];
    int max = 0;
    int min = 0;

    cin >> k >> n;

    for(int i = 0; i < k; i++)
    {
        cin >> young[i];
        if(max < young[i])
        {
            max = young[i];
        }
    }

    int result = 0;
    while(min < max)
    {
        int mid = (min + max) / 2;
        int nl = 0;

        for(int i = 0; i < k; i++) {
            nl += young[i]/mid;
        }

        if(nl >= n) {
            min = mid + 1;
        }
        else if(nl < n) {
            max = mid - 1;
        }
        if(nl == n)
        {
            result = mid;
        }

    }
    cout  <<result << endl;


}