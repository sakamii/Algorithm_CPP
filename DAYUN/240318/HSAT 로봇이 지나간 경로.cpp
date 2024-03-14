/*
    H x W
    우좌하상
    L : 왼쪽으로 90회전
    R
    A : 바라보는 방향으로 두칸 전진
    랜덤갓
    같은 곳 두번 이상 방문 안함
    어떤 칸 갔는지는 알고 있다. 
*/

#include<iostream>

using namespace std;


int h, w;
int a, b;
int visited[25][25];
int ydir[] = {-1, 1, 0, 0};
int xdir[] = {0, 0, -1, 1};
int num_route = 0;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> h >> w;
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            char c;
            cin >> c;
            if(c =='.') visited[i][j] = 0;
            else {
                num_route++;
                visited[i][j] = 1;
            }
        }
    }

    int a = -1, b = -1;
    


    //시작점 잡기
    //한붓그리기
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            int link = 0;
            if(visited[i][j]) {
                for(int d = 0; d < 4; d++) {
                    int nexti = ydir[d] + i;
                    int nextj = xdir[d] + j;
                    if((nexti >= 0) && (nexti < h) && (nextj >= 0) && (nextj < w)) {
                        if(visited[nexti][nextj]) link++;
                    }
                }

                if(link % 2)  {
                    a = i;
                    b = j;
                    i = h;
                    break;
                }
            }
        }
    }
    if(a == -1) {
        for(int i = 0; i < h; i++) {
            for(int j = 0; j < w; j++) {
                if(visited[i][j]) {
                    a = i;
                    b = j;
                    i = h;
                    break;
                }
            }
        }
    }

    //모든 점에서 
    

    
}