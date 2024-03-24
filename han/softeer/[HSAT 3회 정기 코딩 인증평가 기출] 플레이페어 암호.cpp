#include <iostream>
#include <string>
#include <vector>
#include <tuple>

using namespace std;

const int MAX_N = 5;

string plain, key, answer = "";
vector<pair<char, char>> plainSet;

int idx;
char cipher[MAX_N][MAX_N];
bool DAT[26] = {false};

pair<pair<int, int>, pair<int, int>> getCharSetPos(char left, char right) {
    pair<int, int> leftIdx, rightIdx;
    for(int i = 0; i < MAX_N; i++) {
        for(int j = 0; j < MAX_N; j++) {
            if(cipher[i][j] == left) leftIdx = {i, j};
            if(cipher[i][j] == right) rightIdx = {i, j};
        }
    }
    return {leftIdx, rightIdx};
}

void setCipherPlain(pair<int, int> left, pair<int, int> right) {
    int leftY, leftX, rightY, rightX;
    tie(leftY, leftX) = left;
    tie(rightY, rightX) = right;
    if(leftY == rightY) {
        if(++leftX == MAX_N) leftX = 0;
        if(++rightX == MAX_N) rightX = 0;
    } else if(leftX == rightX) {
        if(++leftY == MAX_N) leftY = 0;
        if(++rightY == MAX_N) rightY = 0;
    } else {
        swap(leftX, rightX);
    }
    answer += cipher[leftY][leftX];
    answer += cipher[rightY][rightX];
}

void convertPlainSet() {
    idx = 0;
    while(idx < plainSet.size()) {
        char left, right;
        tie(left, right) = plainSet[idx++];

        auto target = getCharSetPos(left, right);
        pair<int, int> leftIdx = target.first;
        pair<int, int> rightIdx = target.second;
        
        setCipherPlain(leftIdx, rightIdx);
    }
}

void setPlainSet() {
    idx = 0;

    while(idx < plain.length()) {
        char left = plain[idx++];
        char right = plain[idx];

        if(right == '\0') {
            plainSet.push_back({left, 'X'});
            break;
        }

        if(left != right) {
            plainSet.push_back({left, right});
            idx++;
        } else {
            char temp = 'X';
            if(left == 'X') temp = 'Q';
            plainSet.push_back({left, temp});
        }
    }
}

int main(int argc, char** argv) {
    cin >> plain >> key;
    for(int i = 0; i < key.length(); i++) {
        if(DAT[key[i] - 'A']) continue;
        DAT[key[i] - 'A'] = true;
        *(&cipher[0][0] + idx) = key[i];
        idx++;
    }
     for(int i = 0; i < 26; i++) {
        if((char)('A' + i) == 'J') continue;
        if(DAT[i]) continue;
        *(&cipher[0][0] + idx) = (char)('A' + i);
        idx++;
    }

    setPlainSet();
    convertPlainSet();
    cout << answer;
    return 0;
}