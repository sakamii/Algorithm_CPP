#include<iostream>
#include<cstring>
#include<queue>

using namespace std;

struct cell{
	int time;
	int energy;
	int y;
	int x;
	
	//번식타임 기준 sort
	bool operator < (const cell &temp) const {
		if((time + energy) > (temp.time + temp.energy)) return true;
		if((time + energy) == (temp.time + temp.energy) && energy <= temp.energy) return true;
		return false;
	}
};

//[0]~[49] + k (왼쪽 -300 ) => -300 ~ -251 -> [300] ~[349]
//[300] ~[349] + K(오른쪽 +300 ) => 600~649 -> [650] 
//301~350 + 300 -> 651
const int BLANK = 300;
int map[650][650];
int visited[650][650];
int ydir[4] = {-1, 1, 0, 0};
int xdir[4] = {0, 0, -1, 1};

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        int result = 0;

		int n, m, k;
		cin >> n >> m >> k;
		memset(map, -1, sizeof(map));
		memset(visited, -1, sizeof(visited));
		priority_queue<cell> q;

		for(int i = BLANK; i < BLANK + n; i++) {
			for(int j = BLANK; j < BLANK + m; j++) {
				int energy;
				cin >> energy;
				if(energy > 0)
				{
					q.push({0, energy, i, j});
					if(k < (energy * 2)) result++;
					visited[i][j] = 0;
				}
			}
		}
		
		while(!q.empty()){
			int y = q.top().y;
			int x = q.top().x;
			int energy = q.top().energy;
			int time = q.top().time;
			bool flag = false;
			q.pop();

			//번식 타임
			time = time + energy;
			if(time >= k) {
				break;
			}
			
			//다음 번식에 의해 태어나는 cell이 k시간에 살아있는지
			if((time + (energy * 2)) >= k) {
				flag = true;
			}

			for(int dir = 0; dir < 4; dir++) {
				int next_y = y + ydir[dir];
				int next_x = x + xdir[dir];

				if(visited[next_y][next_x] == -1) {
					visited[next_y][next_x] = 0;
					if(flag){ 
						result++;
					}
					q.push({time + 1, energy, next_y, next_x});
				}
			}
		}
        cout << "#" << test_case << " " << result <<endl;
	}
	return 0;
}