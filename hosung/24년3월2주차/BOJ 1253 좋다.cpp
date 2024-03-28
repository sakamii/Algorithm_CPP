#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
* 이진 탐색을 통해 두 수의 합이 주어진 수에 존재하는 지 찾아낸다
* 이때 두 수의 합이 존재하는 수의 인덱스를 배열의 크기로 초기화하여
* 존재하면 두수의 합들 중 맨 앞 인덱스를 가리키게 하고
* 두수의 합보다 작거나 존재하지 않을 경우 continue를 하여 가지치기 한다
* visited배열을 통해 합이 같지만 다른 수들을 포함한 좋은 수를 표시하고
* 시간초과를 막기 위해 합이 같지만 다른 수들이 나올 때 마다 다음 인덱스로
* 가리키도록 하려고 합이 같지만 다른 수가되는 첫 인덱스에 값을 나타날 때마다
* 증가시켜 보정하였다
* 투포인터로 하기에 구현력이 부족해서 이와 같이 해결함
*/

vector<long long>good;
int visited[2000];

bool chk(int mid, long long sum) {
    return sum <= good[mid];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        long long num;
        cin >> num;
        good.push_back(num);
    }

    sort(good.begin(), good.end());

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i != j) {
                int tmp = good[i] + good[j];
                //이진탐색
                int start = 0;
                int eNd = N - 1;
                int mid = 0;
                int idx = N;
                while (start <= eNd) {
                    mid = (start + eNd) / 2;
                    if (chk(mid, tmp)) {
                        eNd = mid - 1;
                        idx = min(mid, idx);
                    }
                    else {
                        start = mid + 1;
                    }
                }

                if (idx == N) continue; //존재X 다음으로
                if (good[idx] != tmp) continue; //찾았는데 작은 값이면 다음으로

                int correction = 0;
                if (visited[idx] >= 1) {
                    correction = visited[idx];
                    visited[idx]++;
                }

                for (int k = idx + correction; k < N; k++) {
                    if (good[idx] != good[k]) {
                        break;
                    }
                    else {
                        if (i == k || j == k) continue;
                        if (visited[k] == 0) {
                            visited[k] = 1;
                            break;
                        }
                    }
                }
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < N; i++) {
        if (visited[i] >= 1) {
            ans++;
        }
    }

    cout << ans;

    return 0;
}


