#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	string num[30] = { "", "one", "two", "three", "four", "five", "six",
						"seven", "eight", "nine", "ten", "eleven", "twelve",
						"thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen",
						"nineteen", "twenty", "twenty one", "twenty two", "twenty three", "twenty four", "twenty five",
						"twenty six", "twenty seven", "twenty eight", "twenty nine" };
	
	int h, m;
	cin >> h >> m;

	if (m == 0) {
		cout << num[h] << " o' clock" << "\n";
	}
	else if (m == 15) {
		cout << "quarter past " << num[h] << "\n";
	}
	else if (m == 30) {
		cout << "half past " << num[h] << "\n";
	}
	else if (m == 45) {
		if (h == 12) {
			cout << "quarter to " << num[h] << "\n";
		}
		else {
			cout << "quarter to " << num[h + 1] << "\n";
		}
	}
	else if (m < 10) {
		cout << num[m] << " minute past " << num[h] << "\n";
	}
	else if (m < 30) {
		cout << num[m] << " minutes past " << num[h] << "\n";
	}
	else {
		if (h == 12) {
			cout << num[60 - m] << " minutes to " << num[1] << "\n";
		}
		else {
			cout << num[60 - m] << " minutes to " << num[h + 1] << "\n";
		}
	}
	return 0;
}
