#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
   int k,n;
   cin >> k >> n;
   long long int low=1;
   long long int high = 1;
   long long int *arr= new long long int[k];
   for(int i=0; i<k; i++){
       cin >> arr[i];
       if(high<arr[i]){
           high = arr[i];
       }
   }
   int count;
   int result = 0;
   while(low<=high){
       count=0;
       long long int mid = (low+high)/2;
       for(int i=0; i<k; i++){
           count += arr[i]/mid;
       }
       if(count >= n){
           if(result<mid){
               result = mid;
           }
           low = mid +1;
       }
        else{
            high =mid-1;
        }
   }
   cout<<result<<"\n";
   return 0;
}

/*
 쉬운 이분탐색 문제
 최댓값을 기준으로 
 count를 만족하는지 확인하면서 길이를 늘리고 줄이기.
*/