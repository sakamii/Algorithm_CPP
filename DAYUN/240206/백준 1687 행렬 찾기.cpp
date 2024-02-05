#include<iostream>
#include<algorithm>

using namespace std;

int n, m;

int main() {
    cin >> n >> m;
    int prefix_sum[334][334] = { 0 };
    int arr[334][334] = {0};
    for(int i = 1; i <= n; i++) {
        string str;
        cin >> str;
        for(int j = 1; j <= str.length(); j++) {
            if(str[j - 1] == '0') arr[i][j] = 0;
            else arr[i][j] = 1;
        }
    }

    //prefix sum
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            prefix_sum[i][j] = prefix_sum[i - 1][j] + prefix_sum[i][j - 1] + arr[i][j] - prefix_sum[i - 1][j - 1];
        }
    }

    int result = 0;
    for(int width = m; width > (result / m) ; width--) {
        int high = 0;
        for(int i = 0; i <= (m - width); i++) {
            int before = 0;
            int cnt = 0;
            for(int j = 1; j <= n; j++) {
                int k = prefix_sum[j][i + width] - prefix_sum[j][i];
                if(before == k)
                    cnt++;
                else{
                    before = k;
                    cnt = 0;
                }
                high = max(cnt, high);
            }
        }
        result = max(result, high * width);
    }

    cout << result;
}