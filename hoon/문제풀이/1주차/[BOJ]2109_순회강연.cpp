#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
 
int n;
priority_queue<int> pq;
vector<pair<int, int>> v;
int result; // 출력
 
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int p, d;
        cin >> p >> d;
        v.push_back(make_pair(d, p));
    }
 
    sort(v.begin(), v.end());
 
    for (int i = 0; i < n; i++) {
        pq.push(-v[i].second);
        if (pq.size() > v[i].first) {
            pq.pop();
        }
    }
    
    while(!pq.empty()){
        result += -pq.top();
        pq.pop();
    }
    cout << result;
 
    return 0;
}

/*
https://www.acmicpc.net/problem/2109
Greedy, Priority_Queue

--- 틀렸던 코드 ---
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

priority_queue<int> pq;


int main() {
    int n;
    cin >> n;
    vector<pair<int,int>> v;
    for(int i=0; i<n; i++){
        int a,b;
        cin >> a >> b;
        v.push_back({b,a});
    }
    if(n==0){
        cout << 0;
        return 0;
    }
    else if(n==1){
        cout << v[0].second;
        return 0;
    }
    sort(v.begin(),v.end());
    int current = v[0].first;
    int maxi = v[0].second;
    int flag = 0;
    int sum = 0;
    for(int i=1; i<n; i++){
        if(current == v[i].first){
            maxi = max(maxi,v[i].second);
        }
        else{
            sum += maxi;
            current = v[i].first;
            maxi = v[i].second;
            if(i == n-1) flag = 1;
        }
    }
    if(flag == 1) sum += maxi;
    cout << sum;
    return 0;
}

문제를 잘못 이해해 특정 날짜에 받을수 있는 최대 값을 더해주는 형태로 코드를 작성함.
-> 비어있는 스케줄이 있으면 일정을 당겨올수가 없음.
-> 문제가 d일 '이내'에 강연을 하기만 한다는 점을 간과함

=> Prioirty_queue로 해결.

각 일자별로 vector를 정렬하고 priority_queue에 삽입.
각 일정의 개수는 반드시 d일보다는 적어야함.
따라서 priority_queue의 사이즈가 d일의 일정보다 커지는 순간 pop을 해줌.

마지막으로 queue의 남은 값이 비어있는 스케줄까지 고려한 최대 일정들이기 때문에 모두 더해줌.
*/