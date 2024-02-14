//회문
#include<iostream>
#include<algorithm>

using namespace std;

int compare(int low, int high, string str);

int main() {
    int n;
    string str;
    int arr[30];
    cin >> n;
    
    for(int t = 0; t < n; t++) {
        cin >> str;
        int result = 0;
        
        int low = 0; 
        int high = str.length() - 1;
        while(low < high) {
            if(str[low] != str[high]) {
                result = compare(low + 1, high, str);
                result = min(result, compare(low, high - 1, str));
                break;
            }
            low++;
            high--;
        }

        arr[t] = result;
    }

    for(int i = 0; i < n; i++) {
        cout << arr[i] <<endl;
    }
}

int compare(int low, int high, string str){
    while(low < high) {
        if(str[low] != str[high]) {
            return 2;
        }
        low++;
        high--;
    }
    return 1;
}