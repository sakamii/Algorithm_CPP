#include<iostream>
#include <vector>
using namespace std;
int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};
char kk[4]={'^','>','v','<'};
//북, 동, 남, 서
string arr[26];
bool checkDone;
int stx, sty, H, W, startDir;

void cal(int a, int b, int nowdir){
    int nowx=a, nowy=b;
    for(int i=0;i<4;i++){
        if(i==2) continue; 
        int nx=nowx+dx[(nowdir+i)%4];
        int ny=nowy+dy[(nowdir+i)%4];
        if(nx<0||ny<0||nx>=H||ny>=W){
            continue;
        }
        if(arr[nx][ny]=='#'){
            if(i==0){
                cout<<"A";
                cal(nx+dx[(nowdir+i)%4],ny+dy[(nowdir+i)%4],nowdir);
            }
            else if(i==1){
                cout<<"RA";
                cal(nx+dx[(nowdir+i)%4],ny+dy[(nowdir+i)%4],(nowdir+1)%4);
            }
            else if(i==3){
                cout<<"LA";
                cal(nx+dx[(nowdir+i)%4],ny+dy[(nowdir+i)%4],(nowdir+3)%4);
            }
            return;
        }
    }
    return;
}

void check1(int a, int b){
    int tempOne=0;
    for(int i=0;i<4;i++){
        int nx=a+dx[i];
        int ny=b+dy[i];
        if(nx<0||ny<0||nx>=H||ny>=W){
            continue;
        }
        if(arr[nx][ny]=='#') tempOne++;
    }
    if(tempOne==1){
        stx=a;
        sty=b;
        checkDone=true;
        cout<<stx+1<<' '<<sty+1<<'\n';
        for(int i=0;i<4;i++){
            int nx=a+dx[i];
            int ny=b+dy[i];
            if(nx<0||ny<0||nx>=H||ny>=W){
                continue;
            }
            if(arr[nx][ny]=='#'){
                cout<<kk[i]<<'\n';
                startDir=i;
                return;
            }
        }
    }
}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin>>H>>W;
    for(int i=0;i<H;i++){
        cin>>arr[i];
    }
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            if(arr[i][j]=='#') check1(i,j);
            if(checkDone) break;
        }
        if(checkDone) break;
    }

    cal(stx,sty,startDir);
    return 0;
}
