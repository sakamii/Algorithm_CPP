#include <iostream>
#include <set>

using namespace std;

set<unsigned int> a; 

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int nA, nB;
    unsigned int num;
    cin >> nA >> nB;
    for(int i = 0; i < nA; ++i) {
        cin >> num;
        a.insert(num);
    }

    for(int i = 0; i < nB; ++i) {
        cin >> num;
        a.erase(num);
    }

    cout << a.size() << "\n";
    for(unsigned int i : a) {
        cout << i << " ";
    }
}