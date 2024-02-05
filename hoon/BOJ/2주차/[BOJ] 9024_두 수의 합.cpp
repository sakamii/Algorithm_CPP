#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
연속된 수를 찾는게 아니기 때문에 누적합 불가능
투포인터 이용한 이분탐색이 해법.
*/
int main() {
	ios::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);
	int t;
	cin >> t;
	for(int i=0; i<t; i++){
		int n,k;
		cin >> n >> k;
		vector<int> v(n);
		for(int i=0; i<n; i++){
			cin >> v[i];
		}
		sort(v.begin(),v.end());
		int left = 0, right = n-1;
		int result = 1e9;
		int cnt = 0;
		while(left < right){
			int sum = v[left] + v[right];
			if(abs(sum-k) < abs(result-k)){
				cnt = 1;
				result = sum;
			}
			else if(abs(sum-k) == abs(result-k)){
				cnt +=1;
			}
			if(sum > k) right --;
			else left ++;
		}
		cout << cnt << endl;
	}
	return 0;
}