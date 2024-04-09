/////////////////////////////////////////////////////////////////////////////////////////////
// 기본 제공코드는 임의 수정해도 관계 없습니다. 단, 입출력 포맷 주의
// 아래 표준 입출력 예제 필요시 참고하세요.
// 표준 입력 예제
// int a;
// float b, c;
// double d, e, f;
// char g;
// char var[256];
// long long AB;
// cin >> a;                            // int 변수 1개 입력받는 예제
// cin >> b >> c;                       // float 변수 2개 입력받는 예제 
// cin >> d >> e >> f;                  // double 변수 3개 입력받는 예제
// cin >> g;                            // char 변수 1개 입력받는 예제
// cin >> var;                          // 문자열 1개 입력받는 예제
// cin >> AB;                           // long long 변수 1개 입력받는 예제
/////////////////////////////////////////////////////////////////////////////////////////////
// 표준 출력 예제
// int a = 0;                            
// float b = 1.0, c = 2.0;               
// double d = 3.0, e = 0.0; f = 1.0;
// char g = 'b';
// char var[256] = "ABCDEFG";
// long long AB = 12345678901234567L;
// cout << a;                           // int 변수 1개 출력하는 예제
// cout << b << " " << c;               // float 변수 2개 출력하는 예제
// cout << d << " " << e << " " << f;   // double 변수 3개 출력하는 예제
// cout << g;                           // char 변수 1개 출력하는 예제
// cout << var;                         // 문자열 1개 출력하는 예제
// cout << AB;                          // long long 변수 1개 출력하는 예제
/////////////////////////////////////////////////////////////////////////////////////////////

#include<iostream>
#include<queue>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

vector<pair<pair<int, int>, pair<int, int>>> v;
int high[20];
int dfs(int s, int e);


int main(int argc, char** argv)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	int test_case;
	int T;
	// cin>>T;
    T = 1;
	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
    
	for(test_case = 1; test_case <= T; ++test_case)
	{
        memset(high, 0, sizeof(high));

        int n, i, w, h, d;
        cin >> n;
        v.resize(n * 6);
        for(i = 0; i < n; i++) {
            cin >> w >> h >> d;
            v[i] = {{w, h}, {d, i}};
            v[i] = {{h, w}, {d, i}};
            v[i] = {{h, d}, {w, i}};
            v[i] = {{d, h}, {w, i}};
            v[i] = {{w, d}, {h, i}};
            v[i] = {{d, w}, {h, i}};
        }


        for(int i = 0; i < (1 << n); i++) {
            if((i >> 2) & 1) {
                int temp = 0;

            }
        }
        sort(v.begin(), v.end());

        int result = 0; 
        // w = pq.top().first;
        // h = pq.top().second.first;
        // d = pq.top().second.second;
        // pq.pop();
        cout << dfs(0, (n * 6) - 1) << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}

int dfs(int s, int e) 
{
    int i;
    int result = 0;
    bool flag = false;
    for(i = s; i < e; i++) {
        if(v[i].second.first <= high[v[i].second.second]) continue;
        if(v[i].first.second >= v[i + 1].first.second) {
            result = v[i].second.first, high[v[i].second.second]);
        }
        else {
            flag = true;

            result += max(max(v[i].second.first, high[v[i].second.second]) + dfs(i + 2, e), v[i + 1].second.first - high[v[i + 1].second.second] + dfs(i + 3, e));
            cout << endl;
            break;
        }
    }

    if(!flag) {
        result += v[e].second.second;
    }
    return result;
}

