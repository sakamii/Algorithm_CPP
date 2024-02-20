#include <iostream>
#include <queue>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;
int t;
int n, m, k, a, b;
struct lst
{
    int idx;
    int t1, t2;
};



/*

(실패) 47/50 Fail

문제 조건에서 시간 순서대로 들어오니 pq 대신 그냥 queue를 사용하고자 함.

queue에서 들어오는 시간대별로 갱신을 해주면서, idx가 -1이면 창구가 비어있다는 뜻이므로
이전에 저장되있던 idx를 다음 정비창구의 대기큐로 보내주면서 동시에 time을 늘려주면서 해결하고자함

어디가 문제인지 모르겠음.
*/
lst reception[21];
lst repair[21];
int result[1001][2];
int flag[1001];
int main()
{
    cin >> t;
    for (int test_case = 1; test_case <= t; test_case++)
    {
        cin >> n >> m >> k >> a >> b;
        queue<pair<int, int>> people_queue;
		queue<int> repair_queue;
        for (int i = 1; i <= n; i++)
        {
            int temp;
            cin >> temp;
            reception[i] = {-1, temp, 0};
        }

        for (int i = 1; i <= m; i++)
        {
            int temp;
            cin >> temp;
            repair[i] = {-1, temp, 0};
        }

        for (int i = 1; i <= k; i++)
        {
            int temp;
            cin >> temp;
            people_queue.push({temp, i});
			flag[i] = 0;
			result[i][0] = 0;
			result[i][1] = 0;
        }
		int time = 0;
		int cnt = 0;
		while(true){
			if(cnt == k) break;	
			for(int i=1; i<=n; i++){
				if(people_queue.empty())break;
				//창구 비어있을때
				if(reception[i].idx == -1){
					if(people_queue.front().first <= time){
						reception[i].idx = people_queue.front().second;
						reception[i].t2 = time;
						result[reception[i].idx][0] = i;
						people_queue.pop();
						continue;
					}
				}
				else{
					if(reception[i].t1 + reception[i].t2 <= time){
						if(people_queue.front().first <= time){
							repair_queue.push(reception[i].idx);
							flag[reception[i].idx] = 1;

							reception[i].idx = people_queue.front().second;
							result[reception[i].idx][0] = i;
							reception[i].t2 = time;
							people_queue.pop();
						}
						else{
							repair_queue.push(reception[i].idx);
							flag[reception[i].idx] = 1;
							reception[i].idx = -1;
						}
					}
				}
			}
			if(people_queue.empty()){
				vector<pair<int,int>> v_temp;
				for(int i=1; i<=n; i++){
					if(reception[i].idx == -1) continue;
					if(flag[reception[i].idx] == 0){
						if(reception[i].t1 + reception[i].t2 <= time){
							v_temp.push_back({time, reception[i].idx});
							result[reception[i].idx][0] = i;
							flag[reception[i].idx] = 1;
						}
					}
				}
				sort(v_temp.begin(),v_temp.end());
				for(int i=0; i<v_temp.size(); i++){
					repair_queue.push(v_temp[i].second);
				}
			}
			for(int i=1; i<=m; i++){
				if(repair_queue.empty())break;
				if(repair[i].idx == -1){
					repair[i].idx = repair_queue.front();
					repair[i].t2 = time;
					cnt ++ ;
					result[repair[i].idx][1] = i;
					repair_queue.pop();
				}
				else{
					if(repair[i].t1 + repair[i].t2 <= time){
						repair[i].idx = repair_queue.front();
						result[repair[i].idx][1] = i;
						cnt ++;
						repair[i].t2 = time;
						repair_queue.pop();
					}
				}
			}
			time ++;
		}
		int answer = 0;
		for(int i=1; i<=k; i++){
			//cout << i << " " << result[i][0] << " " << result[i][1] << endl;
			if(result[i][0] == a && result[i][1] == b){
				answer += i;
			}
		}
		if(answer ==0 )  answer = -1;
        cout << "#" << test_case << " " << answer << endl;
    }

    return 0;
}
