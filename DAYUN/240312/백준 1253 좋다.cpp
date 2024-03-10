/*
    n개의 수 중에서 두 개의 합으로 나타 낼 수 있다면 좋다.
    모든 경우의 수 더하기 
    + 0이 있는 경우 -> 중복 모두 좋다 포함 
    + 0이 세개이상인 경우 -> 0 모두 좋다 포함

*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> arr;
bool visited_arr[2000];

int main() {
    int n;
    int result = 0;
    int cnt = 0;

    cin >> n;
    arr.resize(n);
    int k = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i - k];
        if (arr[i - k] == 0) {
            cnt++;
            k++;
        }
    }
    arr.resize(n - k);
    sort(arr.begin(), arr.end());

    //0이 있는 경우 중복되는 수는 모두 visited 처리
    if (cnt > 0 && (n - k) >= 2) {
        for (int i = 1; i < n - k; i++) {
            if (arr[i - 1] == arr[i]) {
                result ++;
                if(!visited_arr[i - 1]) result++;
                visited_arr[i - 1] = true;
                visited_arr[i] = true;
            }
        }
    }

    //0이 3개 이상일 떄 모든 0을 "좋다"에 포함
    if (cnt >= 3) {
        result += cnt;
    }
    else {
        //두 수의 합이 0이 되는 경우
        int l = 0;
        int h = arr.size() - 1;
        while (l < h) {
            if (arr[l] + arr[h] < 0) {
                l++;
            }
            else if (arr[l] + arr[h] > 0) {
                h--;
            }
            else {
                result += cnt;
                break;
            }
        }
    }

    //모든 경우의 수 탐색
    for (int i = 0; i < arr.size(); i++) {
        int k = 0;
        for (int j = i + 1; j < arr.size(); j++) {
            int s = arr[i] + arr[j];
            for (; k < arr.size(); k++) {
                if (arr[k] == s && !visited_arr[k] && (k != i) && (k != j)) {
                    result++;
                    visited_arr[k] = true;
                }
                if (arr[k] > s) break;
            }
            
            if (arr[i] + arr[j] > arr[arr.size() - 1])
                break;
        }
    }
    cout << result;
}