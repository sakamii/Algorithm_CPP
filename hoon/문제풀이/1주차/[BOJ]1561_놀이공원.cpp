#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> arr;
long long int n,m;

/*
놀이공원에 n명이 다 탑승할수 있는 최소 시간을 먼저 구함.
그 시간을 t라고 가정하면
t-1 => n-1명까지 탑승할수 있는 최대 시간.
그렇다면 t-1시간까지 탑승할수 있는 사람의 수를 계산해서
t시간에 비어있는 놀기기구의 수만큼 더해주면서 사람의 수가 인풋과 일치해지면
그 놀이기구를 출력하면 정답.

t시간에 비어있는 놀이기구 ==> 나머지가 0인 놀이기구.

다만, 이 문제에서는 이미 0초에 놀이기구에 동시에 탑승한다는 조건이 있어
계산시 0부터가 아닌, n부터 시작을 해야함.

*/
bool check(long long int mid){
    long long int total = n;
    for(int i=0; i<arr.size(); i++){
        total += mid/arr[i];
    }
    return total >= m;
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> m >> n;
    long long int low, end;
    long long int temp_max = 0;
    for(int i=0; i<n; i++){
        long long int temp;
        cin >> temp;
        arr.push_back(temp);
        temp_max = max(temp, temp_max);
    }
    low = 0; end = temp_max*m;
    if(m <= n) {
        cout << m;
        return 0;
    }

    while(low < end){
        long long int mid = (low + end) / 2;

        if(!check(mid)) low = mid + 1;
        else end = mid;
    }


    long long int maximum_time = end-1;
    long long int numbers = n;
    

    //end-1 시간까지 탑승한 승객수를 더함
    //그럼 마지막 놀이기구에 탑승하는 사람만 더해주면 됨.
    for(int i=0; i<arr.size(); i++){
        numbers += maximum_time/arr[i];
    }
    for(int i=0; i<arr.size(); i++){
        if(end%arr[i] == 0){
            numbers += 1;
        }
        if(numbers == m){
            cout << i+1 << endl;
            return 0;
        }
    }

}