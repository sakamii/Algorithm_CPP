
// 조합, 순열, 중복조합, 중복순열

#include <iostream>
using namespace std;

int n, m, arr[5];
bool v[7];

/*
    123
    124
    125
    ...
    456
    -> 조합
*/
void combination(int d, int start) {
    if (d == n) {
        for (int j = 0; j < d; j++)
            cout << arr[j] << " ";
        cout << endl;
        return;
    }

    for (int i = start; i < 7; i++) {
        arr[d] = i;
        combination(d + 1, i + 1);
    }
}

/*
    123
    124
    125
    126
    132
    ...
    456
    ...
    654
    -> 순열
*/
void permutation(int d) {
    if (d == n) {
        for (int j = 0; j < d; j++)
            cout << arr[j] << " ";
        cout << endl;
        return;
    }

    for (int i = 1; i < 7; i++) {
        if (!v[i]) {
            v[i] = 1;
            arr[d] = i;
            permutation(d + 1);
            v[i] = 0;
        }
    }
}

/*
    111
    112
    ...
    166
    222
    223
    233
    ...
    666
    -> 중복조합
*/
void duplicate_combination(int d, int start) {
    if (d == n) {
        for (int j = 0; j < d; j++)
            cout << arr[j] << " ";
        cout << endl;
        return;
    }

    for (int i = start; i < 7; i++) {
        arr[d] = i;
        duplicate_combination(d + 1, i);
    }
}

/*
    111
    112
    ...
    211
    ...
    666
    -> 중복순열
*/
void duplicate_permutation(int d, int start) {
    if (d == n) {
        for (int j = 0; j < d; j++)
            cout << arr[j] << " ";
        cout << endl;
        return;
    }

    for (int i = 1; i < 7; i++) {
        arr[d] = i;
        duplicate_permutation(d + 1, i + 1);
    }
}

int main() {
    cin >> n >> m;  // 3 0

    if (!m) combination(0, 1);
    else if (m == 1) permutation(0);
    else if (m == 2) duplicate_combination(0, 1);
    else duplicate_permutation(0, 1);
}
