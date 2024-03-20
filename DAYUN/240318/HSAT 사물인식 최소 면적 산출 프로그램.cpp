#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
//21!!!!!
vector<pair<int, int>> colors_map[21];
int result = 1000000000;
int n, k;

void dfs(int level, int minx, int maxx, int miny, int maxy);

int main(int argc, char** argv)
{
    cin >>  n >> k;
    
    for(int i = 0; i < n; i++) {
        int x, y, c;
        cin >> x >> y >> c;
        colors_map[c].push_back({x, y}); 
    }

    for(pair<int, int> i : colors_map[1]) {
        dfs(2, i.first, i.first, i.second, i.second);
    }

    cout << result;
   return 0;
}


void dfs(int color, int minx, int maxx, int miny, int maxy){
    if(color == (k + 1)) {
        result = (maxx - minx) * (maxy - miny);
        //return 잊지 않기!!
        return;
    }

    for(pair<int, int> i : colors_map[color]) {
        int minxi = min(minx, i.first);
        int maxxi = max(maxx, i.first);
        int minyi = min(miny, i.second);
        int maxyi = max(maxy, i.second);

        if(result > ((maxxi - minxi) * (maxyi - minyi))) {
            dfs(color + 1, minxi, maxxi, minyi, maxyi);
        }
    }
}
