#include <iostream>
#include <map>
using namespace std;
 
int main(){
    
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    map<string, string, greater<>> m;
    int n; cin >> n;
    for(int i = 0; i<n; i++){
        string st1, st2;
        
        cin >> st1 >> st2;
        m[st1] = st2;
        
    }
    for(auto it = m.begin(); it!=m.end(); it++){
        if(it->second == "enter"){
            cout << it->first << "\n";
        }
    }
        
    return 0;
}
