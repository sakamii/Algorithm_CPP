// SWEA 2477 차량 정비소

/*
고객 만적도 설문지 창구번호 접수N 정비m
각 시간(모든 다 동일) a b
차량정비소 도착 시간 t
빈 접수팡고
*/

#include <iostream>
#include <queue>

using namespace std;

struct edge
{
    int time;
    int i;
    int j;
    bool operator<(const edge &temp) const
    {
        if (time > temp.time)
            return true;
        else if (time == temp.time)
            return j > temp.j;
        else
            return false;
    };
};

int main(int argc, char **argv)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ``` int test_case;
    int T;
    cin >> T;
    for (test_case = 1; test_case <= T; ++test_case)
    {
        // 빡구현
        // input
        int N, M, K, A, B;
        int a_times[20];
        int b_times[20];
        priority_queue<edge> pq_bt;
        int t[1000];

        int resultA[20];
        int resultB[20];
        int result = 0;

        cin >> N >> M >> K >> A >> B;
        A--;
        B--;
        for (int i = 0; i < N; i++)
        {
            cin >> a_times[i];
        }
        for (int i = 0; i < M; i++)
        {
            cin >> b_times[i];
        }
        for (int i = 0; i < K; i++)
        {
            cin >> t[i];
        }

        int a_rest[20] = {0};
        for (int i = 0; i < K; i++)
        {
            int min_a_rest_time = 10000000;
            int min_a_rest_j = 0;
            for (int j = 0; j < N; j++)
            {
                // 사람이 온 시간 >= 창구가 비는 시간
                if (t[i] >= a_rest[j])
                {
                    a_rest[j] = t[i] + a_times[j];
                    min_a_rest_j = -1;
                    pq_bt.push({a_rest[j], i, j});
                    cout << a_rest[j] << " ";

                    resultA[i] = j;
                    break;
                }

                if (a_rest[j] < min_a_rest_time)
                {
                    min_a_rest_time = a_rest[j];
                    min_a_rest_j = j;
                }
            }

            if (min_a_rest_j != -1)
            {
                a_rest[min_a_rest_j] += a_times[min_a_rest_j];
                pq_bt.push({a_rest[min_a_rest_j], i, min_a_rest_j});
                cout << a_rest[min_a_rest_j] << " ";
                resultA[i] = min_a_rest_j;
            }
        }
        // return 0;
        cout << endl;
        cout << "B" << endl;
        int b_rest[20] = {0};
        while (!pq_bt.empty())
        {
            // cout << 2;
            int min_b_rest_time = 10000000;
            int min_b_rest_j = 0;
            int time = pq_bt.top().time;
            int i = pq_bt.top().i;
            cout << time << "," << i << " ";
            pq_bt.pop();
            for (int j = 0; j < M; j++)
            {
                // 사람이 온 시간 >= 창구가 비는 시간
                if (time >= b_rest[j])
                {
                    b_rest[j] = time + b_times[j];
                    min_b_rest_j = -1;
                    // cout << b_rest[j] << " ";
                    resultB[i] = j;
                    break;
                }

                if (b_rest[j] < min_b_rest_time)
                {
                    min_b_rest_time = b_rest[j];
                    min_b_rest_j = j;
                }
            }

            if (min_b_rest_j != -1)
            {
                b_rest[min_b_rest_j] += b_times[min_b_rest_j];
                // cout << b_rest[min_b_rest_j] << " ";
                resultB[i] = min_b_rest_j;
            }
            // cout << resultB[i] << endl;
        }

        cout << endl;
        for (int i = 0; i < K; i++)
        {
            // cout << resultA[i]  << ","<< resultB[i] << " ";
            if ((resultA[i] == A) && (resultB[i] == B))
            {
                cout << i << endl;

                result += (i + 1);
            }
        }

        if (result == 0)
        {
            result = -1;
        }

        cout << "#" << test_case << " " << result << endl;
    }

    return 0;

    ```
}