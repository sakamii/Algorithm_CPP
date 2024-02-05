#include <string>
#include <vector>
using namespace std;

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
vector<vector<int>>accumul(board.size()+1,vector<int>(board[0].size()+1,0));

    for(int i=0;i<skill.size();i++){
        int startx=skill[i][1];
        int starty=skill[i][2];
        int endx=skill[i][3];
        int endy=skill[i][4];
        int power=skill[i][5];
        if(startx>endx){
            int temp=endx;
            endx=startx;
            startx=temp;
        }
        if(starty>endy){
            int temp=endy;
            endy=starty;
            starty=temp;
        }
        if(skill[i][0]==2){
            accumul[startx][starty]+=power;
            accumul[endx+1][starty]-=power;
            accumul[startx][endy+1]-=power;
            accumul[endx+1][endy+1]+=power;
        }
        if(skill[i][0]==1){
            accumul[startx][starty]-=power;
            accumul[endx+1][starty]+=power;
            accumul[startx][endy+1]+=power;
            accumul[endx+1][endy+1]-=power;
        }
    }
    
    //가로 더하기
    for(int j=0;j<=board.size();j++){
        for(int i=1;i<=board[0].size();i++){
            accumul[j][i]=accumul[j][i-1]+accumul[j][i];
        }
    }
    
    //세로더하기
    for(int j=1;j<=board.size();j++){
        for(int i=0;i<=board[0].size();i++){
            accumul[j][i]=accumul[j-1][i]+accumul[j][i];
        }
    }
    
    int answer = 0;
    for(int i=0;i<board.size();i++){
        for(int j=0;j<board[0].size();j++){
            if(accumul[i][j]+board[i][j]>0) answer++;
        }
    }
    
    return answer;

}
