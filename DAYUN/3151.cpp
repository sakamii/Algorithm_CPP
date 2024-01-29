#include <iostream>
#include <vector>

using namespace std;

int student[10000];
int cnt = 0;
int comb_int[3];


void input(int n);

int main() {

    //코딩 실력, 팀워크
    //-10000~10000
    //코딩 실력의 합이 0
    int n;
    cin >> n;
    input(n);
    //combination(3, n, 0);
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                if (!(student[i] + student[j] + student[k]))
                    cnt++;
            }
        }
    }

    //combination 3
    //3명의 합이 0이면 cnt++

    cout << cnt;

    return 0;
}

void input(int n) {
    for (int i = 0; i < n; i++) {
        cin >> student[i];
    }
}


// void combination(int c, int n, int level) {

//     if (c == 0) {
//         if (!(student[comb_int[0]] + student[comb_int[1]] + student[comb_int[2]]))
//             cnt++;
//         return;
//     }

//     for (int i = level; i < n; i++) {
//         comb_int[c - 1] = i;
//         combination(c - 1, n, i + 1);
//     }


// }