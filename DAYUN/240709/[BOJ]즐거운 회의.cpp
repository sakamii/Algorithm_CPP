//24.07.06
// https://www.acmicpc.net/problem/31997
// 누적합

#include <iostream>

using namespace std;

int N;
int M;
int T;
int numMatchingPreFix[2000001];
pair<int, int> timeTable[200001];

void init();
void match();

int main(){
    init();
    match();

    int numMatch = 0;
    for(int i = 0; i < T; i++) {
        numMatch += numMatchingPreFix[i];
        cout << numMatch << "\n"; 
    }
}

void init(){
    int startTime;
    int endTime;

    cin >> N >> M >> T;
    for(int i = 1; i <= N; i++) {
        cin >> startTime >> endTime;
        timeTable[i] = {startTime, endTime};
    }
}

void match(){
    int A;
    int B;
    int startTime;
    int endTime;
    for(int i = 0; i < M; i++) {
        cin >> A >> B;
        startTime = timeTable[A].first > timeTable[B].first? timeTable[A].first : timeTable[B].first;
        endTime = timeTable[A].second > timeTable[B].second ? timeTable[B].second: timeTable[A].second;

        if(startTime >= endTime) continue;
        numMatchingPreFix[startTime]++;
        numMatchingPreFix[endTime]--;
    }
}