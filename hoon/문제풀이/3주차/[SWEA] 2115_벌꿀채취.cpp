#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int t;
int n,m,c;
int map[11][11];
int diff_row1_maxi = 0;
int diff_row2_maxi = 0;
int temp_result = 0;
int same_row_maxi = 0;
void dfs1(int y, int end_x, int x, int sum, int square_sum){
	if(sum <= c){
		temp_result = max(temp_result, square_sum);
	}
	else return;
	for(int i=x; i<end_x; i++){
		dfs1(y,end_x,i+1,sum+map[y][i],square_sum+map[y][i]*map[y][i]);
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> t;
	for(int test_case = 1; test_case<=t; test_case++){
		cin >> n >> m >> c;
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				cin >> map[i][j];
			}
		}
		//서로다른 두 행 고르기
		int answer = 0;
		for(int i=0; i<n-1; i++){
			for(int j=i+1; j<n; j++){
				diff_row1_maxi = 0;
				diff_row2_maxi = 0;
				for(int k=0; k<n-m+1; k++){
					temp_result = 0;
					dfs1(i,k+m,k,0,0);
					diff_row1_maxi = max(diff_row1_maxi,temp_result);
					temp_result = 0;
					dfs1(j,k+m,k,0,0);
					diff_row2_maxi = max(diff_row2_maxi,temp_result);
				}
				answer = max(answer,diff_row1_maxi+diff_row2_maxi);
			}
		}

		//서로 같은 행 고를때

		cout<<"#"<<test_case << " " << answer << endl;
	}
}