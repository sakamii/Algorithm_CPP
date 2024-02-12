// SWEA 2115 벌꿀채취

#include<iostream>
#include<algorithm>

using namespace std;

int map[10][10];
int N, M, C;

int run(int r1, int c1, int r2, int c2);

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        int result = 0;

        cin >> N >> M >> C;
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                cin >> map[i][j];
            }
        }
        // cout << endl;

        int r1 = 0, c1 = 0, r2, c2;
        while(r1 < N)
        {
            r2 = r1;
            c2 = c1 + M;
            while(r2 < N) {
                // result = max(run(r1, c1, r2, c2), result); 
                // cout << result << " ";
                if((c2 + M) > N) {
                    r2++;
                    if(r2 >= N) break;
                    c2 = 0;
                }
                int r = run(r1, c1, r2, c2);
                if(r > result ) {
                    // cout << r <<endl;
                    result = r;
                }
                c2++;

            }
            c1++;
            if((c1 + M) > N) {
                r1++;
                c1 = 0;
            }
        }

        cout << "#" << test_case << " " << result <<endl;

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}

int run(int r1, int c1, int r2, int c2) {
    // cout << r1 <<"," << c1 << "," << r2 <<"," << c2  << " "; 

    int n = 1;
    for(int i = 0; i < M; i++) {
        n *= 2;
    }
    
    bool flag = false;
    if((r1 + c1 + r2 + c2) == 2) flag = true;

    int maxSum1 = 0, maxSum2 = 0;
    for(int i = 0; i < n; i++) {
        int sum1 = 0, sum2 = 0;
        int b1 = 0, b2 = 0;
        for(int j = 0; j < M; j++) {
            if((i >> j) % 2) {
                b1 += map[r1][c1 + j];
                b2 += map[r2][c2 + j];
                sum1 += map[r1][c1 + j] * map[r1][c1 + j];
                sum2 += map[r2][c2 + j] * map[r2][c2 + j];
            }
        }
        if(b1 <= C) maxSum1 = max(sum1, maxSum1);
        if(b2 <= C) maxSum2 = max(sum2, maxSum2);
    }
    // cout << maxSum1 + maxSum2 << " ";
    // cout << endl;
    return maxSum1 + maxSum2;
}