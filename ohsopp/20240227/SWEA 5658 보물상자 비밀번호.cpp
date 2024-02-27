
/*
원형큐 대신 문자열을 2번 이어붙였다.
한 변의 문자 개수 l을 구한 뒤 4면에 걸쳐 한 번에서 l번까지 회전하고, 중복을 제거하기 위해 map<string, int>을 사용했다.
string의 존재 여부만을 판단하기 위함이므로 value 값은 중요하지 않아 그냥 1로 넣어줬다.
map은 기본적으로 키 값을 기준으로 오름차순 정렬이 되어있다.
따라서 map 원소의 개수에서 k를 뺀 해당 인덱스가 k번째로 큰 수가 된다.
*/

#include <iostream>
#include <string>
#include <map>
using namespace std;
 
int t, n, k, l;
map<string, int> m;
string s;
 
int htod(string str) {  // 단순히 string 16진수를, int형 10진수로 바꾸어주는 함수
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
        s += s;    // 문자열 2번 이어붙이기
        l = n / 4; // 한 변의 길이
 
        for (int i = 0; i < l; i++)
            for (int j = 0; j < 4; j++)
                m[s.substr(j * l + i, l)] = 1;    // insert() 메서드를 써도 되나 해당 구문이 더 간편해서 사용. key값이 없다면 추가하고, 있다면 value값을 바꿔줌.
 
        map<string, int>::iterator it;    // map은 key값이 곧 인덱스이기 때문에 기본 자료형 반복자로는 탐색할 수 없다. iterator 사용하기.
        k = m.size() - k;
 
        int i;
        for (i = 0, it = m.begin(); it != m.end(); it++, i++)
            if (i == k) {
                cout << "#" << tc << " " << htod(it->first) << '\n';
                break;
            }
    }
}
