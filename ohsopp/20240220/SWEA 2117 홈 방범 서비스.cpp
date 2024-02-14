
/*
- 전체 사고 과정:
(1) 처음 생각 : 플러드필처럼 bfs로 풀면 되려나? -> 불필요한 탐색이 많을 것 같다.
(2) 고쳐먹은 생각 : 어차피 영역에 들어오는 집만 보면 되니까 집 vector 만들어서 집만 살펴보자.
(3) i,j를 1,1부터 n,n까지 탐색	-> 772ms
(4) i,j에서 대각선으로 포함되는 부분을 고려해서 탐색 -> 275ms
(5) k를 2*n부터 1까지 탐색하여 (현재 ans) >= (k일 때 최대로 가능한 서비스 영역) 이면 탐색 중지 -> 98ms


- 코드 리팩토링 :
(1)은 불필요한 탐색이 많다. (시도 안 함)
(2)는 집의 수가 많은 경우 불필요한 탐색이 많다.
그래서 (2)를 개선하기 위해 k를 1부터가 아닌 2*n부터 탐색하는 방법으로 시간 단축


- 해결 접근 방식 :
어떤 집 h가 서비스 영역에 포함되려면 서비스 중심부로부터의 h의 맨해튼 거리가 k보다 작으면 된다.

예를 들어, K = 3일 때의 서비스 영역은 다음과 같다.
□□■□□
□■■■□
■■■■■
□■■■□
□□■□□

이 때 중심부와의 맨해튼 거리가 3보다 작은 집(최대 2)의 위치는
서비스 영역에 들어오게 된다.
*/


#include <iostream>
#include <vector>
using namespace std;

/*
변수 네이밍
ofs: 대각선 길이만큼 시작지점과 끝지점을 줄이기 위한 offset 값
ans: 문제에서 구하려는 값 (서비스 제공받는 최대 집의 수)
cnt: 중심부 (i,j)에서 k일 때 서비스를 제공받는 집의 수, 초반 입력 변수로도 쓰임(그냥..)
home: 집 위치들만을 저장한 배열
*/
int t, n, m, ofs, ans, cnt;
vector<pair<int, int>> home;

int main() {
	cin >> t;

	for (int tc = 1; tc <= t; tc++) {
		cin >> n >> m;

		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++) {
				cin >> cnt;
				if (cnt) home.push_back({ i,j });
			}
		/*--------------------- 여기까지는 입력 ------------------------*/
		
		ans = 0;
		for (int k = 2 * n; k >= 1; k--) {
			if (k * k + (k - 1) * (k - 1) <= ans) break;

			// 탐색 시간 단축을 위한 대각선 방향으로 (1,1)과 (n,n)이 이미 포함되는 offset 거리 계산
			ofs = (k - 1) / 2;

			for (int i = 1 + ofs; i <= n - ofs + 1; i++)
				for (int j = 1 + ofs; j <= n - ofs + 1; j++) {
					cnt = 0;
					int kk = -(k * k + (k - 1) * (k - 1));	// kk: k일 때 운영 비용
					for (auto h : home)
						if (abs(i - h.first) + abs(j - h.second) < k) {	// 해당 집이 서비스 영역에 들어오면
							kk += m;
							cnt++;
						}
					if (kk >= 0 && ans < cnt)
						ans = cnt;
				}
		}
		cout << "#" << tc << " " << ans << endl;
		home.clear();
	}
}
