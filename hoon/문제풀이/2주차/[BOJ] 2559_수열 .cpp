#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int s[100001];
int main() {

	int n,k;
	cin >> n >> k;

	for(int i=1; i<=n; i++){
		int temp;
		cin >> temp;
		s[i] = s[i-1] + temp;
	}

	int maxi = -1e9;
	for(int i=k; i<=n; i++){
		maxi = max(maxi, s[i]-s[i-k]);
	}
	cout << maxi << endl;
	return 0;
}