#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

unordered_map<string, int> orderList[12];

bool cmp(pair<string, int>& a, pair<string, int>& b){
    return a.second > b.second;
}

void findList(int n, string order, string str){
    int m = str.size();
    if(m >= 2){
        if(orderList[m].find(str) == orderList[m].end()){
            orderList[m][str] = 1;
        }
        else{
            orderList[m][str]++;
        }
    }
    for(int i=n; i<order.size(); ++i){
        findList(i + 1, order, str + order[i]);
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    for(int i=0; i<orders.size(); ++i){
        sort(orders[i].begin(), orders[i].end());
        findList(0, orders[i], "");
    }
    for(int i=0; i<course.size(); ++i){
        int n = course[i];
        if(!orderList[n].size()) continue;
        vector<pair<string, int>> v(orderList[n].begin(), orderList[n].end());
        sort(v.begin(), v.end(), cmp);
        if(v[0].second < 2) continue;
        int max_value = v[0].second;
        answer.push_back(v[0].first);
        for(int j=1; j<v.size(); ++j){
            if(v[j].second < max_value) break;
            answer.push_back(v[j].first);
        }
    }
    sort(answer.begin(), answer.end());
    return answer;
}
