include <iostream>
#include <queue>
#include <vector>
#include <cmath>
using namespace std;
int N, nowTime = 1;
vector<pair<int,pair<int,char>>>vec;
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>pq[4];
int answer[200011];

bool isEmpty(){
    for(int i=0;i<4;i++){
        if(!pq[i].empty()) return true;
    }
    return false;
}

void cal(){
    while(isEmpty()){
        //cout<<nowTime<<' ';
        vector<int>temp;
        bool flag=false;
        int deadLock=0;
        int tempMin=2e9;
        for(int i=3;i>=0;i--){
            if(pq[i].empty()) continue;
            tempMin=min(pq[i].top().first,tempMin);
            if(pq[i].top().first<=nowTime){
                if(!pq[(i+3)%4].empty()){
                    if(pq[(i+3)%4].top().first<=nowTime){
                        deadLock++;
                        continue;
                    }
                }
                answer[pq[i].top().second]=nowTime;
                flag=true;
                temp.push_back(i);
            }
        }
        if(!flag) nowTime=tempMin-1;
        if(deadLock==4) break;
        for(int i=0;i<temp.size();i++){
            pq[temp[i]].pop();
        }
        nowTime++;
    }
    for(int i=1;i<=N;i++){
        if(answer[i]==0) cout<<-1<<'\n';
        else cout<<answer[i] - 1<<'\n';
    }
}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    cin>>N;
    for(int i=1;i<=N;i++){
        int a;
        char b;
        cin>>a>>b;
        pq[b-'A'].push({a + 1,i});
    }
    //cout<<pq[0].top().second;
    cal();
    return 0;
}
