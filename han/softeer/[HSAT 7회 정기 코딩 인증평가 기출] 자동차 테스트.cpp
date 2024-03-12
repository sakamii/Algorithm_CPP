#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, Q, M;
vector<long long> vect;

int BS(int left, int right, int target) {
    while(left <= right) {
        int mid = (left + right) / 2;
        if(vect[mid] == target) return mid;
        else if(vect[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

int main(int argc, char** argv) {
    cin >> N >> Q;
    vect.resize(N);
    for(int i = 0; i < N; i++) {
        cin >> vect[i];
    }
    sort(vect.begin(), vect.end());
    for(int i = 0; i < Q; i++) {
        cin >> M;
        int ret = BS(0, N - 1, M);
        if(ret == -1) cout << 0 << "\n";
        else cout << ret * (N - 1 - ret) << "\n";
    }
    return 0;
}