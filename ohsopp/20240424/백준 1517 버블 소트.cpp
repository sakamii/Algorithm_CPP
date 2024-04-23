
/*

세그트리로는 못 풀겠어서 질문 게시판 힌트써서 머지 소트로 해결.
(swap 하는 횟수) = (역순인 쌍의 개수)
역순인 쌍의 개수를 세는 Inversion counting 개념 -> 합병 정렬(Merge sort, 분할정복)로 해결하기

합병 정렬은 mid를 기준으로 왼쪽 배열과 오른쪽 배열을 말그대로 합치면서 정렬하는 정렬 알고리즘이다.
단, 이때 왼쪽 배열과 오른쪽 배열은 각각 정렬이 되어있음이 보장되어야 한다.
MergeSort 함수의 재귀를 통해 가장 밑단부터 정렬되어 합쳐지도록 구현(분할정복)하므로 무조건 보장된다.



예를 들어, 두 배열 (1 3 5 7)과 (2 4 6 8)을 머지소트 한다고 해보자.
왼쪽과 오른쪽 배열 각각의 인덱스 변수(lidx, ridx)와, 정렬되어 합쳐질 배열의 인덱스 변수(idx)가 필요하다.
위의 경우 역순인 쌍의 개수는 총 6개다. => (3,2), (5,2), (5,4), (7,2), (7,4), (7,6)
정렬된 배열과의 교차점 개수 = 역순인 쌍의 개수 = swap 횟수 = 6

어떻게 계산?
=> 왼쪽 배열의 merge가 끝나기 전에 오른쪽 배열 원소가 merge 되면 교차 발생!!


현재 교차점 개수 : 0
정렬된 배열 : [1]
그 다음은 오른쪽 배열에서 2를 가져와야 하므로 교차가 발생한다. => 교차점++
이 '2'는 그뒤로 있을 모든 왼쪽 배열과 교차점이 발생하게 된다. (3,2), (5,2), (7,2)

현재 교차점 개수 : 1
정렬된 배열 : [1,2]
그 다음은 왼쪽 배열에서 3을 가져와야 한다. 교차점이 1개 있으므로 결과값에 1 더해준다.

현재 교차점 개수 : 1
정렬된 배열 : [1,2,3]
그 다음은 오른쪽 배열에서 4를 가져와야 하므로 교차가 발생한다. => 교차점++
이 '4'는 그뒤로 있을 모든 왼쪽 배열과 교차점이 발생하게 된다. (5,4), (7,4)

현재 교차점 개수 : 2
정렬된 배열 : [1,2,3,4]
그 다음은 왼쪽 배열에서 5를 가져와야 한다. 교차점이 2개 있으므로 결과값에 2 더해준다.

...


왼쪽 배열에서 가져올 때는 교차점의 개수만큼 더해주고, 오른쪽 배열에서 가져올 때는 교차점의 개수를 하나 늘린다.
이 로직을 배열이 모두 합병될 때까지 실행한다.
*/


#include <iostream>
using namespace std;

int n, org[500001], tmp[500001];
long long ans;

void merge(int s, int e) {
	int mid = (s + e) / 2;
  // lidx: 왼쪽 배열 인덱스,  ridx: 오른쪽 배열 인덱스,  idx: 정렬될 배열 인덱스
	int lidx = s, ridx = mid + 1, idx = s;
	long long cnt = 0;

	while (lidx <= mid && ridx <= e) {
		if (org[lidx] <= org[ridx]) {
			tmp[idx++] = org[lidx++];
			ans += cnt;
		}
		else {
			tmp[idx++] = org[ridx++];
			cnt++;
		}
	}

	if (lidx > mid) {    // 왼쪽 배열 merge 끝나고 오른쪽 배열이 남은 경우
		while (ridx <= e)
			tmp[idx++] = org[ridx++];
  }
	if (ridx > e)	{    // 오른쪽 배열 merge 끝나고 왼쪽 배열이 남은 경우
		while (lidx <= mid) {
			tmp[idx++] = org[lidx++];
			ans += cnt;
		}
  }

	for (int i = s; i <= e; i++)  // 정렬된 값 원본 배열로 복사해주기
		org[i] = tmp[i];
}

void mergeSort(int s, int e) {
	if (s < e) {
		int mid = (s + e) / 2;
		mergeSort(s, mid);
		mergeSort(mid + 1, e);
		merge(s, e);
	}
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> org[i];

	mergeSort(1, n);
	cout << ans;
}
