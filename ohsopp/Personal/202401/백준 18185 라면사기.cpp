
// https://www.acmicpc.net/problem/18185

#include <iostream>
using namespace std;

int n, a, b, ans, arr[10005];

int main() {
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> arr[i];
	
	for (int i = 0; i < n; i++) {
    	// 두 번째 공장의 라면 개수가 세 번째 공장의 라면 개수보다 큰 경우 세 번째 공장과 개수를 맞춘다.
    	// 다음 반복문에서 네 번째 공장과 연달아 3개(2번,3번,4번)를 짝지을 수 있기 때문. 만약 무조건 7원을 주고 사면, 세 번째 공장의 라면 개수가 0이 되고, 네 번째 공장과 짝지을 수 없다.
		if (arr[i + 1] > arr[i + 2]) {
			a = min(arr[i], arr[i + 1] - arr[i + 2]);
			ans += a * 5;
			arr[i] -= a; arr[i + 1] -= a;

			b = min(arr[i], min(arr[i + 1], arr[i + 2]));
			ans += b * 7;
			arr[i] -= b; arr[i + 1] -= b; arr[i + 2] -= b;
		}
		else {
			b = min(arr[i], min(arr[i + 1], arr[i + 2]));
			ans += b * 7;
			arr[i] -= b; arr[i + 1] -= b; arr[i + 2] -= b;

			a = min(arr[i], arr[i + 1]);
			ans += a * 5;
			arr[i] -= a; arr[i + 1] -= a;
		}
		ans += arr[i] * 3;
	}
	cout << ans;
}
