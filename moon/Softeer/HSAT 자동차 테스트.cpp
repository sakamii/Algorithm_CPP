#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*
  target number의 index를 알아내면 문제를 해결할 수 있음.
  배열에서 인덱스를 빠르게 찾기 위해 이진탐색을 사용해서 해결.
*/

vector<int> v;
int map[200001];
int N,Q;

int main(){

    cin >> N >> Q;

    for(int i=0; i < N; i++){
        int e;
        cin>> e;
        v.push_back(e);
    }
  
    // 이진탐색을 위해 정렬
    sort(v.begin(), v.end());


    for(int i=0; i<Q;i++){
        int k;
        cin>> k;
        
        int start = 0;
        int end = N-1;
        int mid = 0;
        // 이진탐색 시작
        while(start <= end){
            mid = (start + end)/2;
          
            if(v[mid] < k) start = mid + 1;
            else if(v[mid] > k) end = mid - 1;
            else {
                // target을 찾았다면 끝 값인지 확인한 후 연산
                if(mid > 0 && mid < N-1){
                int low = mid;
                int high = N-1 - mid;
                map[i] = low * high;
                }
                
                break;
            }
        } 
    }
    for(int i=0; i<Q;i++){
        cout << map[i] << "\n";
    }
    
   return 0;
}
