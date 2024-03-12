#include<iostream>
using namespace std;
int ydir[]={-1,1,0,0};
int xdir[]={0,0,-1,1};
int n, m, cnt;
int map[5][5];
int points[20][2];

void dfs(int y, int x, int now){
    if(y==points[now][0]&&x==points[now][1]){
        if(now<m) dfs(y,x,now+1);
        else{
            cnt++;
            return;
        }
    }
    for(int i=0;i<4;i++){
        int ny = y + ydir[i];
        int nx = x + xdir[i];
        if(ny<=0||ny>n||nx<=0||nx>n)continue;
        if(map[ny][nx]!=0)continue;
        map[ny][nx]=1;
        dfs(ny,nx,now);
        map[ny][nx]=0;
    }
}

int main(int argc, char** argv)
{
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>map[i][j];
        }
    }
    for(int i=1;i<=m;i++){
        int a,b;
        cin>>a>>b;
        points[i][0]=a;
        points[i][1]=b;
    }
    map[points[1][0]][points[1][1]]=1;
    dfs(points[1][0], points[1][1], 2);
    cout<<cnt;
   return 0;
}
