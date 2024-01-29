#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> arr;
int n;

/*
투포인터로 실패해서 바이너리 서치로 구현 -> 왜 실패하는지 모르겠음.
일반적인 바이너리 서치는 중복 개수를 세지 못하기 때문에
upperBound와 lowerBound를 이용해 중복 개수를 인덱스를 이용한 방식으로 검사함.

STL에서 제공하는 함수가 있지만, 직접 구현해서 문제를 풀었음

upperBound -> target보다 큰 숫자가 등장하는 첫 index.
중간값이 target 값과 동일해 질때까지 start를 늘리기 때문에, end는 
타겟넘버의 바로 뒷 인덱스를 가리킴.

lowerBound -> 중간값이 target 값보다 작을때까지 start를 늘리기 때문에
end는 target의 바로 직전 인덱스를 가리킴.


*/
int upperBound(int start,int end, int target){
    while(start < end){
        int mid = (start+end)/2;
        if(arr[mid] <= target) start = mid+1;
        else end = mid;
    }
    return end;
}

int lowerBound(int start,int end, int target){
    while(start < end){
        int mid = (start+end)/2;
        if(arr[mid] < target) start = mid+1;
        else end = mid;
    }
    return end;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;

    for(int i=0; i<n; i++){
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }

    sort(arr.begin(),arr.end());
    

    long long result = 0;
    for(int i=0; i<n-2; i++){
        for(int j = i+1; j<n-1; j++){
            int check = arr[i] + arr[j];
            int upper = upperBound(j+1,n,-check);
            int lower = lowerBound(j+1,n,-check);
            result += upper-lower;
        }
    }
    cout << result<<endl;
    return 0;
}