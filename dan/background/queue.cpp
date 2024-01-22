#include <iostream>
#include <queue>
using namespace std;

int main() {
	//큐 선언
	queue<int> que;
	
	//큐에 요소 추가하기
  // 0 1 2 3 4
	for (int i = 0; i < 5; i++) {
		que.push(i);
	}

	// 요소 삭제하기
  // front()는 값을 가져올 뿐 제거하지 않음
  // pop()으로 제거
	int output = que.front();
	que.pop();
	cout << output; // 0이 나옴

	// 큐의 전체 요소 출력하기
  // empty()는 비어있으면 1 채워져있으면 0
	while (!que.empty()) {
		cout << que.front() << " ";
		que.pop(); // 1 2 3 4
	}
}

