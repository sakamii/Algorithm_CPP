// SWEA 2117 홈 방법 서비스

/*
운영비용 : k*K + (k -1) * (k - 1);
도시에서 벗어난 경우 운영비용 변경되지 않음
운영비용은 최소 가장 많은 홍방범 서비스
단 무조건 운영비용 < 홍방범 서비스 금액

해결 방법
도시의 크기가 크지 않으므로
1. 제일 위 기준으로(집 기준) 돌기
1.1 정사각형에 들어가기
2.1 가운데에서 같은 거리가 최대 갈 수 있는 거리
3. 하나 기준으로 모든집에대해 거리를 구한다.
4. 최대 일떄부터 하나씩 줄여가면서 최대 가능한 것을 고른다.
5. 만약 첫번째 가 들어가지 않은 상태로 거리를 구해서 하나씩 줄여가면서 최대를 구하낟
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char **argv)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test_case;
    int T;
    cin >> T;
    for (test_case = 1; test_case <= T; ++test_case)
    {
        int result = 0;
        vector<pair<int, int>> house;
        vector<int> dist_array;
        // input
        int N, M;
        cin >> N >> M;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                int k;
                cin >> k;
                if (k == 1)
                {
                    house.push_back({i, j});
                }
            }
        }

        for (int hi = 0; hi < N; hi++)
        {
            for (int hj = 0; hj < N; hj++)
            {
                int max_dist = 0;
                for (int i = 0; i < house.size(); i++)
                {
                    int dist = abs(hi - house[i].first) + abs(hj - house[i].second);
                    dist_array.push_back(dist);
                }
                // cout << max_dist << endl;
                sort(dist_array.begin(), dist_array.end());
                int s;
                for (int i = 0; i <= dist_array.size(); i++)
                {
                    int dist = dist_array[i];
                    int cost = (dist * dist) + ((dist + 1) * (dist + 1));
                    if (result < ((M * (i + 1)) - cost))
                    {
                        // cout << hi << " " << hj << " " << result << " ";
                    }
                    result = max((M * (i + 1)) - cost, result);
                }
            }
        }

        cout << "#" << test_case << " " << result << endl;
    }
    return 0;
}