#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
struct Battery
{
    int x, y;
    int c;
    int p;
};
int dy[] = {0, -1, 0, 1, 0};
int dx[] = {0, 0, 1, 0, -1};
int M, battery_cnt, res;
int A[101];
int B[101];
vector<Battery> battery;
int main()
{

    int test_case;
    int T;

    cin >> T;

    for (test_case = 1; test_case <= T; test_case++)
    {
        memset(A, 0, sizeof(A));
        memset(B, 0, sizeof(B));
        battery.clear();
        res = 0;
        cin >> M >> battery_cnt;
        for (int i = 1; i <= M; i++)
            cin >> A[i];
        for (int i = 1; i <= M; i++)
            cin >> B[i];
        for (int i = 0; i < battery_cnt; i++)
        {
            int x, y, c, p;
            cin >> y >> x >> c >> p;
            battery.push_back({x, y, c, p});
        }
        vector<int> a_battery, b_battery;
        int ax = 1, ay = 1, bx = 10, by = 10;
        for (int i = 0; i <= M; i++)
        {
            a_battery.clear();
            b_battery.clear();
            ax += dy[A[i]];
            ay += dx[A[i]];
            bx += dy[B[i]];
            by += dx[B[i]];
            for (int j = 0; j < battery_cnt; j++)
            {
                int a_dist = abs(ax - battery[j].x) + abs(ay - battery[j].y);
                int b_dist = abs(bx - battery[j].x) + abs(by - battery[j].y);
                if (a_dist <= battery[j].c)
                    a_battery.push_back(j);
                if (b_dist <= battery[j].c)
                    b_battery.push_back(j);
            }
            /*
            이부분은 간단하게 하기 위해서 각 모든 케이스의 배터리 용량을 저장해 더함
            a가 bc1, bc2를 거쳐간다면 2개 모두를 벡터에 저장하고
            b가 bc2를 거쳐간다면
            a가 bc1을 가질때, bc2를 가질때 모두를 체크해서 maximum값을 전달해줌.
            M번 수행하면서 겹치는 부분을 check 하고 maximum 값을 찾는 방식의 코드도 가능해보임.
            */
            if (!a_battery.empty() && !b_battery.empty())
            {
                int maxSum = 0;
                for (int k = 0; k < a_battery.size(); k++)
                {
                    for (int l = 0; l < b_battery.size(); l++)
                    {

                        int tmpA = battery[a_battery[k]].p;
                        int tmpB = battery[b_battery[l]].p;

                        if (a_battery[k] == b_battery[l])
                        {
                            tmpA /= 2;
                            tmpB /= 2;
                        }
                        maxSum = max(tmpA + tmpB, maxSum);
                    }
                }
                res += maxSum;
            }
            else if (!a_battery.empty())
            {
                int maxA = 0;
                for (int k = 0; k < a_battery.size(); k++)
                    maxA = max(maxA, battery[a_battery[k]].p);
                res += maxA;
            }
            else if (!b_battery.empty())
            {
                int maxB = 0;
                for (int k = 0; k < b_battery.size(); k++)
                    maxB = max(maxB, battery[b_battery[k]].p);
                res += maxB;
            }
        }
        cout << "#" << test_case << " " << res << "\n";
    }
    return 0;
}
