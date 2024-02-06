#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    vector<vector<int>> skills(board.size() + 1, vector<int>(board[0].size() + 1, 0));
    int answer = 0;
    // 스킬에 맞춰 배열 생성 
    for (int i = 0; i < skill.size(); i++) {
        int r1 = skill[i][1], c1 = skill[i][2], r2 = skill[i][3], c2 = skill[i][4], degree = skill[i][5];
        if (skill[i][0] == 1) {
            skills[r1][c1] -= degree;
            skills[r1][c2 + 1] += degree;
            skills[r2 + 1][c1] += degree;
            skills[r2 + 1][c2 + 1] -= degree;
        }
        else {
            skills[r1][c1] += degree;
            skills[r1][c2 + 1] -= degree;
            skills[r2 + 1][c1] -= degree;
            skills[r2 + 1][c2 + 1] += degree;
        }
    }
    // 딜, 힐 배열 행 채우기
    for (int i = 0; i <= board.size(); i++) {
        for (int j = 0; j < board[0].size(); j++) {
            skills[i][j + 1] = skills[i][j] + skills[i][j + 1];
        }
    }
    // 열 채우기
    for (int i = 0; i < board[0].size(); i++) {
        for (int j = 0; j <= board.size(); j++) {
            skills[i + 1][j] = skills[i][j] + skills[i + 1][j];
        }
    }
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[0].size(); j++) {
            int damage = board[i][j] + skills[i][j];
            if (damage > 0) answer++;
        }
    }
    return answer;
}
