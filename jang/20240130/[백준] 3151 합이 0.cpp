#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int>A(N);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	sort(A.begin(), A.end());
	
	//답은 최대 10000C3이 될 수 있으니 long long으로 자료형 선택
	long long int ans = 0;
	
	//두개를 더하고 나머지 하나의 첫번째 인덱스, 마지막 인덱스를 찾아 개수를 정답에 더해준다
	for (int i = 0; i < N - 1; i++) {
		for (int j = i + 1; j < N ; j++) {
			long long int cnt = A[i] + A[j];
 			long long int k = lower_bound(A.begin() + j + 1, A.end(), -cnt) - A.begin();
			long long int u = upper_bound(A.begin() + j + 1, A.end(), -cnt) - A.begin();
			ans += u - k;
		}
	}
	cout << ans;
}
