#include <iostream>

typedef unsigned long long ll;

using namespace std;

const int MAX_N = 100000;

int N;
ll B;
int vect[MAX_N];

bool isPossible(ll target) {
    ll cost = 0;
    for(int i = 0; i < N; i++) {
        if(target <= vect[i]) continue;
        cost += (target - vect[i]) * (target - vect[i]);
        if(cost > B) return false;
    }
    return true;
}

ll PS(ll left, ll right) {
    ll ret;
    
    while(left <= right) {
        ll mid = (left + right) / 2;
        if(isPossible(mid)) {
            left = mid + 1;
            ret = mid;
        } else {
            right = mid - 1;
        }
    }
    return ret;
}

int main(int argc, char** argv) {
    cin >> N >> B;
    for(int i = 0; i < N; i++) {
        cin >> vect[i];
    }
    cout << PS(1, (ll)1e18);
    
    return 0;
}