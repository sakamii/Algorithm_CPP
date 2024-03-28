#include <iostream>
#include <vector>
using namespace std;

vector<int> v;

int n, k;
int max_v = -1;
int max_m = -1;
int m;
int result;

// binary search 
void bs(long int low, long int high) {
	int sum = 0;
	long int mid = (low + high) / 2;

	// 종료 조건
	if (low > high) return;

	// 랜선 갯수 구하기
	for (int i = 0; i < v.size(); i++) {
		sum += v[i] / mid;
	}

	// 랜선 갯수가 넘친다면 길이 늘려서 조사
	if (sum >= k) {
		if (max_m < mid) max_m = mid;
		bs(mid + 1, high);
	}
	// 랜선 갯수가 부족하다면 길이 줄여 조사
	else {
		bs(low, mid - 1);
	}

}

int main() {

	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		int k_value;
		cin >> k_value;
		v.push_back(k_value);
		if (max_v < k_value) {
			max_v = k_value;
		}
	}


	bs(1, max_v);

	cout << max_m;


	return 0;
}
