#include <iostream>
using namespace std;

int main() {
	int N;
	cin >> N;
	while (N--) {
		string a;
		cin >> a;
		int s = 0, e = a.length() - 1;
		int whatisit = 0;
		while (s <= e) {
			if (a[s] == a[e]) {
				s++;
				e--;
				continue;
			}
			else {
        //왼쪽이 틀렸을 때, 오른쪽이 틀렸을 때 두가지 경우 모두 살펴봐야됨
				whatisit += 1;
				int temps = s;
				int tempe = e;
				s++;
				while (s <= e) {
					if (a[s] == a[e]) {
						s++;
						e--;
						continue;
					}
					else {
						whatisit++;
						break;
					}
				}
        //왼쪽 하나 빼니까 되면 오른쪽거 살펴볼 필요 없음
				if (whatisit == 1) {
					cout << 1 << "\n";
					break;
				}
				else { //다시 whatisit 변수 1로 설정해주고 오른쪽 하나 옮기고 진행
					whatisit = 1;
					s = temps;
					e = tempe - 1;
					while (s <= e) {
						if (a[s] == a[e]) {
							s++;
							e--;
							continue;
						}
						else {
							whatisit++;
							cout << 2 << '\n';
							break;
						}
					}
					if(whatisit==1) cout << 1 << '\n';
				}
			}
			if (whatisit == 1 || whatisit == 2) break;
		}
		if(!whatisit) cout << whatisit << '\n';
	}
}
