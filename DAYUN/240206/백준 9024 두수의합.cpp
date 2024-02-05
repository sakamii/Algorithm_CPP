#include<iostream>
#include<algorithm>

using namespace std;

int arr[1000000];


int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;
    for(int test_case = 0; test_case < T; test_case++)  {
        int t, k;
        cin >> t >> k;
        for(int i = 0; i < t; i++) {
            cin >> arr[i];
        }

        sort(arr, arr + t);

        int low = 0;
        int high = t - 1;
        int nearNum = 1000000000;
        int cnt = 0;
        while(low < high) {
            int sum = arr[low] + arr[high];
            if(nearNum == abs(sum - k)) {
                cnt++;
            }
            else if( nearNum > abs(sum - k)) {
                    cnt = 1;
                    nearNum = abs(sum - k);
            }

            if(sum > k) {
                high--;
            }
            else {
                low++;
            }
        }
        cout << cnt <<endl;
    }
    return 0;
}