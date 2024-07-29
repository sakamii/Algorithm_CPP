
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int n, cnt;
string s;

int main() {
    cin >> n;
    unordered_map<string, int> um;
    vector<string> str;

    for (int i = 0; i < n; i++) {
        cin >> s;
        um.insert({ s, i });
    }

    for (int i = 0; i < n; i++) {
        cin >> s;
        str.push_back(s);
    }

    for (int i = 0; i < str.size(); i++)
        for (int k = i + 1; k < str.size(); k++)
            if (um[str[i]] > um[str[k]]) {
                cnt++;
                break;
            }
       
    cout << cnt;
}
