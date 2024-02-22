//백준 11055 가장 큰 증가하는 부분 수열

/*
    수열 A: 수열의 증가하는 부분 수열 중 합이 제일 큰 것

    위치 상 최고 수열 갯수 저장
*/

#include <iostream>
#include <algorithm>

using namespace std;

int arr[1000];
int num[1000] = { 0 };

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int maxSum = 0;
    for(int i = 0; i < n; i++) {
        int maxNum = 0;
        for(int j = i - 1; j >= 0; j--) {
            //Break안 하고 끝 까지 찾기
            if(arr[i] > arr[j]) {
                maxNum = max(maxNum,num[j]);
            }
        }
        num[i] = maxNum + arr[i];
        maxSum = max(num[i], maxSum);

    }

    cout << maxSum;
}