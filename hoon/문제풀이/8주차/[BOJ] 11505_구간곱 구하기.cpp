#include <iostream>
#include <algorithm>
using namespace std;

int n,m,k;
long long seg[4000001];
long long arr[1000001];

/*
세그먼트트리 update를 다르게 생각해야 하는 문제
세그먼트트리의 update 방식은 크게 두가지로 나뉘어지는데
트리의 부모노드부터 갱신하는 방식
트리의 lead노드부터 갱신하는 방식이다.

기본적으로 구간합이나 최소or최대값을 갱신하는 문제는 부모노드부터 갱신해도, leaf 노드에는 영향을 주지 않으니
부모노드부터 갱신을 하면서 내려올수있지만,

이 문제처럼 곱셈연산의 경우에는 update값으로 0이 올수도 있어서, leaf노드를 업데이트한 이후
다시 부모노드를 갱신해주는 방식으로 처리한다.

=> init과 똑같은 방식으로 처리하는것 .
*/
long long init(int node, int start ,int end){
    if(start == end) return seg[node] = arr[start];
    int mid= (start+end)/2;
    return seg[node] = (init(node*2,start,mid) * init(node*2+1,mid+1,end))% 1000000007;
}

long long getMul(int node, int start, int end, int left, int right){
    if(left > end || right < start) return 1;
    if(left <= start && right >= end) return seg[node];
    int mid = (start+end)/2;

    return (getMul(node*2, start , mid, left,right) * getMul(node*2 + 1, mid + 1, end, left,right))%1000000007;
}

long long update(int node, int start, int end, int index, int item){
    if(index < start || index > end) return seg[node];
    if(start == end) return seg[node] = item;
    int mid = (start + end)/2;
    return seg[node] = (update(node*2,start,mid,index,item)* update(node*2+1,mid+1,end,index,item))% 1000000007;

}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> k;
    for(int i=1; i<=n; i++){
        cin >> arr[i];
    }
    init(1,1,n);
    for(int i=0; i<m+k; i++){
        int a,b,c;
        cin >> a >>b >> c;
        if(a==1){
            update(1,1,n,b,c);
            arr[b] = c;
        }
        else{
            cout << getMul(1,1,n,b,c) % 1000000007 << "\n";
        }
    }
    return 0;
}