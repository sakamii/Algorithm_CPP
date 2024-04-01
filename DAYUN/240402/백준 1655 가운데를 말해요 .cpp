#include <iostream>
#include <queue>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    priority_queue<int> left;
    priority_queue<int, vector<int>, greater<int>> right;

    int temp;
    cin >> temp;
    right.push(temp);
    cout << temp << "\n";
    if(n >= 2)
    {
        cin >> temp;
        if(right.top() < temp) {
            cout << right.top() << "\n";
            left.push(right.top());
            right.pop();
            right.push(temp);
        }
        else {
            left.push(temp);
            cout << temp << "\n";
        }
    }


    //동일 하다 -> 왼쪽 채우기
    bool flag = true;
    for(int i = 2; i < n; i++) {
        cin >> temp;
        //홀수 일때  : left size 와 right size가 같음
        //right에 무조건 추가
        if(flag)
        {
            if(temp < left.top()) {
                cout << left.top() << "\n";
                right.push(left.top());
                left.pop();
                left.push(temp);
            }
            else if(temp <= right.top()) {
                cout << temp << "\n";
                right.push(temp);
            }
            else {
                cout << right.top() << "\n";
                right.push(temp);
            }
            flag = false;
        }
        else {
            //짝수 일때 무조건 왼쪽에 추가
            if(temp <= left.top()) {
                cout << left.top() << "\n";
                left.push(temp);
            }
            else if(temp <= right.top()) {
                cout << temp << "\n";
                left.push(temp);
            }
            else {
                cout << right.top() << "\n";
                left.push(right.top());
                right.pop();
                right.push(temp);
            }
            flag = true;
        }
    }

    // cout << endl;
    // while(!left.empty()){
    //     cout << left.top() << " ";
    //     left.pop();
    // }
    // cout << endl;
    // while(!right.empty()){
    //     cout << right.top() << " ";
    //     right.pop();
    // }

}