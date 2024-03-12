#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n,m,stx,sty,edx,edy,nowToGo,answer;
int arr[5][5];
bool visited[5][5];
vector<pair<int,int>>A;

int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};

void cal(int a, int b){
    int nowx=a;
    int nowy=b;
    for(int i=0;i<4;i++){
        int nx=nowx+dx[i];
        int ny=nowy+dy[i];
        if(nx<1||ny<1||nx>n||ny>n||visited[nx][ny]||arr[nx][ny]==1) continue;
        if(nx==edx&&ny==edy){
            nowToGo++;
            if(nowToGo==m){
                //cout<<nx<<' '<<ny<<'\n';
                answer++;
                nowToGo--;
                continue;
            }
            visited[nx][ny]=true;
            int tempedx=edx;
            int tempedy=edy;
            edx=A[nowToGo].first;
            edy=A[nowToGo].second;
            cal(nx,ny);
            edx=tempedx;
            edy=tempedy;
            nowToGo--;
            visited[nx][ny]=false;
            continue;
        }
        if(arr[nx][ny]==-1) continue;
        visited[nx][ny]=true;
        cal(nx,ny);
        visited[nx][ny]=false;
    }
}

int main(int argc, char** argv)
{
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>arr[i][j];
        }
    }
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        A.push_back({a,b});
        arr[a][b]=-1;
    }
    stx=A[0].first;
    sty=A[0].second;
    nowToGo=1;
    edx=A[nowToGo].first;
    edy=A[nowToGo].second;
    visited[stx][sty]=true;
    cal(stx, sty);
    cout<<answer;
}
