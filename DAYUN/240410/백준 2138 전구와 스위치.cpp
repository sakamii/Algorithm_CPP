#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAX = 200000;

//ll last lignt nl next light
char ll[100000], nl[100000];
char ll_copy[100000];
int n;

int cal(char *list, int s);

int main(){
    cin >> n;
    int result = MAX;


    cin >> ll;
    cin >> nl;

    memcpy(ll_copy, ll, sizeof(char) * n);
    ll_copy[0] = (ll_copy[0] == '0') ? '1' : '0';
    ll_copy[1] = (ll_copy[1] == '0') ? '1' : '0';
    result = min(result, 1 +  cal(ll_copy, 0));

    //3자리만 사용하는 경우 
    result = min(result, cal(ll, 0));

    if(result == MAX) result = -1;
    cout << result;
    // cin >> nl;

}

int cal(char *list, int s){
    int result = 0;
    for(int i = s; i < (n - 2); i++) {
        if(nl[i] != list[i]) {
            result++;
            list[i + 1] = (list[i + 1] == '0') ? '1' : '0';
            list[i + 2] = (list[i + 2] == '0') ? '1' : '0';
        }
    }

    if(list[n - 2] == nl[n - 2] && list[n - 1] == nl[n - 1]) {
        return result;
    }
    else if(list[n - 2] != nl[n - 2] && list[n - 1] != nl[n - 1])  {
        return result + 1;
    }
    else {
        return MAX;
    }
}
