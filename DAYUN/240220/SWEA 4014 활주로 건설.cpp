//4014 SWEA 활주로 건설
//1. 가로 세로 탐색
//2. 경사로 설치가 가능한가? valid 함수 써서 체크
//2.1 validR : 가로 체크 함수
//2.2 validC : 세로 체크 함수

#include<iostream>

using namespace std;
//input 지도
int map[20][20];
int N, X;
int validR(int r);
int validC(int C);

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
        int result = 0;
        //input
        cin >> N >> X;
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                cin >> map[i][j];
            }
        }

        //가로 탐색
        for(int i = 0; i < N; i++){
            result += validR(i);
        }
        //세로 탐색
        for(int i = 0; i < N; i++){
            result += validC(i);
        }

        cout << "#" << test_case << " " << result <<endl;
	}
	return 0;
}

//가로 체크 함수 
// return 1 : 가능 0 : 불가능
// 배열을 돌면서 높이 차이 발생 -> 경사로 가능 확인 -> 경사로 불가 (return 0), 경사로 가능 (다음으로)
int validR(int r) {
    int before = map[r][0];
    //제약사항으로 경사로가 있는 부분 저장
    int duple = -1;
    for(int i = 0; i < N; i++) {
        //차이가 1 초과일 경우 return
        if(abs(before - map[r][i]) > 1) return 0;
        //경사로 :  오른쪽 설치 
        if(map[r][i] < before) {
            for(int j = 1; j < X; j++) {
                if((i + j) >= N) return 0;
                if(map[r][i] != map[r][i + j]) {
                    return 0;
                }
            }
            i = i + X - 1;
            // 경사로가 있는 가장 큰 index
            duple = i;
        }
        //경사로 :  왼쪽 설치 
        else if(map[r][i] > before){
            for(int j = 2; j <= X; j++) {
                // **주의 ** 36/50 성공 case "duple == (i - j)" (X) 
                if(((i - j) < 0) || (duple >= (i - j))) return 0;
                if(before != map[r][i - j]) {
                    return 0;
                }
            }
        }
        before = map[r][i];
    }
    return 1;
}

//세로 체크 함수 
int validC(int c) {
    int before = map[0][c];
    int duple = -1;
    for(int i = 0; i < N; i++) {
        if(abs(before - map[i][c]) > 1) return 0;

        if(map[i][c] < before) {
            for(int j = 1; j < X; j++) {
                if((i + j) >= N) return 0;
                if(map[i][c] != map[i + j][c]) {
                    return 0;
                }
            }
            i = i + X - 1;
            duple = i;
        }
        else if(map[i][c] > before) {
            for(int j = 2; j <= X; j++) {
                if(((i - j) < 0) || (duple >= (i - j))) return 0;
                if(before != map[i - j][c]) {
                    return 0;
                }
            }
        }
        before = map[i][c];
    }
    return 1;
}
