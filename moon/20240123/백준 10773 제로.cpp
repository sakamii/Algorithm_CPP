//https://www.acmicpc.net/problem/10773

#include <iostream>
#include <stack>
using namespace std;


int main() {

    int k;
    int a;
    int sum = 0;

    stack <int> s;

    cin >> k;

    for (int i = 0; i < k; i++) {
        cin >> a;
        if (a != 0) {
            s.push(a);
        }
        else if(a ==0){
            s.pop();
        }
    }

    while (s.size()>0) {
        sum += s.top();
        s.pop();
    }

    cout << sum;

    return 0;
}
