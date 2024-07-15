#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<pair <int, int> > vect;
priority_queue<int> pq;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    int num, start, end;
    cin >> n;
    vect.resize(n);
    for(int i = 0; i < n; i++) {
        cin >> num >> start >> end;
        pair<int, int> p;
        vect[i].first =start;
        vect[i].second = end;
    }
    sort(vect.begin(), vect.end());

    int lec = 0;
    int time = 0;
    for(int i = 0; i < n; ++i) {
        time = vect[i].first;
        while( !pq.empty() && (-pq.top()) <= time) {
            pq.pop();
        }

        pq.push( -vect[i].second);
        if(lec < pq.size()) lec = pq.size();
    }
    cout << lec ; 
}



