#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <string.h>

using namespace std;
unordered_set<string> out;
unordered_map<string, int> in;
string input[1000];

int main(){
    int n;
    cin >> n;
    int result = 0;
    //input
    for(int i = 0; i < n; i++) {
        cin >> input[i];
        in[input[i]] = i;
    }

    //output
    for(int i = 0; i < n; i++) {
        char ch[9];
        cin >> ch;
        out.insert(ch);
        for(int j = 0; j < in[ch]; j++) {
            if(out.count(input[j]) == 0) {
                result++; 
                break; 
            }
        }
    }

    cout << result;    
}