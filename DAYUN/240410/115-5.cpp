
/*
    5, 2, 2
    숫자 들어가고
    수의 변경
    구간 곱으 ㄹ구하느 횟수

*/

#include <iostream>

using namespace std;

const int SIZE = 1 << 21;
const int LEN = 1 << 20;
//node
int tree[SIZE] = { 0 };


void update(int b, int c);
void init(int n);
int  getMul(int b, int c, int s, int e, int i);

int main(){

    int n, m, k;
    int i;
    int a, b, c;
    
    init(n);
    for(i = 0; i < m; i++) {
        cin >> a >> b >> c;
        if(a == 1) {
            update(b, c);
        }
        else if(a == 2) {
            cout << getMul(b, c, 0, LEN, 1) << "\n";
        }
    }


}


void init(int n) {
    int i;
    for(i = 0; i < n; i++) {
        cin >> tree[LEN + i]; 
    }

    for(i = (LEN + n) / 2; i > 0; i--) {
        tree[i] = tree[i * 2] * tree[i * 2 + 1];
    }
}

void update(int b, int c){
    b += LEN;
    tree[b] = c;
    b /= 2;
    while(b > 0) {
        tree[b] = tree[b * 2] * tree[b * 2 + 1];
        b /= 2;
    }
}

int getMul(int b, int c, int s, int e, int i) {
    if(b <= s && c >= e) return tree[i];
    if(e < b || s > c) return 1;
    return getMul(b, c, s, (s + e) / 2, i * 2) * getMul(b, c, (s + e) / 2 + 1, e, i * 2 + 1);
}