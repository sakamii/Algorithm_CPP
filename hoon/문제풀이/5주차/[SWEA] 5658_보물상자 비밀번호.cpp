#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <deque>
using namespace std;
/*
단순한 구현문제

회전시키면서 가능한 16진수들 찾아라!

⇒ 4조각 각각의 길이만큼 앞에서부터 이동시키면서 더하면 그만 아님?

⇒ 중복 제거 : set 이용 (set은 기본적으로 오름차순, greater를 통해 내림차순으로 변경)

k번째 수

⇒ iterator 이용해, k번째이면 출력후 종료
*/
int main()
{
    int t;
    cin >> t;
    for (int test_case = 1; test_case <= t; test_case++)
    {
        int n, k;
        string s;
        cin >> n >> k >> s;
        set<int, greater<int>> str_set;
        int temp = n / 4;
        for (int i = 0; i < s.length(); i++)
        {
            string s_temp = "";
            for (int j = 0; j < temp; j++)
            {
                s_temp += s[(i + j) % s.length()];
            }
            str_set.insert(stoi(s_temp, nullptr, 16));
        }
        int cnt = 0;
        for (auto it : str_set)
        {
            cnt++;
            if (cnt == k)
            {
                cout << "#" << test_case << " " << it << endl;
                break;
            }
        }
    }
    return 0;
}
