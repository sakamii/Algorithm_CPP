#include <iostream>
#include <algorithm>
#include<vector>
#include<unordered_map>
using namespace std;
int n, m;
string str[3][20] = { {"twenty","one","two","three","four","five","six","seven",
	"eight", "nine","ten", "eleven","twelve","thirteen","fourteen", "sixteen","seventeen", "eighteen", "nineteen"},
	{"twenty", " o' clock", "past","to", "quater"," minute",""} };

int main() {
	cin >> n >> m;
	if (m == 0) {
    	cout << str[0][n] << str[1][1];
	}
	else if (m == 1) {
		cout << str[0][1] << " minute past " << str[0][n];
	}
	else if ((m > 1 and m < 15)||(m > 15 and m < 20)) {
		cout << str[0][m] << " minutes past " << str[0][n];
	}
    else if (m == 15) {
		cout << "quarter past " << str[0][n];
	}
    else if (m == 20) {
		cout << str[0][0] << " minutes past " << str[0][n];
	}
    else if ((m > 20 and m < 30)) {
		cout << str[0][0] <<" "<< str[0][m-20] << " minutes past " << str[0][n];
	}
    else if (m == 30) {
		cout << "half past " << str[0][n];
	}
    else if ((m > 30 and m < 40)) {
    	int now = 40 - m;
		int h = n + 1;
		cout << str[0][0] <<" "<< str[0][now] << " minutes to " << str[0][h];
	}
    else if (m == 40) {
		cout << str[0][0] << " minutes to " << str[0][n];
	}
    else if ((m > 40 and m < 45)||(m > 45 and m < 60)) {
    	int now = 60 - m;
		int h = n + 1;
		cout << str[0][now] << " minutes to " << str[0][h];
	}
    else if (m == 45) {
    	int h = n + 1;
		cout << "quarter to " << str[0][h];
	}
}
