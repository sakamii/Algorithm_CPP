#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, T;
int A[101][101][4];
int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};
int traffic[13][4]={{0,0,0,0},{1,0,1,2},{0,3,0,1},{3,2,3,0},{2,1,2,3},
{1,0,1,5},{0,0,3,5},{3,2,3,5},{2,1,2,5},
{1,1,2,5},{0,0,1,5},{3,0,3,5},{2,2,3,5}
};
bool visited[101][101];

void cal(int a, int b, int nowdir, int nowTime){
    visited[a][b]=true;
    if(nowTime==T){
        //cout<<nowdir<<' '<<a<<' '<<b<<'\n';
        return;
    }
    if(traffic[A[a][b][nowTime%4]][0]!=nowdir){
        return;
    }
    int nowx=a;
    int nowy=b;
    for(int i=1;i<=3;i++){
        int toDir=traffic[A[a][b][nowTime%4]][i];
        if(toDir==5) continue;
        int nx=nowx+dx[toDir];
        int ny=nowy+dy[toDir];
        if(nx<0||ny<0||nx>=N||ny>=N) continue;
        cal(nx,ny,toDir,nowTime+1);
    }
}

int main(int argc, char** argv)
{
    cin>>N>>T;
    //A.resize(N,vector<vector<int>>(N,vector<int>(4)));
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            for(int k=0;k<4;k++){
                cin>>A[i][j][k];
            }
        }
    }
    cal(0,0,0,0);
    int answer=0;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(visited[i][j]){
                //cout<<i<<' '<<j<<'\n';
                answer++;
            }
        }
    }
    cout<<answer;
}
