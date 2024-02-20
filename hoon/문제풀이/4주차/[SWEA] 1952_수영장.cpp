#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int t;
int answer;
int a,b,c,d;
int map[13];
/*
dp 아니면 그리디로 풀수 있을것 같았지만
그리디로 3개월분부터 때려박고 풀면 당연이 1일 이용권이 더 싼 경우가 생김
-> 아마 이용권이 고정된 가격이었으면 그리디가 가능했을것
그리디 X이니 dp -> 어케 풀어야할지 모르겠음. dp는 무조건 가능해보임

그래서 완탐으로 풀었음
스케줄이 없는 구간에 대해서 dfs를 수행하고, 3개월치 이용권에 대해서만 따로 index를 +3 해줌.
*/
void dfs(int idx, int cost){
	if(idx >= 12){
		//cout << cost << endl;
		answer = min(answer,cost);
		return;
	}

	if(map[idx] == 0){
		dfs(idx+1,cost);
	}
	else{
		dfs(idx+1,cost+a*map[idx]);
		dfs(idx+1,cost+b);
		dfs(idx+3,cost+c);
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> t;
	for(int test_case = 1; test_case<=t; test_case++){
		
		cin >> a >> b >> c >> d;
		answer = d;
		for(int i=0; i<12; i++) cin >> map[i];
		dfs(0,0);
		cout<<"#"<<test_case << " " << answer << endl;
	}
}