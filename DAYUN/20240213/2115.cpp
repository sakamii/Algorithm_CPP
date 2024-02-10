// SWEA 2115 벌꿀채취

#include<iostream>

using namespace std;

int map[10][10]

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        int result = 0;

        int N, M, C;
        cin >> N >> M >> C;
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                cin >> map[i][j];
            }
        }

        cout << "#" << test_case << " " << result <<endl;

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}

//5 5 6 50 36
//5 5 7 