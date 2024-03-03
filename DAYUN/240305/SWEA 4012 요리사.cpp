#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

int map[16][16];
int n;
int result;
bool a[16];

void bfs(int a, int choices);
void cook();

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
        result = 2147483647;
		memset(a, false, sizeof(a));

		cin >> n;
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				cin >> map[i][j];
			}
		}

		//0을 고른 상태로 시작
		a[0] = true;
		bfs(1, n / 2 - 1);

        cout << "#" << test_case << " " << result <<endl;
	}
	return 0;
}

// 선택 할 수 있는 가장 작은 수 k
// 앞으로 선택해야 하는 개수 level
// 만약 a = 8 9~15 7개 선택가능
void bfs(int k, int level) {
	if(level == 0) {
		//선택한 종류 연산 및 비교
		cook();
		return;
	}
	//8개 고르기 level : 
	for(int i = k; i <= (n - level); i++) {
		a[i] = true;
		bfs(i + 1, level - 1);
		a[i] = false;
	}

	return;
}

void cook() {
	int one = 0;
	int two = 0;
	for(int i = 0; i < n; i++) {
		for(int j = i + 1; j < n; j++) {
			if(a[i] && a[j]) {
				one += map[i][j];
				one += map[j][i];
			}
			else if(!a[i] && !a[j]) {
				two += map[i][j];
				two += map[j][i];
			}
		}
	}
	result = min(result, abs(two - one));
}
