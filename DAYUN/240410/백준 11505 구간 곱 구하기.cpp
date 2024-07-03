#include <iostream>

using namespace std;

const long long SIZE = 1 << 21;
const long long LEN = 1 << 20;
const long long mod = 1000000007;

int n, m, k;
long long tree[SIZE];

void init();
void update(int b, int c);
long long get(int idx, int s, int e, int ts, int te);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >>  n >>  m >> k;
    init();
    
    int a, b, c;
    int result = 1;
    for(int i = 0; i < (m + k); i++) {
        cin >> a >> b >> c;
        if(a == 1) {
            update(b - 1, c);
        }
        else if(a == 2) {
            cout << get(1, 0, LEN - 1, b - 1, c - 1) % mod << endl;
        }
    }
}


void init(){
    for(int i = 0; i < n; i++) {
        cin >> tree[LEN + i];
    }
    for(int i = LEN - 1; i >= 1; --i) {
        tree[i] = (tree[i * 2] * tree[i * 2 + 1]) % mod;
    }
}

void update(int b, int c) {
    b += LEN;
    tree[b] = c;
    b /= 2;
    while(b >= 1) {
        tree[b] = (tree[2 * b] * tree[2 * b + 1]) % mod;
        b /= 2; 
    }
}

long long get(int idx, int s, int e, int ts, int te) {
    int mid;
    if(ts <= s && e <= te) return tree[idx];
    if(te < s || e < ts) return 1;
    mid = (s + e) / 2;
    return get(idx * 2, s, mid, ts, te) * get(idx * 2 + 1, mid + 1, e, ts, te) % mod;
}