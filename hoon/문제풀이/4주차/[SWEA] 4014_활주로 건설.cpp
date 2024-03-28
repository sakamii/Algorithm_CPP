#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <math.h>
using namespace std;
int t,n,m;
int map[22][22];
int answer;

/*
쌩 구현문제였다.
index를 조절해주는것이 어려웠음.
index를 늘려주면서 이전 값과 비교해 현재 위치가 오르막길인지 내리막길인지 파악하는것이 중요
오르막길의 경우 이전부터 체크해온 count가 m의 크기 이상이면 건설이 가능하지만
내리막길이라면 앞에서부터 체크해온 count는 동일한 경사를 의미하므로 의미가 없음.
그래서 count를 초기화해주고, 반복문을 새로 세워 m 만큼의 내리막길과 동일한 평지가 있는지를 파악해주는것이 중요함.

*/
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> t;
	for(int test_case = 1; test_case<=t; test_case++){
		cin >> n >> m;
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				cin >> map[i][j];
			}
		}
		answer = 0;
		//가로행
		for(int i=0; i<n; i++){
			bool check = true;
			int prev = map[i][0];
			int length = 1;
			for(int j=1; j<n; j++){
				if(prev == map[i][j]){
					length ++;
					continue;
				}
				else{
					if(map[i][j]-prev == 1){
						if(length >= m){
							prev = map[i][j];
							length = 1;
							continue;
						}
						check = false;
						break;
					}
					if(map[i][j]-prev == -1){
						prev = map[i][j];
						length = 1;
						if(j+m > n){
							check =false;
							break;
						}
						for(int k=1; k<m; k++){
							j+=1;
							if(map[i][j] == prev)length++;
						}
						if(length == m){
							length = 0;
							
							continue;
						}
						check = false;
						break;
					}
					check = false;
					break;
				}
			}
			if(check) answer ++;
			// else{
			// 	cout << i << endl;
			// }
		}

		//세로열
		for(int j=0; j<n; j++){
			bool check = true;
			int prev = map[0][j];
			int length = 1;
			for(int i=1; i<n; i++){
				if(prev == map[i][j]){
					length ++;
					continue;
				}
				else{
					if(map[i][j]-prev == 1){
						if(length >= m){
							prev = map[i][j];
							length = 1;
							continue;
						}
						check = false;
						break;
					}

					if(map[i][j]-prev == -1){
						prev = map[i][j];
						length = 1;
						if(i+m > n){
							check =false;
							break;
						}
						for(int k=1; k<m; k++){
							i+=1;
							if(map[i][j] == prev)length++;
						}
						if(length == m){
							length = 0;
							continue;
						}
						check = false;
						break;
					}
					check = false;
					break;
				}
			}
			if(check) answer ++;
		}
		cout << "#" << test_case <<" " << answer << endl;
	}
}