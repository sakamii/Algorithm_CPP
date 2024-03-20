/*
    바이너리 왕국
*/

#include<iostream>

using namespace std;

bool arr[1000002] = {false};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        int k;
        cin >> k;
        if(k != 0) {
            cnt++;
            arr[i] = true;
            if(arr[i - 1]) cnt--;
        } 
    }


    for(int i = 0; i < m; i++) {
        int k;
        cin >> k;
        if(k == 0) {
            cout << cnt << "\n";
        }
        else if(k == 1){
            int j;
            cin >> j;
            if(!arr[j]) {
                arr[j] = true;
                cnt++;
                if(arr[j - 1]) cnt--;
                if(arr[j + 1]) cnt--;
            } 
        }
    }
}