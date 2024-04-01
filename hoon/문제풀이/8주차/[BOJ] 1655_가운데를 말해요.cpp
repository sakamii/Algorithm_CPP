#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <math.h>
#include <string>
#include <map>
#include <set>
using namespace std;

int n;
priority_queue<int> max_heap;
priority_queue<int> min_heap;
vector<int> result;

/*
max heap과 min heap의 사용으로 중앙값을 유지할 수 있음.
*/
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n;

    for(int i=0; i<n; i++){
        int temp;
        cin >> temp;

        if(max_heap.size() > min_heap.size()){
            min_heap.push(-temp);
        }
        else{
            max_heap.push(temp);
        }

        if(!max_heap.empty() && !min_heap.empty()){
            if(max_heap.top() > -min_heap.top()){
                int temp1 = max_heap.top();
                int temp2 = -min_heap.top();
                max_heap.pop();
                min_heap.pop();

                max_heap.push(temp2);
                min_heap.push(-temp1);
            }
        }
        result.push_back(max_heap.top());
    }

    for(int i=0; i<result.size(); i++){
        cout << result[i] << "\n";
    }
}