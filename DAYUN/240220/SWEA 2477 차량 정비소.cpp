// SWEA 2477 차량 정비소

/*
1. 접수 창고 모두 돌면서 pq_bt에 접수가 끝나는 시간, 접수한 사람, 접수 창고 번호(나중에 우선순위) 저장
2. pq_bt에서 우선순위는 정비 창고 우선순위와 같다

1.1 접수 창고를 도는 방법은 모든 번호순서대로 돌면서 사람이 시작한 시간t[i]가  끝나는 시간 보다  크면
1.2 만약 모든 창고가 시작한 시간보다 작으면 가장 끝나는 시간에 접수한다. 
*/

#include <iostream>
#include <queue>

using namespace std;

struct edge
{
    int time;
    int i;
    int j;
    //우선순위 : 정비 먼저 시작하는 조건
    //1. 접수 끝난 순서 
    //2. 접수 창고번호가 작은 수
    bool operator<(const edge& temp) const
    {
        if (time > temp.time)
            return true;
        else if (time == temp.time)
            return j > temp.j;
        else
            return false;
    };
};

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test_case;
    int T;
    cin >> T;
    for (test_case = 1; test_case <= T; ++test_case)
    {
        int N, M, K, A, B;
        int a_times[20] = {0};
        int b_times[20] = { 0 };
        //접수가 끝나는 시간, 접수한 사람, 접수 창고 번호
        priority_queue<edge> pq_bt;
        int t[1000];

        int resultA[1000] = { 0 };
        int resultB[1000] = {0 };
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

        // 접수 창고가 끝나는 시간
        int a_rest[20] = { 0 };
        for (int i = 0; i < K; i++)
        {
            //가장 빨리 끝나는 창고 숫자, 시간
            int min_a_rest_time = 10000000;
            int min_a_rest_j = 0;
            for (int j = 0; j < N; j++)
            {
                // 사람이 온 시간 >= 창구가 비는 시간
                if (t[i] >= a_rest[j])
                {
                    a_rest[j] = t[i] + a_times[j];
                    min_a_rest_j = -1;
                    pq_bt.push({ a_rest[j], i, j });
                    resultA[i] = j;
                    break;
                }

                if (a_rest[j] < min_a_rest_time)
                {
                    min_a_rest_time = a_rest[j];
                    min_a_rest_j = j;
                }
            }

            //사람이 들어왔을 때 쉬는 창고가 없는 경우
            if (min_a_rest_j != -1)
            {
                a_rest[min_a_rest_j] += a_times[min_a_rest_j];
                pq_bt.push({ a_rest[min_a_rest_j], i, min_a_rest_j });
                resultA[i] = min_a_rest_j;
            }
        }

        // 정비 창고가 끝나는 시간
        int b_rest[20] = { 0 };
        while (!pq_bt.empty())
        {
            int min_b_rest_time = 10000000;
            int min_b_rest_j = 0;
            int time = pq_bt.top().time;
            int i = pq_bt.top().i;
            pq_bt.pop();
            for (int j = 0; j < M; j++)
            {
                // 사람이 온 시간 >= 창구가 비는 시간
                if (time >= b_rest[j])
                {
                    b_rest[j] = time + b_times[j];
                    min_b_rest_j = -1;
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
                resultB[i] = min_b_rest_j;
            }
        }

        for (int i = 0; i < K; i++)
        {
            if ((resultA[i] == A) && (resultB[i] == B))
            {
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
}

