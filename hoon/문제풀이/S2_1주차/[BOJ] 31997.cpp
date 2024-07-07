#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;


/*
1차원 누적합을 어떻게 최적화 할거냐에 대한 문제
먼저 교집합 범위를 구함

교집합 범위의 시작, 끝부분에 체크 배열을 만들고
시작지점에서는 +, 끝지점에서는 -로 누적합 처리.

*/
int n,m,t;
int timeTable[200001];
int startTable[200001];
int endTable[200001];
struct person{
    int a,b;
};

person p[200001];

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m >> t;
    for(int i=1; i<=n; i++){
        cin >> p[i].a >> p[i].b;
    }
    for(int i=0; i<m; i++){
        int a,b;
        cin >> a >> b;
        int c1 = max(p[a].a, p[b].a);
        int c2 = min(p[a].b, p[b].b);

        if(c1 >= c2) continue;

        startTable[c1] += 1;
        endTable[c2] += 1;
    }
    int temp = 0;
    for(int i=0; i<=t; i++){
        temp += startTable[i];
        temp -= endTable[i];
        timeTable[i] = temp;
    }

    for(int i=0; i<t; i++){
        cout << timeTable[i] << "\n";
    }
}