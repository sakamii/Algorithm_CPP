#include <iostream>
#include <algorithm>

using namespace std;

int n,m;
int seg[400001];
int arr[100001];

int init(int node, int start, int end){

    if(start == end){
        return seg[node] = arr[start];
    }

    int mid = (start + end) / 2;
    
    return seg[node] = min(init(node*2, start, mid), init(node*2+1, mid + 1, end));
}

int getMin(int node, int start, int end, int left, int right){
    if(left > end || right < start) return 1e9;
    if(left <= start && right >= end) return seg[node];
    int mid = (start+end)/2;
    return min(getMin(node*2,start, mid, left, right), getMin(node*2+1,mid + 1, end , left ,right));
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i=1; i<=n; i++) cin >> arr[i];
    init(1,1,n);
    for(int i=0; i<m; i++){
        int a,b;
        cin >> a >> b;
        cout << getMin(1,1,n,a,b) << "\n";
    }
    return 0;
}