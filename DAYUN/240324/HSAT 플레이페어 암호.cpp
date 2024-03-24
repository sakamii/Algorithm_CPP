#include<iostream>
#include<string>
using namespace std;

char map[5][5];
bool alpabet[26] = { false };
pair<int, int> alpha_loc[26];
char msg[1001];
char result[2000];
int resultI = 0;

void change(char f, char s);


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    alpabet['J' - 'A'] = true;
    string key;
    cin >> msg;
    cin >> key;
    int j = 0;
    for (int i = 0; i < key.length(); i++) {
        if (alpabet[key[i] - 'A']) {
            continue;
        }
        else {
            alpha_loc[key[i] - 'A'] = { j / 5, j % 5 };
            map[j / 5][j % 5] = key[i];
            j++;
            alpabet[key[i] - 'A'] = true;
        }
    }
    for (int i = 0; i < 26; i++) {
        if (!alpabet[i]) {
            map[j / 5][j % 5] = (char)(i + 'A');
            alpha_loc[i] = { j / 5, j % 5 };
            j++;
        }
    }
    alpha_loc['J' - 'A'] = alpha_loc['I' - 'A'];
    int msg_len = 0;
    while (msg[msg_len] != '\0') {
        msg_len++;
    }
    // msg[msg_len + 1] = '\0';
    int msgI = 1;
    while (msg[msgI] != '\0') {
        if (msg[msgI] != msg[msgI - 1]) {
            change(msg[msgI - 1], msg[msgI]);
            msgI += 2;
        }
        else {
            if (msg[msgI] == 'X') {
                change(msg[msgI - 1], 'Q');
                msgI++;
            }
            else {
                change(msg[msgI - 1], 'X');
                msgI++;
            }
        }
    }
    // cout << msgI;
    if (msgI == msg_len) {
        change(msg[msg_len - 1], 'X');
    }

    cout << result;


}

void change(char f, char s) {
    if (alpha_loc[f - 'A'].first == alpha_loc[s - 'A'].first) {
        result[resultI++] = map[alpha_loc[f - 'A'].first][(alpha_loc[f - 'A'].second + 1) % 5];
        result[resultI++] = map[alpha_loc[s - 'A'].first][(alpha_loc[s - 'A'].second + 1) % 5];
    }
    else if (alpha_loc[f - 'A'].second == alpha_loc[s - 'A'].second) {
        result[resultI++] = map[(alpha_loc[f - 'A'].first + 1) % 5][alpha_loc[f - 'A'].second];
        result[resultI++] = map[(alpha_loc[s - 'A'].first + 1) % 5][alpha_loc[s - 'A'].second];
    }
    else {
        result[resultI++] = map[alpha_loc[f - 'A'].first][alpha_loc[s - 'A'].second];
        result[resultI++] = map[alpha_loc[s - 'A'].first][alpha_loc[f - 'A'].second];
    }
}
