/* 
    문제 이해 : 
    n-분기  - n1
    
*/


#include<iostream>
#include<stack>
#include<vector>

using namespace std;

int road[100][100][4];
int visited[100][100];
vector<pair<int, int>> signal[13] ={
    {},
    {{-1, 1}, {0, 1}, {1, 1}},
    {{-1, -1}, {-1, 0}, {-1, 1}},
    {{-1, -1}, {0, -1}, {1, -1}},
    {{1, -1}, {1, 0}, {1, 1}},
    {{-1, 1}, {0, 1}},
    {{-1, -1}, {-1, 0}},
    {{0, -1}, {1, -1}},
    {{1, 0}, {1, 1}},
    {{0, 1}, {1, 1}},
    {{-1, 0}, {-1, 1}},
    {{-1, -1}, {0, -1}},
    {{1, -1}, {1, 0}}
};

int main() {
    int n , t;
    cin >> n >> t;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < t; j++) {
            cin >> road[i][j][0] >> road[i][j][1] >> road[i][j][2] >> road[i][j][3];
        }
    }

    int idx = 0;
    stack<pair<int, int>> st;
    //처음 진입
    for(int i = 0; i < road[0][0][])




    while(!st.empty()) {
        int y = st.top().first;
        int x = st.top().second;


    }
}