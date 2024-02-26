
#include <iostream>
#include <string>
#include <map>
using namespace std;
 
int t, n, k, l;
map<string, int> m;
string s;
 
int htod(string str) {
    int mul = 1, ret = 0;
    for (int i = str.size() - 1; i >= 0; i--) {
        int a;
        if (str[i] >= 'A' && str[i] <= 'Z') a = str[i] - 'A' + 10;
        else a = str[i] - '0';
 
        ret += a * mul;
        mul *= 16;
    }
    return ret;
}
 
int main() {
    cin >> t;
    for (int tc = 1; tc <= t; tc++) {
        m.clear();
        cin >> n >> k >> s;
        s += s;
        l = n / 4;
 
        for (int i = 0; i < l; i++)
            for (int j = 0; j < 4; j++)
                m[s.substr(j * l + i, l)] = 1;
 
        map<string, int>::iterator it;
        k = m.size() - k;
 
        int i;
        for (i = 0, it = m.begin(); it != m.end(); it++, i++)
            if (i == k) {
                cout << "#" << tc << " " << htod(it->first) << '\n';
                break;
            }
    }
}
