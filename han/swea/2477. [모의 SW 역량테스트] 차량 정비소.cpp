// @START 24.02.19:21:44
// @END 24.02.17:22:41
// @TOTAL 1H

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int T, N, M, K, A, B, answer;
int a[10], b[10], t[1001];

struct LOG {
  int userId = -1;
  int deskId = -1;
  int endTime = -1;

  void printLOG() {
    cout << "userID : " << userId << " deskID : " << deskId
         << " endTime : " << endTime << "\n";
  }
};

struct compare {
  bool operator()(LOG left, LOG right) {
    if (left.endTime > right.endTime)
      return true;
    else if (left.endTime == right.endTime) {
      if (left.deskId > right.deskId) return true;
    }
    return false;
  }
};

int main() {
  cin >> T;
  for (int tc = 0; tc < T; tc++) {
    answer = 0;
    cin >> N >> M >> K >> A >> B;
    for (int i = 1; i <= N; i++) {
      cin >> a[i];
    }
    for (int i = 1; i <= M; i++) {
      cin >> b[i];
    }
    for (int i = 1; i <= K; i++) {
      cin >> t[i];
    }

    int now = 0, cnt = 0;
    LOG deskA[10] = {}, deskB[10] = {};
    queue<int> waitA;
    priority_queue<LOG, vector<LOG>, compare> waitB;
    vector<LOG> usedA[10], usedB[10];

    while (true) {
      // 접수, 정비 창고 초기화
      // 1. 접수가 종료되는 인원이 있다면 접수 창구(a) 이용 기록을 등록하고 해당
      // 접수 창구를 초기화 > 정비 큐 대기열에 삽입
      for (int i = 1; i <= N; i++) {
        if (deskA[i].endTime == now) {
          waitB.push(deskA[i]);
          usedA[i].push_back(deskA[i]);
          deskA[i] = {-1, i, -1};
        }
      }
      // 2. 정비가 종료되는 인원이 있다면 정비 창구(b) 이용 기록을 등록하고 해당
      // 정비 창구를 초기화
      for (int i = 1; i <= M; i++) {
        if (deskB[i].endTime == now) {
          usedB[i].push_back(deskB[i]);
          deskB[i] = {-1, i, -1};
          cnt++;
        }
      }

      if (cnt == K) break;

      // 접수하러 온 인원(t)을 먼저 확인
      // 접수하러 온 인원이 있다면, 접수 큐 대기열에 삽입
      for (int i = 1; i <= K; i++) {
        if (t[i] == now) {
          waitA.push(i);
        } else if (t[i] > now) {
          break;
        }
      }

      // 비어있는 접수 창구의 수 만큼 순서대로 반복
      // 접수 큐 pop > 접수 창구 할당
      for (int i = 1; i <= N; i++) {
        if (deskA[i].userId == -1) {
          if (waitA.empty()) break;
          int userId = waitA.front();
          waitA.pop();
          deskA[i] = {userId, i, now + a[i]};
        }
      }

      // 비어있는 정비 창구의 수 만큼 순서대로 반복
      // 정비 큐 pop > 정비 창구 할당
      for (int i = 1; i <= M; i++) {
        if (deskB[i].userId == -1) {
          if (waitB.empty()) break;
          LOG user = waitB.top();
          waitB.pop();
          user.deskId = i;
          user.endTime = now + b[i];
          deskB[i] = user;
        }
      }

      now++;
    }

    int userDAT[1001] = {0};

    for (int i = 0; i < usedA[A].size(); i++) {
      userDAT[usedA[A][i].userId] = true;
    }

    for (int i = 0; i < usedB[B].size(); i++) {
      if (userDAT[usedB[B][i].userId]) {
        answer += usedB[B][i].userId;
      }
    }
    cout << "#" << tc + 1 << " " << (answer == 0 ? -1 : answer) << "\n";
  }
  return 0;
}
