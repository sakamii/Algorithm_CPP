#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

const int SIZE = 1 << 20;
const int LEN = 1 << 19;
pair<int, int> tree[SIZE];
int result = 0;
int n;

void segtree();
int next_bigger(int idx, int s, int e, int ts, int te, int target);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    segtree();
    for(int i = 0; i < n; ++i) {
        int num = tree[LEN + num].first;
        result += next_bigger(1, 0, LEN - 1, i, n, num);
    }
}


void segtree(){
    for(int i = 0; i < n; ++i) {
        cin >> tree[LEN + i].first;
        tree[LEN + i].second = tree[LEN + i].second;
    }

    for(int i = LEN - 1; i > 0; --i) {
        tree[i] = {min(tree[i * 2].first, tree[i * 2 + 1].first), max(tree[i * 2].second, tree[i * 2 + 1].second)};
    }
}


int next_bigger(int idx, int s, int e, int ts, int te, int target){
    if(tree[idx].first > target) return e - idx;
    if(tree[idx].second <= target) return 0;
    int mid = (s + e) / 2; 
    // return next_bigger(idx * 2, s, mid)
    
}

int nn()
{
    int mid;
    if(ts <= s && e <= te) return tree[idx];
    if(te < s || e < ts) return 1;
    mid = (s + e) / 2;
    return get(idx * 2, s, mid, ts, te) * get(idx * 2 + 1, mid + 1, e, ts, te) % mod;
}