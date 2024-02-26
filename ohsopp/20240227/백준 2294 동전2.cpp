
#include <iostream>
using namespace std;

int n, k, c, d[10010];

int main(){
    
    cin >> n >> k;
    fill(d + 1, d + k + 1, 1e5);

    while (n--) {
        cin >> c;
        for(int i = c; i <= k; i++)
            d[i] = min(d[i], d[i - c] + 1);
    }
    cout << (d[k] < 1e5 ? d[k] : -1);
}
