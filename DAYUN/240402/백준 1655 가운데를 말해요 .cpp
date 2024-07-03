#include <iostream>
#include <queue>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    //중앙값보다 작은 수 
    priority_queue<int> left;
    //중앙값보다 큰 수 
    priority_queue<int, vector<int>, greater<int>> right;

    int temp;
    cin >> temp;
    //첫번째 수 -> 바로 출력
    right.push(temp);
    cout << temp << "\n";
    //두번째 수 
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


    //flag가 true이다 -> 홀수 번째, 오른쪽에 추가한다.
    bool flag = true;
    for(int i = 2; i < n; i++) {
        cin >> temp;
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
            //무조건 왼쪽에 추가
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
}