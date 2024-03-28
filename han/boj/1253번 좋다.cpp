// @START 24.03.09:16:30
// @END FAIL

#include <iostream>
#include <algorithm>

using namespace std;

int N, answer;
long long A[2000];
bool DAT[2000];

int main() {
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }
    sort(A, A + N);
    for(int i = 2; i < N; i++) {
        if(A[i] == A[i - 1] && DAT[i - 1]) {
            answer++;
            continue;
        }
        int right;
        for(int left = 0; left < i; left++) {
            right = left + 1;
            while(right < N && A[left] + A[right] < A[i]) {
                right++;
            }
            if(A[left] + A[right] == A[i]) {
                answer++;
                break;
            }
        }
    }
    cout << answer;
    return 0;
}
