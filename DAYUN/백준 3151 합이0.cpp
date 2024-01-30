#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> stu(500);
long long cnt = 0;

int main() {

    //cin.tie(0);
    //cout.tie(0);
    //ios::sync_with_stdio(false);

    int n;
    //cin >> n;

    //stu.resize(n);

    //for (int i = 0; i < n; i++) {
    //    cin >> stu[i];
    //}

    n = 10000;
    stu.resize(n);
    fill(stu.begin(), stu.end(), 0);
    //sort(stu.begin(), stu.end());
    int ex = 9998;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {

            //binary search
            int MIN = j + 1;  //0 1 //10000
            int MAX = n - 1; //10000
            int k = -stu[i] - stu[j];
/*            int minK = 10000;
            int maxK = 0;
            while (MIN <= MAX) {
                int mid = (MIN + MAX) / 2;

                int stuMid = stu[mid];

                if (stuMid < k) MIN = mid + 1;
                else if (stuMid >= k) {
                    MAX = mid - 1;
                }

                if(stuMid == k) {
                    minK = min(minK, mid);
                    maxK = max(maxK, mid);
                }
            }*/

            //cnt += (maxK - minK);

            //for (; minK < n; minK++) {
            //    if (stu[minK] == k)
            //        cnt++;
            //    else break;
            //    //if(minK == (n - 1) )
            //        //cout << " ? ?" << endl;
            //}


            int u = upper_bound(stu.begin() + j + 1, stu.end(), -stu[i] - stu[j]) - stu.begin();
            int l = lower_bound(stu.begin() + j + 1, stu.end(), -stu[i] - stu[j]) - stu.begin();

            if (l != 10000)
            {
                cnt += (u - l);
            }
           
        }
       
            cout << i << endl;

    }
    cout << cnt;

    return 0;
}
