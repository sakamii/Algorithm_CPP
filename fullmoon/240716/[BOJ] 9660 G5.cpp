#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	unsigned long long N;
	cin >> N;
	if (N == 1) {
		cout << "SK\n";
	}
	else {
		int rest = (N - 2) % 7;
		if (rest == 5 || rest == 0) {
			cout << "CY\n";
		}
		else {
			cout << "SK\n";
		}
	}
	return 0;
}
