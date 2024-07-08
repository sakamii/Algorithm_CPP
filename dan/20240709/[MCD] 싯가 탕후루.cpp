#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int n;
int arr[100001]; 
long long total = 0;
long long fee = INT_MAX;

int main() {
	cin >> n; 
	for (int i = 0; i < n; ++i) 
		cin >> arr[i]; 
	sort(arr, arr + n);

	
	for (int i = 0; i < N; ++i) {
		long long tmp = (long long)arr[i] * (long long)(N - i);
		if (tmp > total) {
			total = tmp;
			fee = arr[i]; 
		}
	}
	cout << total << " " << fee; 
}
