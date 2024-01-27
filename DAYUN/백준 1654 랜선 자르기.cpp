#include<iostream>
#include <climits>

using namespace std;

int main() {
    //성원 - N개의 랜선 만들기
    //영식 - 가지고 있는 k개 랜선 길이 각각
    //랜선은 N개의 같은 길이 랜선 0> 랜선 자르기
    //bynarysearch

    int k, n;
    int young[10000];
    long long max = INT_MAX;
    long long min = 1;

    cin >> k >> n;

    for(int i = 0; i < k; i++)
    {
        cin >> young[i];
    }

    long long result = 0;
    while(min <= max)
    {
        long long mid = (min + max) / 2;
        long long nl = 0;

        for(int i = 0; i < k; i++) {
            nl += young[i]/mid;
        }

        if(nl >= n) {
            min = mid + 1;
            result = mid;
        }
        else if(nl < n) {
            max = mid - 1;
        }
    }
    cout  << result << endl;


}