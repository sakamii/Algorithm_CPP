//프로그래머스 문제 파괴되지 않은 건물
#include<vector>
#include <string>
#include<iostream>

#define N 5
#define skill_num 4

using namespace std;

int solution(vector<vector<int>> board, vector<vector<int>> skill);

int main() {

    vector<vector<int>> board(N);
    vector<vector<int>> skill(skill_num);
    for(int i = 0; i < N; i++) {
        board.resize(N);
    }
    board = {{5,5,5,5,5},{5,5,5,5,5},{5,5,5,5,5},{5,5,5,5,5}};
    for(int i = 0; i < skill_num; i++) {
        skill.resize(6);
    }
    skill = {{1,0,0,3,4,4},{1,2,0,2,3,2},{2,1,0,3,1,2},{1,0,1,3,3,1}};
    cout << solution(board, skill);
}

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int answer = 0;
    vector<vector<int>> prefix_sum;
    int n = board.size();
    int m = board[0].size();
    prefix_sum.resize(n + 2);
    
    for(int i = 0; i <= n + 1; i++) {
        prefix_sum[i].resize(m + 2);
    }
    
    prefix_sum[1][1] = board[0][0];
    for(int i = 1; i <= m; i++) {
        prefix_sum[1][i] = board[0][i] - board[0][i - 1];
        prefix_sum[0][i] = 0;
    }
    for(int i = 1; i < n; i++) {
        prefix_sum[i][1] = board[i][0] - board[i - 1][0];
        prefix_sum[i][0] = 0;
    }
    for(int i = 1; i < n; i++) {
        for(int j = 1; j < m; j++) {
            prefix_sum[i + 1][j + 1] = board[i][j] - board[i - 1][j] - board[i][j - 1] + board[i - 1][j - 1];
        }
    }

    // //skill 
    for(int i = 0; i < skill.size(); i++) {
        int type = skill[i][0];
        int r1 = skill[i][1] + 1;
        int c1 = skill[i][2] + 1;
        int r2 = skill[i][3] + 1;
        int c2 = skill[i][4] + 1;
        int degree = skill[i][5];

        if(type == 1) degree *= -1;
        prefix_sum[r1][c1] += degree;
        prefix_sum[r2][c2 + 1] -= degree;
        prefix_sum[r2 + 1][c2] -= degree;
        prefix_sum[r2 + 1][c2 + 1] +=degree;
    }
    
    for(int i = 1; i < n; i++) {
        for(int j = 1; j < m; j++) {
            cout << (prefix_sum[i][j] - prefix_sum[i - 1][j] - prefix_sum[i][j - 1] + prefix_sum[i - 1][j - 1]) << " ";
        }
        cout << "\n";
    }
    

    for(int i = 1; i < n; i++) {
        for(int j = 1; j < m; j++) {
            if((prefix_sum[i][j] - prefix_sum[i - 1][j] - prefix_sum[i][j - 1] + prefix_sum[i - 1][j - 1]) > 0)
                answer++;
        }
    }


    return answer;
}