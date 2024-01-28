#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> v;
string str;


int main() {

	cin >> str;

	int count = 0;
	int sum = 0;

	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '(') {
			v.push_back(-1);
		}
		else if (str[i] >= '0' && str[i] <= '9') {
			if (str[i + 1] == '(') {
				v.push_back(str[i] - '0');
			}
			else {
				v.push_back(1);
			}
		}
		else if(str[i] == ')'){
			while (!v.empty()) {
				if (v.back() == -1) break;
				count += v.back();
				v.pop_back();
			}
			v.pop_back();
			count = count * v.back();
			v.pop_back();
			v.push_back(count);

			count = 0;
		}
	}

	while (!v.empty()) {
		sum += v.back();
		v.pop_back();
	}
	
	cout << sum;

	return 0;
}
