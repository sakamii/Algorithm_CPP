#include<iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;
int n,q,a;
unordered_map<int,int>um;
vector<int>oil;
int main(int argc, char** argv)
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n>>q;
    oil.push_back(0);
    for(int i=0;i<n;i++){
        cin>>a;
        oil.push_back(a);
    }
    sort(oil.begin(),oil.end());
    for(int i=1;i<=n;i++){
        um[oil[i]]=i;
    }
    for(int i=0;i<q;i++){
        cin>>a;
        if(um.count(a)==0) cout<<0<<'\n';
        else cout<<(n-um[a])*(um[a]-1)<<"\n";
    }
}
