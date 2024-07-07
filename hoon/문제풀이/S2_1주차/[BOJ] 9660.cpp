#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

/*
규칙이 7주기마다 반복
7주기마다 두번째와 7번째는 CY가 이김
*/
long long n;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    if(n%7 == 0 || n%7 == 2) cout << "CY";
    else cout <<"SK";
    return 0;
}