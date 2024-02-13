#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
/*

DFS를 이용해 모든 사람들이 갈수있는 계단의 경우의수 전부 계산
-> 처음에 visited를 이용하고 풀어주는 식으로 했으나
-> idx를 이용하면 그럴 필요가 없고 , 시간도 줄어들음. => 이번 월말평가에서 시간초과 났던 요인

priority_queue를 이용해 먼저 도착한 사람들부터 queue에 집어넣고
queue의 front가 계단을 완전히 내려가는 시간이
다음 사람이 대기하는 시간보다 크면 그 시간을 갱신시켜줌
만일 아니라면 그대로 다시 삽입

**** 그리고 마지막에 계단을 내려가는 시간을 꼭 더해주어야함

의문) 진작에 계단을 다 내려가는 시간으로 priority_queue에 넣고 계산하면 결과가 안나옴

*/
int t;
int n;
int map[11][11];
int visited[11];
int answer = 123456789;
vector<pair<int,int>> people;
vector<pair<int,pair<int,int>>> stair;

void dfs(int size){
	if(size == people.size()){
		int stair1_time = stair[0].first;
		int stair2_time = stair[1].first;
		priority_queue<int> q1,q2;
		for(int i=0; i<people.size(); i++){
			if(visited[i] == 1){
				q1.push(-(abs(people[i].first-stair[0].second.first)+abs(people[i].second - stair[0].second.second)));
			}
			else if(visited[i] == 2){
				q2.push(-(abs(people[i].first-stair[1].second.first)+abs(people[i].second - stair[1].second.second)));
			}
		}
		int q1_time = 0, q2_time = 0;
		queue<int> q11, q22;
		while(!q1.empty()){
			int current = -q1.top();
			q1.pop();
			if(q11.size() < 3){
				q11.push(current);
			}
			else{
				int temp = q11.front();
				q11.pop();
				if(temp+stair1_time+1 <= current){
					q11.push(current);
				}
				else{
					q11.push(temp+stair1_time);
				}
			}
		}
		while(!q11.empty()){
			q1_time = q11.front();
			q11.pop();
		}
		q1_time += stair1_time + 1;
		while(!q2.empty()){
			int current = -q2.top();
			q2.pop();
			if(q22.size() < 3){
				q22.push(current);
			}
			else{
				int temp = q22.front();
				q22.pop();
				if(temp+stair2_time+1 <= current){
					q22.push(current);
				}
				else{
					q22.push(temp+stair2_time);
				}
			}
		}
		while(!q22.empty()){
			q2_time = q22.front();
			q22.pop();
		}
		q2_time += stair2_time+1;
		int check = max(q1_time,q2_time);
		answer = min(answer,check);
		return;
	}

	visited[size] = 1;
	dfs(size+1);
	visited[size] = 2;
	dfs(size+1);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> t;
	for(int test_case = 1; test_case<=t; test_case++){
		cin >> n;
		answer = 123456788;
		people.clear();
		stair.clear();
		for(int i=0; i<11; i++){
			visited[i] = 0;
		}
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				cin >> map[i][j];
				if(map[i][j] == 1){
					people.push_back({i,j});
				}
				else if(map[i][j] > 1){
					stair.push_back({map[i][j],{i,j}});
				}
			}
		}
		dfs(0);

		cout<<"#"<<test_case << " " << answer << endl;
	}
}