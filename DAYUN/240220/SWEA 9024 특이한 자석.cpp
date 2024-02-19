// 9024
/*
지석정보  회전 방향 정보
붙는 자석이면 같이 회전하지만 붙지 않는 자석이면 같이 회번하지 않음
*/

#include <iostream>
#include <queue>

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
        int K;
        int mag[4][8];
        int point[4] = {0};

        cin >> K;
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                cin >> mag[i][j];
            }
        }

        for (int i = 0; i < K; i++)
        {
            int start;
            int turn;
            int change[4] = {0};
            cin >> start >> turn;
            start--;
            change[start] = -turn;
            // 왼쪽
            int left_turn = turn;
            for (int left = start - 1; left >= 0; left--)
            {
                if (mag[left + 1][(point[left + 1] + 6) % 8] != mag[left][(point[left] + 2) % 8])
                {
                    change[left] = left_turn;
                    left_turn *= -1;
                }
                else
                {
                    break;
                }
            }

            // 오른쪽
            int right_turn = turn;
            for (int right = start + 1; right < 4; right++)
            {
                if (mag[right - 1][(point[right - 1] + 2) % 8] != mag[right][(point[right] + 6) % 8])
                {
                    change[right] = right_turn;
                    right_turn *= -1;
                }
                else
                {
                    break;
                }
            }

            for (int j = 0; j < 4; j++)
            {
                // cout << change[j] << " ";
                point[j] = (point[j] + change[j] + 8) % 8;
            }
        }

        int plus = 1;
        for (int i = 0; i < 4; i++)
        {
            // cout << mag[i][point[i]] << " ";
            result += (mag[i][point[i]] * plus);
            plus *= 2;
        }

        cout << "#" << test_case << " " << result << endl;
    }
    return 0;
}