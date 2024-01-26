#include <iostream>
#include <string>
#include <vector>
using namespace std;


vector<int> v[500001];

int main() {
    int num,pp;
    cin >> num >> pp;
    int ans = 0;
    for(int i=0; i<num; i++){
        int n,p;
        cin >> n >> p;
        while(v[n].size() != 0){
            if(v[n].back() > p){
                //cout << v[n].back() << endl;
                ans += 1;
                v[n].pop_back();
            }
            else if(v[n].back() == p){
                v[n].pop_back();
                ans -= 1;
            }
            else break;
        }
        v[n].push_back(p);
        ans += 1;
    }
    cout << ans;
}


/*
vector로 구현
pop_back -> O(1)이라 스택이랑 같은 동작.
스택으로 구현해도 됫을듯.

첫번째 예제에서 10이 두번 들어오는데, 손가락은 그냥 두고 튕기는데만 손가락을 움직이면 되므로
정답 카운트에서 -1을 해주고 벡터에 삽입하면서 다시 +1
*/