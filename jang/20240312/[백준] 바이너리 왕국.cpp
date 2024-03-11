#include <iostream>
#include <vector>
using namespace std;

int N,M,k,groupNum;
int array1[1000002];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> N >> M;
	bool flag = false;
	for (int i = 1; i <= N; i++) {
		cin >> array1[i];
		if (!array1[i]) flag = false;
		if (flag && array1[i]) continue;
		if (!flag && array1[i]) groupNum++, flag=true;
	}
	for (int i = 0; i < M; i++) {
		cin >> k;
		if (!k) cout << groupNum << '\n';
		else {
			cin >> k;
			if (array1[k] == 1) {
				continue;
			}
			array1[k] = 1;
			if (array1[k - 1] == 1 && array1[k + 1] == 1) groupNum--;
			else if (array1[k - 1] == 0 && array1[k + 1] == 0)groupNum++;
		}
	}	
}
