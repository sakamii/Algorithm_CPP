//5644. [모의 SW 역량테스트] 무선 충전
/*
    빡구현
*/
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<int> map[10][10];
int a_route[100];
int b_route[100];
int bc[9];

int ydir[5] = {0, -1, 0, 1, 0};
int xdir[5] = {0, 0, 1, 0, -1};


int main(int argc, char** argv)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        for(int i = 0; i < 10; i++) {
            for(int j = 0; j < 10; j++) {
                map[i][j].clear();
            }
        }


        int result = 0;

        int m, a;
        cin >> m >> a;
        for(int i = 0; i < m; i++) {
            cin >> a_route[i];
        }
        for(int i = 0; i < m; i++) {
            cin >> b_route[i];
        }

        for(int ap = 0; ap < a; ap++) {
            int y, x, r, p;
            cin >> x >> y >> r >> p;
            x--;
            y--;

            bc[ap] = p;
            //xy로 부터 r거리 안에 있는 모든 노드에 ap번호 추가
            for(int ap_y = (y - r); ap_y <= (y + r); ap_y++) {
                if(ap_y < 0) ap_y = 0;
                if(ap_y >= 10) break;

                int xr = r - abs(y - ap_y);
                for(int ap_x = x - xr; ap_x <= (x + xr); ap_x++) {
                    if(ap_x < 0) ap_x = 0;
                    if(ap_x >= 10) break;

                    map[ap_y][ap_x].push_back(ap);
                }
                
            }
        }
        //밑에 a, b 최고 2개 찾을 때 초기값 설정을 위해 저장
        bc[8] = 0;

        int ay = 0;
        int ax = 0;
        int by = 9;
        int bx = 9;
        
        //처음위치 부터 계산해야 하므로 do-while 사용
        int i = -1;
        do {
            i++;
            int a_high[2] = {8, 8};
            int b_high[2] = {8, 8};
            // int idx = 0;
            
            //a중 제일 큰 두가지 고르기
            for(int j = 0; j < map[ay][ax].size(); j++) {
                int num = map[ay][ax][j];
                if(bc[num] > bc[a_high[0]]) {
                    a_high[1] = a_high[0];
                    a_high[0] = num;
                }
                else if(bc[num] > bc[a_high[1]]){
                    a_high[1] = num;
                }
            }
            //b중 제일 큰 두가지 고르기
            for(int j = 0; j < map[by][bx].size(); j++) {
                int num = map[by][bx][j];
                if(bc[num] > bc[b_high[0]]) {
                    b_high[1] = b_high[0];
                    b_high[0] = num;
                }
                else if(bc[num] > bc[b_high[1]]){
                    b_high[1] = num;
                }
            }

            //b중 제일 큰 두가지 고르기
            //제일 큰 거 두개 고르기
            //두개가 같다면 두번째거 비교 해서 더 큰것
            if((a_high[0] != b_high[0])) {
                result += bc[a_high[0]];
                result += bc[b_high[0]];
            }
            else{
                result += bc[a_high[0]];
                result += max(bc[a_high[1]], bc[b_high[1]]);
            }

            ay += ydir[a_route[i]];
            ax += xdir[a_route[i]];
            by += ydir[b_route[i]];
            bx += xdir[b_route[i]];
        }while(i < m);
        cout << "#" << test_case << " " << result <<endl;
	}
	return 0;
}