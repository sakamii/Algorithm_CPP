
#include <iostream>
using namespace std;

int mi;
string L, R;

int main() {
	cin >> L >> R;
  
	if (L.size() != R.size())
		cout << 0;

	else {
		for (int i = 0; i < L.size(); i++) {
			if (L[i] != R[i]) break;
			if (L[i] == R[i] && L[i] == '8') mi++;
		}
		cout << mi;
	}
}
