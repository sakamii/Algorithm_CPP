#include <iostream>
#include <vector>

using namespace std;

vector<int> v;

int n, k;
int max_v = -1;
int max_m = -1;
int m;
int result;

void bs(long int low, long int high) {
	int sum = 0;
	long int mid = (low + high) / 2;

	if (low > high) return;

	for (int i = 0; i < v.size(); i++) {
		sum += v[i] / mid;
	}
	if (sum >= k) {
		if (max_m < mid) max_m = mid;
		bs(mid + 1, high);
	}
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
