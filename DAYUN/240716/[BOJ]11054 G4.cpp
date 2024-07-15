#include <iostream>

using namespace std;

int num[1000];
int bigger[1000];
int smaller[1000];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> num[i];
    }

    bigger[0] = 0;
    for(int i = 0; i < n; ++i) {
        int k = num[i];
        for(int j = 0; j < i; ++j) {
            if(num[j] < k) {
                bigger[i] = bigger[i] >= (bigger[j] + 1) ? bigger[i] : (bigger[j] + 1);  
            }
        }
    }

    smaller[n - 1] = 0;
    for(int i = n - 1; i >= 0; --i) {
        int k = num[i];
        for(int j = n - 1; j > i; --j) {
            if(num[j] < k) {
                smaller[i] = smaller[i] >= (smaller[j] + 1) ? smaller[i] : (smaller[j] + 1);  
            }
        }
    }

    int ret = 0;
    for(int i = 0; i < n; ++i) {
        ret = ret >= (smaller[i] + bigger[i]) ? ret :  (smaller[i] + bigger[i]);
    }

    cout << ret + 1;

}


/*
    1 3 5 7 (좋은 수열)
    자신보다 작은 것 중에 제일 큰것
for (int k = 0; k < n; k++){
	length[k] = 1;
    for (int i = 0; i < k; i++){
        if(arr[i] < arr[k]){
            length[k] = max(length[k], length[i] + 1);
        }
    }
}
*/