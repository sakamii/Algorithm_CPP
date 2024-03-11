/*
    방법
    1. 모든 가능한 사각형 을 저장한다
    2. 1이 나온다.
    2.1 모든 가능한 경우의 수를 처리 (1부터) -> 0으로
    2.1.1 다음 0을 찾는다.
    2.

*/

#include <iostream>
#include <vector>

using namespace std;

int paper[10][10];
//prefix_sum
int ps[11][11];
int sizep[10][10];
int use_paper[6];
int numblock = 0;
int numPaper = 0;
int result = 101;

void cover(int i, int j, int k) {
    // for (int x = 0; x <= k; x++) {
    //     paper[i + k][j + x] = 0;
    // }

    // for (int y = 0; y < k; y++) {
    //     paper[i + y][j + k] = 0;
    // }
    for (int y = i; y <= i + k; y++) {
        for (int x = j; x <= j + k; x++) {
            paper[y][x] = 0;
        }
    }
}

void discover(int i, int j, int k) {
    for (int y = i; y <= i + k; y++) {
        for (int x = j; x <= j + k; x++) {
            paper[y][x] = 1;
        }
    }
}


void dfs(int y, int x) {

    while(paper[y][x] == 0) {
        if(x == 9) {
            y++;
            x = 0;
        }
        else x++;
        if(y >= 10) return;
    }

    numPaper++;
    if (numPaper >= result) {
        numPaper--;
        return;
    }

    //사용할 수 있는 색종이 사용
    //어떤 색종이를 사용할 것인지 
    for (int k = sizep[y][x] - 1; k >= 0; k--) {

        //커버된는 부분을 0으로 바꿈
        if(use_paper[k] == 5) continue;
        use_paper[k]++;
        cover(y, x, k);
        numblock -= ((k + 1) * (k + 1));
        if(numblock == 0) {
            result = min(result, numPaper);
        }
        else {
            //다음 색종이 사용 부분 찾기 
            dfs(y, x + k);
        }

        //커버된는 부분을 1으로 바꿈
        use_paper[k]--;
        numblock += ((k + 1) * (k + 1));
        discover(y, x, k);
    }

    numPaper--;
}



int main() {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cin >> paper[i][j];
            if (paper[i][j]) numblock++;
        }
    }
    if (numblock == 0) {
        cout << "0\n";
        return 0;
    }


    for (int i = 1; i <= 10; i++) {
        for (int j = 1; j <= 10; j++) {
            ps[i][j] = ps[i - 1][j] + ps[i][j - 1] - ps[i - 1][j - 1] + paper[i - 1][j - 1];
        }
    }

    //가능한 사각형 확인
    for (int i = 1; i <= 10; i++) {
        for (int j = 1; j <= 10; j++) {
            if (paper[i - 1][j - 1]) {
                sizep[i - 1][j - 1] = 1;
                for (int k = 1; k < 5; k++) {
                    if ((i + k) > 10 || (j + k) > 10) break;
                    if ((ps[i + k][j + k] - ps[i + k][j - 1] - ps[i - 1][j + k] + ps[i - 1][j - 1]) == ((k + 1) * (k + 1))) {
                        sizep[i - 1][j - 1] = k + 1;
                    }
                    else {
                        break;
                    }
                }
            }
        }
    }

    
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cout << sizep[i][j] <<" ";
        }
        cout << endl;
    }

    dfs(0, 0);

    if (result == 101) result = -1;
    cout << result;
}

