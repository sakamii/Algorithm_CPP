#include <iostream>
#include <vector>
using namespace std;

int n,m;
int arr[100001];
int minSeg[400001];
int maxSeg[400001];

int minInit(int node, int start, int end){
    if(start == end){
        return minSeg[node] = arr[start];
    }

    int mid = (start + end)/2;

    return minSeg[node] = min(minInit(node*2, start, mid), minInit(node*2+1, mid + 1, end));
}
int maxInit(int node, int start, int end){
    if(start == end){
        return maxSeg[node] = arr[start];
    }

    int mid = (start + end)/2;

    return maxSeg[node] = max(maxInit(node*2, start, mid), maxInit(node*2+1, mid + 1, end));
}
int getMin(int node, int start, int end, int left, int right){
    if(left > end || right < start) return 1e9;
    if(left <= start && right >= end) return minSeg[node];
    int mid = (start + end) /2;
    return min(getMin(node*2, start , mid, left, right), getMin(node*2 + 1 , mid + 1, end, left,right));
}
int getMax(int node ,int start, int end, int left, int right){
    if(left > end || right < start) return -1e9;
    if(left <= start && right >= end) return maxSeg[node];
    int mid = (start + end) /2;
    return max(getMax(node*2, start , mid, left, right), getMax(node*2 + 1 , mid + 1, end, left,right));
}

void minUpdate(int node, int start, int end, int index, int item){
    if(index < start || index > end){
        return ;
    }
    minSeg[node] = min(minSeg[node],item);

    if(start != end){
        int mid = (start + end)/2;
        minUpdate(node*2, start, mid, index, item);
        minUpdate(node*2 + 1 , mid + 1, end,index,item);
    }
}

void maxUpdate(int node, int start, int end, int index, int item){
    if(index < start || index > end){
        return ;
    }
    maxSeg[node] = max(maxSeg[node],item);

    if(start != end){
        int mid = (start + end)/2;
        maxUpdate(node*2, start, mid, index, item);
        maxUpdate(node*2 + 1 , mid + 1, end,index,item);
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;

    for(int i=1; i<=n; i++){
        cin >> arr[i];
    }
    minInit(1,1,n);
    maxInit(1,1,n);
    for(int i=0; i<m; i++){
        int a,b;
        cin >> a >> b;
        cout<<getMin(1,1,n,a,b) << " " << getMax(1,1,n,a,b) << "\n";
    }
    return 0;
}