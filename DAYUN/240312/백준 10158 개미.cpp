/*
    x, y 따로 생각하기
*/


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int w, h;
    int y, x;
    int end_time;
    cin >> w >> h;
    cin >> x >> y;
    cin >> end_time;

    int ytime = end_time;
    int xtime = end_time;

    //오른쪽 시작 
    //1. 만약 오른쪽 끝 도착하기 전에 시간이 끝나는 경우
    if (xtime < (w - x)) x += xtime;
    else {
        // 오른쪽 끝 이동시간
        xtime -= (w - x);
        // 한번 왕복하여 다시 오른쪽 끝까지 이동 
        xtime %= (w * 2);
        //만약 왼쪽 까지 갔다가 다시 오른쪽으로 이동하다 멈추는 경우
        if (xtime > w) { x = -w + xtime; }
        // 왼쪽으로 가다가 멈추는 경우
        else { x = w - xtime; }
    }
    //좌표를 문제 대로 하면, 모든 부호가 같음
    if (ytime <= (h - y)) y += ytime;
    else {
        ytime -= (h - y);
        ytime %= (h * 2);
        if (ytime > h) { y = -h + ytime; }
        else { y = h - ytime; }
    }

    cout << x << " " << y;
}