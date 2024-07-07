#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

/*
첫 풀이:
그냥 완탐 -> 길이 50이라 당연히 시간초과

두번째 풀이:
각 문자열에서 A개수, B개수 판단후 둘중 하나가 초과되는 경우 리턴 -> 시간초과

세번째
두번째 문자열부터 생각해서 지워가보자
첫번째 문자가 B면 B 추가하고 뒤집기 실행가능 -> 그럼 첫문자 B 삭제하고 뒤집기
마지막 문자가 A면 A추가하고 그대로 재귀 -> 마지막 문자만 제거하고 재귀
=> AC

*/
int result = 0;

void func(string a, string b){
    if(a.length() == b.length()){
        if(a==b) result =1;
        return;
    }
    if(b[0] == 'B'){
        string next = "";
        for(int i=b.length()-1; i>=1; i--){
            next += b[i];
        }
        func(a,next);
    }
    if(b[b.length()-1] == 'A'){
        string next ="";
        for(int i=0; i<b.length()-1; i++){
            next += b[i];
        }
        func(a,next);
    }
}
int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    string a,b;
    cin >> a >> b;
    func(a,b);
    cout << result << endl;
}