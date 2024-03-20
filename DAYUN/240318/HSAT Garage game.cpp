#include<iostream>
#include<queue>

using namespace std;

int map[30][15];
int n;
bool visited[3][15][15];
int newMap[3][15][15];

void dfs_1();
int score(int level, int i, int j);

int main(int argc, char** argv)
{
    cin >> n;
    int result;

    for(int i = 0;  i < (n * 2); i ++) {
        for(int j = 0; j < n; j++) {
            cin >> map[2][j];
        }
    }
    for(int i = 0;  i < n; i ++) {
        for(int j = 0; j < n; j++) {
            cin >> newMap[0][i][j];
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++){
            if(visited[0][i][j]) {
                result += score(0, i, j);
            }
        }
    }
   return 0;
}

int score(int level, int y, int x){
    int r = 0;
    int ydir[] = {-1, 1, 0, 0};
    int xdir[] = {0, 0, -1, 1};
    bool erase[15][15] = {false};

    int minx = n, maxx = 0, miny = n, maxy = 0;
    int color = newMap[level][y][x];
    

    queue<pair<int, int>> q;
    q.push({y, x});
    while(!q.empty()) {
        y = q.front().first;
        x = q.front().second;
        q.pop();
        r++;
        erase[y][x] = true;

        minx = min(x, minx);
        maxx = max(x + 1, maxx);
        miny = min(y, miny);
        maxy = max(y + 1, maxy);
        for(int i = 0; i < 4; i++) {
            int nexty = y + ydir[i];
            int nextx = x + xdir[i];
            
            if((nexty >= 0) && (nexty < n) && (nextx >= 0) && (nextx < n)) {
                if((newMap[level][y][x] == color) && (!erase[nexty][nextx])) {
                    q.push({nexty, nextx});
                }
            }
        }

    }

    if(level != 2) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                
            }
        }
    }

    r += (maxx - minx) * (maxy - maxx);
    return r;
}
