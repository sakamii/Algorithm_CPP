// 2024.07.02

// 문제 부분 : long long 형변환 필요 

#include <iostream>
#include <vector> 
#include <algorithm>

using namespace std;

int N;
vector<int> v;

int main(){
    cin >> N;
    v.resize(N);
    for(int i = 0; i < N; ++i) {
        cin >> v[i];
    }    
    sort(v.begin(), v.end());

    long long price = 0;
    long long value = 0;
    long long maxValue = 0;
    for(int i = 0; i < N; ++i) {
        // 형변환 필요
        value = (long long)v[i] * (long long)(N - i);
        if(value > maxValue) {
            maxValue = value;
            price = v[i];
        }
    }
    cout << maxValue << " " << price;
}