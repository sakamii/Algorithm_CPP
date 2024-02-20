#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
using namespace std;
int t,k;
int m[4];
int mno, dt;
int answer;

/*
이전에 백준 '톱니바퀴'문제로 풀었던 문제라,
이번에는 비트마스킹을 통해서 풀어보고자 함
rotate 연산은 shift 연산으로 대체하여 풀었고,
각 방향에 대한 벡터를 저장해서 한번에 돌려주고,
최상단 비트를 확인해주는 식으로 구현함.

cpp의 rotate 연산시 나머지 부분은 0으로 채워지는 특성상
최상or최하단 비트를 저장하고, 쉬프트이후에 바꿔주는 작업이 필요했음.
*/
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> t;
	for(int test_case = 1; test_case<=t; test_case++){
		cin >> k;
		int rotate[4];
		for(int i=0 ;i<4; i++){
			m[i] = 0;
			rotate[i] = 0;
			for(int j=7; j>=0; j--){
				int temp;
				cin >> temp;
				m[i] += temp * pow(2,j);
			}
		}

		for(int i=0; i<k; i++){
			cin >> mno >> dt;
			mno -= 1;
			rotate[mno] = dt;
			int idx = mno-1;
			int prev = mno;
			while(idx >= 0){
				if(((m[prev] & 2) && (m[idx] & 32)) ) break;
				else if(((m[prev] & 2) == 0 && (m[idx] & 32) == 0)) break;
				else{
					rotate[idx] = -rotate[prev];
					prev = idx;
					idx -= 1;
				}
			}
			prev = mno;
			idx = mno + 1;
			while(idx <= 3){
				if(((m[prev] & 32) && (m[idx] & 2)) ) break;
				else if(((m[prev] & 32) == 0 && (m[idx] & 2) == 0)) break;
				else{
					rotate[idx] = -rotate[prev];
					prev = idx;
					idx += 1;
				}
			}

			for(int j=0; j<4; j++){
				if(rotate[j] == 1){
					int flag = m[j] & 1;
					m[j] = m[j] >> 1;
					if(flag) m[j] = m[j] | 128;
				}
				else if(rotate[j] == -1){
					int flag = m[j] & 128;
					m[j] = m[j] << 1;
					if(flag) m[j] = m[j] | 1;
				}
				rotate[j] = 0;
			}
		}
		answer = 0;
		for(int i=0; i<4; i++){
			if(m[i]&128){
				answer += pow(2,i);
			}
		}

		cout << "#" << test_case <<" " << answer << endl;
	}
}