#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, int> > vect;
int line[100];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int ret = 0;
    int n;
    int s, e;
    cin >> n;
    vect.resize(n);
    for(int i = 0; i < n; ++i) {
        cin >> s >> e;
        vect[i].first = s;
        vect[i].second = e;
    }
    sort(vect.begin(), vect.end());


    for(int i = 0; i < n; i++) {
        line[i] = 1;
        int kf = vect[i].first;
        int ks = vect[i].second;
        for(int j = 0; j < i; ++j) {
            if(kf > vect[j].first && ks > vect[j].second) {
                line[i] = line[i] >= (line[j] + 1) ? line[i] : (line[j] + 1);
            }
        }
        ret = ret >= line[i] ? ret : line[i];
    }

    cout << n - ret;

}