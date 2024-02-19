
// SWEA 1952 수영장

// 일 이용권 , 원이용권 비교
// 3달씩 비교   BFS
// 전체 금액과 연 이용권이랑 비교

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// vector<pair<int, int>> payM;
int payM[14];
int use3month = 0;
int dfs(int num, int last3, int r);

int main(int argc, char **argv)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int test_case;
	int T;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int result = 0;
		int pay[12] = {0};
		use3month = 0;

		// input
		int day, month, month3, year;
		cin >> day >> month >> month3 >> year;
		int plan[12];
		for (int i = 0; i < 12; i++)
		{
			cin >> plan[i];
		}
		//11월, 12월도 3달 가능하기 때문에 계산을 위해 추가 
		plan[12] = {0};
		plan[13] = {0};
		
		// 한달과 하루와 비교
		for (int i = 0; i < 12; i++)
		{
			pay[i] = min(month, day * plan[i]);
			result += pay[i];
		}

		//3달과 한달과 비교
		for(int i = 0; i < 10; i++) {
			payM[i] = pay[i] + pay[i + 1] + pay[i + 2] - month3;
			if(payM[i] < 0) payM[i] = 0;
		}
		dfs(0, -1, 0);

		result -= use3month;
		//1년과 비교
		result = min(result, year);

		cout << "#" << test_case << " " << result << endl;
	}
	return 0;
}

int dfs(int num, int last3, int r) {
	
	for(; num < 12; num++) {
		if(payM[num] <= 0) continue;
		else if (num > last3) {
			last3 = num + 2;
			r += payM[num];
		}
		//num의 이득이 이 전의 이득보다 작거나 같을 경우 -> 무조건 전에 꺼로 진행
		//아래는 num의 이득이 이 전의 이득보다 큰 경우
		else if(payM[last3 - 2] < payM[num]) {
			//다음꺼로 진행
			dfs(num + 1, num + 2, r - payM[last3 - 2] + payM[num]);
			//원래꺼로 진행
		}
	}
	use3month = max(r, use3month);
}
