
// https://school.programmers.co.kr/learn/courses/30/lessons/92344

#include <string>
#include <vector>
using namespace std;

int ans, type, sx, sy, ex, ey, deg, n, m;

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    
    n = board.size();
    m = board[0].size();

    vector<vector<int>> pre(n + 1, vector<int>(m + 1, 0));
    
    for (int i = 0; i < skill.size(); i++) {
        type = skill[i][0];
        sx = skill[i][1], sy = skill[i][2], ex = skill[i][3], ey = skill[i][4];
        deg = skill[i][5];
        
        if (type == 1) deg *= -1;
        
        pre[sx][sy] += deg;
        pre[ex + 1][sy] += -deg;
        
        pre[sx][ey + 1] += -deg;
        pre[ex + 1][ey + 1] += deg;
    }
    
    for (int i = 0; i < n; i++)
        for (int j = 1; j < m; j++)
            pre[i][j] += pre[i][j - 1];
    
    for (int i = 0; i < m; i++)
        for (int j = 1; j <= n; j++)
            pre[j][i] += pre[j - 1][i];
    
    for (int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if (board[i][j] + pre[i][j] > 0)
                ans++;

    return ans;
}
