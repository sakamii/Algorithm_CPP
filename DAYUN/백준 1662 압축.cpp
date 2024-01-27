#include <iostream>
#include<string>
#include<stack>

using namespace std;

string str;

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    int result = 0;
    cin >> str;

    stack<pair<char, int>> st;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == ')')
        {
            pair<char, int> p = st.top();
            st.pop();
            int cnt = 0;
            while (p.first != '(')
            {
                cnt += p.second;
                p = st.top();
                st.pop();
            }
            p = st.top();
            st.pop();
            st.push({ '0', cnt * (p.first - '0') });

        }
        else {
            st.push({ str[i], 1 });
        }
    }

    while (!st.empty()) {
        result += st.top().second;
        st.pop();
    }

    cout << result;
    return 0;
}