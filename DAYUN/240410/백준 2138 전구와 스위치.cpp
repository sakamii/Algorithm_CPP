#include <iostream>

using namespace std;

//ll last lignt nl next light
char ll[100000], nl[100000];

int check(int i);

int main(){
    int n;
    int i;
    cin >> n;
    // for(i = 0; i < n; i++) {
    cin >> ll;
    // }
    // for(i = 0; i < n; i++) {
    cin >> nl;
    // }

    i = 0;
    int count = 0;
    if((ll[0] != nl[0]) && (ll[1] != nl[1]) && (ll[2] == nl[2])) {
        i = 2;
        count++; 
    }

    //마지막 두개 지정
    while(i < (n - 2)) {
        int diff = 0;
        for(int j = 0; j < 3; j++) {
            diff <<= 1;
            diff += (ll[i + j] != nl[i + j]);
            cout << (ll[i + j] != nl[i + j]) << ",";
        }
        cout << diff << " ";

        //ll, nl범위 지정
        switch(diff){
            case 0 : 
                i += 3;
                break;
            case 1 :
                ll[i + 4] = (ll[i + 4] == '0') ? '1' : '0';
                ll[i + 5] = (ll[i + 5] == '0') ? '0' : '1';
                i += 3;
                count++;
                break;
            case 2 :
                ll[i + 5] = (ll[i + 5] == '0') ? '0' : '1';
                i += 3;
                count += 2;
                break;
            case 3 :
                ll[i + 4] = (ll[i + 4] == '0') ? '1' : '0';
                i += 3;
                count += 1;
                break;
            case 4 : 
                ll[i + 4] = (ll[i + 4] == '0') ? '1' : '0';
                i += 3;
                count += 2;
                break;
            case 5 :
                ll[i + 5] = (ll[i + 5] == '0') ? '0' : '1';
                i += 3;
                count += 3;
                break; 
            case 6 :
                ll[i + 4] = (ll[i + 4] == '0') ? '1' : '0';
                ll[i + 5] = (ll[i + 5] == '0') ? '0' : '1';
                i += 3;
                count += 2;
                break;
            case 7 :
                i += 3;
                count += 1;
                break;
            default : 
                cout << "ERROR\n";
        }
    }

    if((n - i) == 2) {
        if((ll[n - 2] != nl[n - 2]) && (ll[n - 1] != nl[n - 1])) {
            count++;
        }
        else if(ll[n - 2] == nl[n - 2] ^ ll[n - 1] == nl[n - 1]){
            count = -1;
        }
    }
    else if((n - 1) == 1) {
        if(ll[n - 1] != nl[n - 1]) {
            count = -1;
        }
    }

    cout << i << endl;
    cout << count << endl;

}
