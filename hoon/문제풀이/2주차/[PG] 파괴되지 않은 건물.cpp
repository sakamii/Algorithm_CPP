#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/*

2차원 누적합을 이용해 풀이.
기존 map에 r과 c를 +1씩 더해서 생각해야함.
누적으로 더할 양을 미리 각 꼭짓점에 저장해둠. 단, 1사분면과 3사분면의 꼭짓점은 더하는 값에 음수 부호를 취해야함
-> 행과 열의 합을 더할때 이부분때문에 임시로 늘려둔 배열의 값이 기존의 값으로 돌아갈 수 있음

각 꼭짓점에 좌표를 저장했으면, 열과 행 순서로 더해줌.
그렇게 생성된 배열을 기존의 배열과 합치면 누적합이 완료된 배열 완성됨.

*/
int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int answer = 0;
    int map[1010][1010];
    int n = board.size();
    int m = board[0].size();
    for(int i=0; i<1010; i++){
        for(int j=0; j<1010; j++){ 
            map[i][j] = 0;
        }
    }
    
    for(int i=0; i<skill.size(); i++){
        int type = skill[i][0];
        int r1 = skill[i][1], r2=skill[i][3];
        int c1 = skill[i][2], c2 = skill[i][4];
        int degree = skill[i][5];
        
        if(type==1) degree *= -1;
        
        map[r1][c1] += degree;
        map[r1][c2+1] -= degree;
        map[r2+1][c1] -= degree;
        map[r2+1][c2+1] += degree;
    }
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            map[i][j+1] += map[i][j];
        }
    }
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            map[i+1][j] += map[i][j];
        }
    }
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(map[i][j] + board[i][j] > 0) answer ++;
        }
    }
    
    
    return answer;
}