#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*
	binary seach
	총 3개의 숫자 연산이 필요하기 때문에
	2개의 숫자의 합을 미리 구하고
	나머지 값을 이진탐색으로 찾는다.
*/

// 39032KB, 248ms
struct node {
	int s;
	int x;
	int y;
};

bool cmp(node left, node right) {
	return left.s < right.s;
}

vector<int> v;
vector<node> sum;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	int cnt = 0;

	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		v.push_back(a);
	}


	// 이진탐색을 위해 정렬
	sort(sum.begin(), sum.end(), cmp);

	for (int i = 0; i < N; i++) {
		int tar = v[i];

		int st = 0;
		int en = sum.size() - 1;
		int idx = 0;

		// 이진탐색
		// 구조체를 사용한 이유는 연산 과정에서
		// 자기자신은 제외하기 위해
		while (st <= en) {
			int mid = (st + en) / 2;

			if (tar > sum[mid].s) st = mid + 1;
			// tar과 같은 값이 여러가지면 제일 처음 index를 찾도록 한다.
			else if (tar <= sum[mid].s) {
				if (tar == sum[mid].s) idx = mid;
				en = mid - 1;
			}
		}

		// 자기 자신인지 판단하고 아니면 +1
		while (sum[idx].s == tar) {
			if (i != sum[idx].y && i != sum[idx].x) {
				cnt++;
				break;
			}
			idx++;
			if (idx > sum.size() - 1) break;
		}
	}

	cout << cnt;

	return 0;
}


#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*
	two pointer
	대놓고 투포인터 쓰라고 광고하는 문제
	start, end 시작 index 설정이 어려웠음
	이문제의 경우 이진탐색보다 빠름
	2156KB, 12ms
*/

vector<int> v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	int cnt = 0;

	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		v.push_back(a);
	}

	sort(v.begin(), v.end());


	for (int i = 0; i < N; i++) {
		int start = 0;
		int end = v.size() - 1;
		int tar = v[i];

		while (start < end) {
			int sum = v[start] + v[end];

			if (sum > tar) end--;
			else if (sum < tar) start++;
			else {
				if (start == i) start++;
				else if (end == i) end--;
				else {
					cnt++;
					break;
				}
			}
		}
	}
	

	cout << cnt;

	return 0;
}
