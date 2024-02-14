#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int arr[1010][1010];
int sum[1010][1010];

/*

누적합. 암기해야함.

*/

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int r, c, q;
	cin >> r >> c >> q;
	for (int i = 1; i <= r; i++)
		for (int j = 1; j <= c; j++)
			cin >> arr[i][j];

	for (int i = 1; i <= r; i++)
		for (int j = 1; j <= c; j++)
			sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + arr[i][j];

	int x1, y1, x2, y2;
	for (int i = 0; i < q; i++) {
		cin >> x1 >> y1 >> x2 >> y2;
		int out = sum[x2][y2] - (sum[x2][y1 - 1] + sum[x1 - 1][y2]) + sum[x1 - 1][y1 - 1];
		cout << out / ((x2 - x1 + 1) * (y2 - y1 + 1))<<"\n";
	}
}