#include<iostream>
#include<stack>

using namespace std;

int num[5000];
stack<int> st;

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    long long result = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }

    for (int i = 0; i < (n - 2); i++) {
        int cnt = 0;
        for (int j = i + 1; j < n; j++) {
            if (num[j] < num[i]) cnt++;
            else if (num[j] > num[i]) {
                st.push(cnt);
                cnt = 0;
            }
        }
        st.push(cnt);
        long long st_sum = 0;
        while (st.size() > 1) {
            st_sum += st.top();
            result += st_sum;
            st.pop();
        }
        if (!st.empty()) st.pop();

    }

    cout << result;
    return 0;
}