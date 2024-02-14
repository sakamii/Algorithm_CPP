#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
/*
투포인터를 통해 두 문자가 같으면 양옆에서 포인터를 조여줌.
두 문자가 다를 경우에는 flag를 두어, 좌측+1한 문자열과 우측-1한 문자열이 각각 palindrome인지 판단.
두 문자 모두 palindrome이 아닌 경우에는 2를 출력하게끔 구현했음.
*/
int main() {
	ios::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);
	int n;
	cin >> n;
	for(int i=0; i<n; i++){
		string s;
		cin >> s;
		int left = 0, right = s.length()-1;
		int cnt = 0;
		int flag1 = 1;
		while(left <= right){
			if(s[left] == s[right]){
				left += 1;
				right -= 1;
			}
			else if(s[left] != s[right]){
				flag1 = 0;
				break;
			}
		}
		int flag2 = 1;
		int flag3 = 1;
		if(flag1 == 0){
			int left1 = left+1, right1=right;
			while(left1 <= right1){
				if(s[left1] == s[right1]){
					left1 += 1;
					right1 -= 1;
				}
				else{
					flag2 = 0;
					break;
				}
			}
			left1 = left;
			right1=right-1;
			while(left1 <= right1){
				if(s[left1] == s[right1]){
					left1 += 1;
					right1 -= 1;
				}
				else{
					flag3 = 0;
					break;
				}
			}
		}
		if(flag1 == 1) cout << 0 << endl;
		else if(flag1 == 0 && flag2 == 0 && flag3 == 0) cout << 2 << endl;
		else cout << 1 << endl;
	}
	return 0;
}