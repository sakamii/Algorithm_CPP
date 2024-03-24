#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
unsigned long long N, B;
vector<unsigned long long>temp;
unsigned long long answer;

using namespace std;

int main(int argc, char** argv)
{
    cin>>N>>B;
    temp.resize(N);
    for(int i=0;i<N;i++){
        cin>>temp[i];
    }
    sort(temp.begin(),temp.end());    
    
    unsigned long long start1=1;
    unsigned long long end1=1e18;
    while(start1<=end1){
        //cout<<start<<' '<<end;
        //if(end1<10){
        //    cout<<start1<<' '<<end1<<'\n';
        //}
        unsigned long long mid=(start1+end1)/2;
        unsigned long long tempAns=0;
        bool flag=false;
        for(int i=0;i<N;i++){
            if(mid<=temp[i]) break;
            else if(tempAns+pow((mid-temp[i]),2)>B){
                flag=true;
                break;
            }
            tempAns+=pow((mid-temp[i]),2);
            //if(mid==3) cout<<tempAns<<' '<<i<<' '<<temp[i]<<'\n';
        }
        if(!flag){
            answer=mid;
            start1=mid+1;
        }
        else{
            //cout<<mid<<'\n';
            end1=mid-1;
        }
    }
    cout<<answer;
    return 0;
}
