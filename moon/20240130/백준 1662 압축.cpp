#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> v;
string str;

/*
	문자열로 풀어야 한다는 부분에 집착해서 오래걸린 문제
	'('앞 문자를 제외하고는 문자열의 길이만 중요할 뿐
	그 값이 어떤 값인지는 상관이 없다는 것이 중요
*/
int main() {

	cin >> str;

	int count = 0;
	int sum = 0;

	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '(') {
			v.push_back(-1);
		}
		else if (str[i] >= '0' && str[i] <= '9') {
			// '(' 앞 문자이기 때문에 char -> int로 변환하여 value 유지
			if (str[i + 1] == '(') {
				v.push_back(str[i] - '0');
			}
			// 나머지 괄호안 문자 1개당 크기 1을 의미하므로
			// 전부 int(1)로 변환
			else {
				v.push_back(1);
			}
		}
		else if (str[i] == ')') {
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

	// 압축이 시작되기 전에 존재하는 문자열 길이 추가
	while (!v.empty()) {
		sum += v.back();
		v.pop_back();
	}

	cout << sum;

	return 0;
}


/*
	첫번째로 시도했던 방법 문자열의 길이를 조건에 
	맞게 늘려 결과값을 문자열의 길이를 출력을 시도했지만
	최대 문자열의 길이가 2,147,473,647로 메모리 크기 초과로 실패
*/

/*#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<char> v;
string str;
string box;
string s;

void zip(int x) {

	for (int i = x; i >= 0; i--) {
		if (v.back() == '(') {
			v.pop_back();
			break;
		}
		s = s + v.back();
		v.pop_back();
	}


	int r = v.back() - '0';
	v.pop_back();

	for (int i = 0; i < r; i++) {
		box = box + s;
	}

	s = box;
	box.clear();
}

int main() {

	cin >> str;

	for (int i = 0; i < str.length(); i++) {
		if (str[i] == ')') {
			zip(v.size() - 1);
		}
		else {
			v.push_back(str[i]);
		}
	}

	while (v.size() > 0) {
		s = s + v.back();
		v.pop_back();
	}

	cout << s.length();

	return 0;
}
*/
