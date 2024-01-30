#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/*

lowerbound 방식으로 시간의 최솟값을 찾는 과정.
m명의 인원을 각 출입국 심사에 배정한다 => 각 출입국 심사시 m명을 골고루 배정해야한다.
m명을 골고루 배정한다 => t라는 시간을 두고 각 심사대에서 걸리는 시간의 총 합이 딱 m이면 된다.
딱 m이다 -> lowerbound 방식으로 m보다 크거나 같은 마지막 index를 체크한다.

이 문제에서 주어진 n개의 심사소에서 걸리는 시간의 최대값과 m을 곱한 부분을 end로 잡고 풀이했지만
풀어야 했으나, overflow가 발생하는거 같아 이렇게 풀지 못했다.

근데 min으로 바꿔서 풀었더니 ac가 나왓는데 이유는 모르겠다.

잘못된 코드라고 생각해 오버플로우를 체크해주는 방향으로 다시 코드를 수정했다.
*/


vector<int> arr;
long long int n,m;

bool check(long long int mid){
    long long int total = 0;
    for(int i=0; i<arr.size(); i++){
        total += mid/arr[i];
        if(total < 0) return -1;
    }
    return total >= m;
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    long long int low, end;
    long long int temp_max = 0;
    for(int i=0; i<n; i++){
        long long int temp;
        cin >> temp;
        arr.push_back(temp);
        temp_max = max(temp, temp_max);
    }
    low = 0; end = temp_max*m;

    while(low < end){
        long long int mid = (low + end) / 2;

        if(!check(mid)) low = mid + 1;
        else end = mid;
    }


    cout << end;
}