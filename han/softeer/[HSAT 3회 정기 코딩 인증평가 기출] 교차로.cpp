#include <iostream>
#include <queue>
#include <tuple>
#include <vector>

using namespace std;

const int MAX_N = 200001;
const int A = 0, B = 1, C = 2, D = 3; // 오른쪽으로 - 1 되는 위치를 확인

int N, T, n = 1;
int answer[MAX_N];
pair<int, int> vect[MAX_N];
queue<int> pos[4];

bool isPossible() {
    for(int i = A; i <= D; i++) {
        if(pos[i].empty()) return true;
    }
    return false;
}

bool isAllEmptyPos() {
    for(int i = A; i <= D; i++) {
        if(!pos[i].empty()) return false;
    }
    return true;
}

// 자동차 통과 제어
// 무조건 나가야 함
void passingCars() {
    bool flag = false;
    vector<int> passed;
    for(int i = A; i <= D; i++) {
        if(pos[i].empty()) continue;
        int right = (i == 0 ? 3 : i - 1);
        int idx;
       
        idx = pos[i].front();
        
        if(pos[right].empty()) {
            answer[idx] = T;
            passed.push_back(i);
            flag = true;
        }
    }
    for(int i : passed) {
        pos[i].pop();
    }
    if(flag) T++;
}

void inputCars() {
    while(n <= N) {
        int t, w;
        tie(t, w) = vect[n];
        if(t == T) {
            pos[w].push(n);
            n++;
        } else {
            if(isAllEmptyPos()) {
                T = t;
                pos[w].push(n);
                n++;
            } else {
                break;
            }
        }
    }
    
}


int main(int argc, char** argv) {
    cin >> N;
    fill(answer, answer + N + 1, -1);
    for(int i = 1; i <= N; i++) {
        int t; char w;
        cin >> t >> w;
        vect[i] = {t, w - 'A'};
    }
    
    while(true) {
        if(!isPossible()) break;
        if(n > N && isAllEmptyPos()) break;
        passingCars();
        inputCars();
    }
    for(int i = 1; i <= N; i++) {
        cout << answer[i] << "\n";
    }
    return 0;
}