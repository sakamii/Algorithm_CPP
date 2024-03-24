#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

vector<pair<int, char>> v;
queue<pair<int, int>> list[4]; 
int result[200000];

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    memset(result, -1, (n + 1) * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        char ch;
        int t;
        cin >> t >> ch;
        list[ch - 'A'].push({ -i, t });
    }

    int t = 0;
    while (true)
    {
        priority_queue<pair<pair<int, int>, int>> pq;
        for (int k = 0; k < 4; k++)
        {
            if (!list[k].empty())
                pq.push({ list[k].front(), k });
        }

        if (pq.empty())
            break;

        int check_t = t;
        while (!pq.empty())
        {
            int num = -pq.top().first.first;
            int time = pq.top().first.second;
            int dir = pq.top().second;
            pq.pop();
            if (t < time)
                t = time;
            if (list[(dir + 3) % 4].empty() || (list[(dir + 3) % 4].front().second > t))
            {
                result[num] = t;
                list[dir].pop();
                if (list[(dir + 1) % 4].empty() ||  (list[(dir + 1) % 4].front().second > t))
                {
                    if (!list[(dir + 2) % 4].empty()) {
                        int ndir = (dir + 2) % 4;
                        if (list[ndir].front().second <= t) {
                            result[-list[ndir].front().first] = t;
                            list[ndir].pop();
                        }
                    }
                }
                t++;
                break;
            }
        }
        if (check_t == t) break;
    }


    for (int i = 0; i < n; i++)
    {
        cout << result[i] << "\n";
    }

    return 0;
}