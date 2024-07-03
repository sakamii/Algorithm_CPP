#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAX = 200000;

//ll last lignt nl next light
char ll[100002], nl[100002];
char ll_copy[100002];
int n;

int cal(char *list);

int main(){
    cin >> n;
    int result = MAX;

    cin >> ll;
    cin >> nl;

    memcpy(ll_copy, ll, sizeof(char) * n);
    ll_copy[0] = (ll_copy[0] == '0') ? '1' : '0';
    ll_copy[1] = (ll_copy[1] == '0') ? '1' : '0';
    result = min(result, 1 +  cal(ll_copy));

    result = min(result, cal(ll));

    if(result == MAX) result = -1;
    cout << result;
    // cin >> nl;

}

int cal(char *list){
    int result = 0;
    for(int i = 0; i < (n - 1); i++) {
        if(nl[i] != list[i]) {
            result++;
            list[i + 1] = (list[i + 1] == '0') ? '1' : '0';
            list[i + 2] = (list[i + 2] == '0') ? '1' : '0';
        }
    }

    if(list[n - 1] != nl[n -1]) {
        return MAX;
    }
    return result;
}
