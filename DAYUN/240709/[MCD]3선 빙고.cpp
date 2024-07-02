// 2024.07.03

// 알고리즘의 탑 - 구현의 탑 3번 

#include <iostream>

using namespace std;

pair<int, int> bingoPan[26];
int row[5];
int col[5];
int diag[2];

int main() {
    int num;
    int i;
    for(i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            cin >> num;
            bingoPan[num] = {i, j};
            row[i] += num;
            col[j] += num;

            if(i == j) diag[0] += num;
            if((i + j) == 4) diag[1] += num;
        }
    }

    int y;
    int x;
    int callNum;
    int bingo = 3;
    int ret;
    for(i = 0; i < 25; i++) {
        cin >> callNum;

        if(bingo > 0) {
            y = bingoPan[callNum].first;
            x = bingoPan[callNum].second;

            row[y] -= callNum;
            if(row[y] == 0) bingo--;
            col[x] -= callNum;
            if(col[x] == 0) bingo--;
            if(x == y) {
                diag[0] -= callNum;
                if(diag[0] == 0) bingo--; 
            }
            if((x + y) == 4) {
                diag[1] -= callNum;
                if(diag[1] == 0) bingo--; 
            }

            if(bingo <= 0) {
                ret = callNum;
            }
        }
        
    }

    cout << ret;
    
}