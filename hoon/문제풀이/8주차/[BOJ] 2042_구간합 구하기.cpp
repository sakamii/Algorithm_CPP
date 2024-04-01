#include <iostream>
#include <vector>

/*
Segment-Tree -> Full binary tree -> 시간복잡도 대부분이 binary tree와 동일
각 구간에 대한 정보를 저장하는 자료구조

리프노드 => 배열 그대로
각 노드의 부모 => 왼쪽 자식과 오른쪽 자식에 대한 특정 연산의 결과
=> 즉 특정 구간의 최소, 최대값 or 구간 합 구하는 문제에 주로 적용
=> 일반적인 구간합이 쉽고 선형시간 알고리즘에 속해 좋지만 
=> segtree는 이거보다 logn 시간복잡도와 더불어, 원소를 계속해서 변경해야 하는 작업에 특출남 but 메모리 많이먹음

prefix sum vs segment tree
prefix sum => O(n) => 원소 변경 연산 m번 수행 => O(nm)
segment tree => O(logn) , 원소 변경 O(logn), m번 수행 => O(mlogN)

구현
=> 일반적인 분할정복, start와 end index를 이분하면서 탐색
=> 다만, segment tree의 특성에 맞게 init 함수의 return값을 구간에 대한 정보로 리턴하자

update의 경우 특정 index의 값과 변경될 값의 차이를 계산해 루트노드로부터 내려오면서 더해주는 특정 구간에 더해주는 방식으로 구현

segtree의 node는 1부터 시작해야 binary tree 구조 생성 가능

*/
using namespace std; 
int n,m,k;
long long segtree[4000001];
long long arr[1000001];

long long init(int node,int start, int end){
    if(start == end) return segtree[node] = arr[start];
    int mid = (start+end)/2;
    return segtree[node] = init(node*2, start, mid) + init(node*2 + 1, mid+1, end);
}

/*
left, right가 start end보다 큰 범위임.
start와 end가 [left,right] 구간에 들어오면 그 구간의 합을 return 해주면됨
어차피 각 segment가 겹치는 구간을 다루지 않기 때문에 상관없음.
*/
long long getSum(int node, int start, int end, int left, int right){

    if(left > end || right < start) return 0;
    if(left <= start && right >= end) return segtree[node];

    int mid = (start+end)/2;
    return getSum(node*2, start, mid, left, right) + getSum(node*2 + 1 , mid + 1, end, left, right);
}

void update(int node, int start, int end, int index, long long diff){
    if(index < start || index > end) return;
    segtree[node] += diff;

    if(start != end){
        int mid = (start+end)/2;
        update(node*2, start, mid,index, diff);
        update(node*2 + 1, mid+1, end,index, diff);
    }
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
        long long a,b,c;
        cin >> a >> b >> c;
        if(a == 1){
            update(1,1,n,b,c-arr[b]);
            arr[b] = c;
        }
        else{
            cout << getSum(1,1,n,b,c)<<"\n";
        }
    }
    return 0;
}