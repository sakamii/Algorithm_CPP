#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*

binary search로 특정 값을 찾으면
그 좌우 인덱스를 곱하면 정답.
못찾으면 0

중복된 값이 입력되지 않기 때문에
map으로 값,인덱스를 저장해 그 앞뒤를 곱해 출력하는게 더 빠름.
*/
vector<int> v;
int n, q;
int main(int argc, char **argv)
{
    cin >> n >> q;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        v.push_back(temp);
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < q; i++)
    {
        int check;
        int idx = -1;
        cin >> check;
        int left = 0, right = n - 1;
        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (v[mid] < check)
            {
                left = mid + 1;
            }
            else if (v[mid] > check)
            {
                right = mid - 1;
            }
            else
            {
                idx = mid;
                break;
            }
        }
        if (idx != -1)
        {
            cout << idx * (n - 1 - idx) << "\n";
        }
        else
        {
            cout << 0 << "\n";
        }
    }
    return 0;
}