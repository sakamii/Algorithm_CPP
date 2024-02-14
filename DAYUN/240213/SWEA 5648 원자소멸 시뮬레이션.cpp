#include<iostream>
#include<cstring>
#include<vector>
#include<queue>

using namespace std;

struct edge {
    int x, y, dir, k;
};

int ydir[4] = {1, -1, 0, 0};
int xdir[4] = {0, 0, -1, 1};
int map[4001][4001];
vector<edge> ve;
int N;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        int result = 0;
        memset(map,0,sizeof(map));
        cin >> N;
        ve.resize(N);
        for(int i = 0; i < N; i++) {
            int x, y, dir, k;
            cin >> x >> y >> dir >> k;
            ve[i] = {(x + 1000) * 2, (y + 1000) * 2, dir, k};
        }
       
       while(ve.size() > 0) {
           queue<pair<int, int>> q;
            cout << ve.size() << " ";
            for(vector<edge>::iterator it = ve.begin(); it != ve.end(); it++) {
                it->y += ydir[it->dir];
                it->x += xdir[it->dir];
                if((it->y < 0) || (it->y >= 4000) || (it->x < 0) || (it->x >= 4000)){
                    it = ve.erase(it);
                    it--;
                } 
                else map[it->y][it->x]++;
            }

            for(vector<edge>::iterator it = ve.begin(); it != ve.end(); it++) {
                if(map[it->y][it->x] > 1) {
                    q.push({it->y, it->x});
                    result += (it->k);
                    it = ve.erase(it);
                    it--;
                }
                else {
                    map[it->y][it->x] = 0;
                }
            }

            while(!q.empty()) {
                map[q.front().first][q.front().second] = 0;
                q.pop();
            }
       }


        cout << "#" << test_case << " " << result <<endl;
	}
	return 0;
}