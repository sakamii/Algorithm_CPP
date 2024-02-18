// SWEA 2117 홈 방법 서비스

/*
운영비용 : k*K + (k -1) * (k - 1);
도시에서 벗어난 경우 운영비용 변경되지 않음
운영비용은 최소 가장 많은 홍방범 서비스
단 무조건 운영비용 < 홈방범 서비스 금액

해결 방법
도시의 크기가 크지 않으므로
1. 모든 구역과 집들 사이의 거리 계산하기
2. 가운데에서 같은 거리가 최대 갈 수 있는 거리
3. 모든 거리를 pq로 저장
4. 거리를 기준으로 모두 계산
5. 이익을 보는  최장 거리를 구한다.
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
                // 모든 구역 hi,hj에 대해 계산
                //해당 구역의 최대 거리
                int max_dist = 0;

                //원하는 위치에 대한 모든 거리 저장
                vector<int> dist_array;
                for (int i = 0; i < house.size(); i++)
                {
                    int dist = abs(hi - house[i].first) + abs(hj - house[i].second);
                    dist_array.push_back(dist);
                }		
                sort(dist_array.begin(), dist_array.end());
				
                //최대 거리 구하기
                for (int i = 0; i < dist_array.size(); i++)
                {
                    int dist = dist_array[i];
                    int cost = (dist * dist) + ((dist + 1) * (dist + 1));
                    if (cost <= (M * (i + 1)))
                    {
                        result = max(i + 1, result);
                    }
				}
            }
        }

        cout << "#" << test_case << " " << result << endl;
    }
    return 0;
}