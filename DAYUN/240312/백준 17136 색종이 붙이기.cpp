/*
    색종이

    10X10

    1로 되있는 데는 모두 색종이
    색종이의 최소 갯수
    10개줄에 종이의 각 칸 수
    색종이가 5x5 ~ 큰것부터 사용하는 경우
    (최대 사용 색종이 측정)
    색종이가 1개만 있을 떄,
    색종이가 2개만 있을 떄, 
    ...
    1x1만 있을 때 
    모든 종류의 종이가 각각의 경우가 존재
    ex 2, 4 만 사용한 경우 
    만들 수 있는 모든 사각형 계산?

    하나의 1그룹에서 나올 수 있는 모든 경우의 수 
    5를 한번 사용한 경우


    dfs
    만약 큰걸로 커버가능한 것이 있다 -> 그것을 제외했을 경우?

    union
    그룹 짓기 - 사이즈 저장 (가로, 세로 최소 사이즈)

    5x5가 가능한 경우->다음 작은 것 가능한지 확니
    prefix_sum

    1.5x5가 커버가능한 경우, 위치 저장 1~2
    2. 4x4가 커버가능한 경우 ..
    3. 1x1만 나머지 5개 이하인 경우 찾기
    모두 dfs로 안 겹치는 경우 찾기


*/

#include <iostream>
#include <vector>

using namespace std;

int paper[10][10];
//prefix sum
int ps[10][10];

bool cover(int i, int j, int k) {
}

int main() {
    int numblock = 0;
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            cin >> paper[i][j];
            if(paper[i][j]) numblock++;
        }
    }
    for(int i = 1; i < 10; i++) {
        for(int j = 1; j < 10; j++) {
            paper[i][j] += paper[i][j - 1] + paper[i - 1][j] - paper[i - 1][j - 1];
        }
    }

    vector<pair<int, pair<int, int>>> v;
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            for(int k = 1; k <= 4; k++) {
                if(j + k >= 10) break;
                if(i + k >= 10) break;
                if(paper[i + k][j + k] - paper[i][j + k] - paper[i + k][j] == k * k) {
                    v.push_back({k, {i, j}});
                }
            }
        }
    }

    //구역 a를 

}

