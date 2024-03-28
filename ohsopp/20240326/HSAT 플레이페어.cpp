
/*
하라는 대로 하면 되는 구현 문제
알파벳을 J를 제외한 5X5 encode 맵에 할당하면서 동시에 해당 알파벳의 xy 좌표를 저장.
5X5를 매번 돌아도 괜찮지만 속도가 약간 빠르고 무엇보다 코드가 간결해짐.
메세지를 2개 문자씩 보면서 쌍을 만들어줌.
그뒤로 행이 같은 경우, 열이 같은 경우, 모두 다른 경우로 나누어서 문장 암호화.
*/
#include <iostream>
#include <vector>
#define pii pair<int, int>

using namespace std;

string msg, key;
pii xy[26];
char encode[5][5];
bool alp[26];

int main() {
    cin >> msg >> key;

    int idx = 0;
    for (int i = 0; i < key.size(); i++) {
        if (alp[key[i] - 'A']) continue;
        alp[key[i] - 'A'] = 1;
        encode[idx / 5][idx % 5] = key[i];
        xy[key[i] - 'A'] = { idx / 5, idx % 5 };
        idx++;
    }

    for (int i = 0; i < 26; i++) {
        if (alp[i] || char(i + 'A') == 'J') continue;
        else {
            encode[idx / 5][idx % 5] = char(i + 'A');
            xy[i] = { idx / 5, idx % 5 };
            idx++;
        }
    }

    for (int i = 0; i < msg.size(); i += 2) {
        if (i == msg.size() - 1 && msg.size() % 2) {
            msg += "X";
            break;
        }
        else if (msg[i] == msg[i + 1]) {
            if (msg[i + 1] == 'X')
                msg.insert(i + 1, "Q");
            else
                msg.insert(i + 1, "X");
        }
    }

    for (int i = 0; i < msg.size(); i += 2) {
        int ax = xy[msg[i] - 'A'].first, ay = xy[msg[i] - 'A'].second;
        int bx = xy[msg[i + 1] - 'A'].first, by = xy[msg[i + 1] - 'A'].second;

        if (ax == bx) {
            msg[i] = encode[ax][(ay + 1) % 5];
            msg[i + 1] = encode[bx][(by + 1) % 5];
        }
        else if (ay == by) {
            msg[i] = encode[(ax + 1) % 5][ay];
            msg[i + 1] = encode[(bx + 1) % 5][by];
        }
        else {
            msg[i] = encode[ax][by];
            msg[i + 1] = encode[bx][ay];
        }
    }

    cout << msg << endl;
}
