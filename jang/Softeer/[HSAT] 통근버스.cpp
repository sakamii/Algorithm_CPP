#include <iostream>
#include <vector>

using namespace std;
int bigger[5001];
int smaller[5001];
int bus[5001];
int N, answer;


int main(int argc, char** argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    cin>>N;
    for(int i=1;i<=N;i++){
        cin>>bus[i];
    }
    for(int i=1;i<=N;i++){
        int big=0, small=0;
        for(int j=i+1;j<=N;j++){
            if(bus[i]>bus[j]) small++;
            else big++;
        }
        bigger[i]=big;
        smaller[i]=small;
    }
    for(int i=1;i<=N;i++){
        for(int j=i+1;j<=N;j++){
            if(bus[i]<bus[j]){
                //cout<<i<<' '<<j<<'\n';
                answer+=smaller[j];
                break;
            }
        }
    }
    // for(int i=1;i<=N;i++){
    //     cout<<smaller[i]<<' ';
    // }
    // cout<<'\n';
    // for(int i=1;i<=N;i++){
    //     cout<<bigger[i]<<' ';
    // }
    
    cout<<answer;
    
}
