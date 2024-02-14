
#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

int room[10][10];

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        int result = 2000000000;

        int N;
        int stair[2][3] = {0};
        int person[10][2];
        int num_person = 0;
        cin >> N;
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                cin >> room[i][j];
                if(room[i][j] > 0) {
                    if(room[i][j] > 1) {
                       if(stair[0][2] > 0) {
                            stair[1][0] = i; 
                            stair[1][1] = j; 
                            stair[1][2] = room[i][j];
                        }
                        else {
                            stair[0][0] = i; 
                            stair[0][1] = j; 
                            stair[0][2] = room[i][j];
                        }
                    }
                    else {
                        person[num_person][0] = i;
                        person[num_person][1] = j;
                        num_person++;
                    }
                }
            }
        }


        int NPmul2 = 1;
        for(int i = 0; i < num_person; i++) {
            NPmul2 *= 2;
        }

        for(int i = 0; i < NPmul2; i++) {
            int npmul2 = i;
            priority_queue<int> stair_time[2];

            for(int j = 0; j < num_person; j++) {
                int st = (npmul2 >> j) % 2;
                int time = abs(person[j][0] - stair[st][0]) + abs(person[j][1] - stair[st][1]);
                stair_time[st].push(-time);
            }

            int tt[2] = {0};
            for(int j = 0; j < 2; j++) {
                int t[3];
                int k = 0;
                //3명 채우기
                while(!stair_time[j].empty()) {
                    t[k] = -stair_time[j].top();
                    stair_time[j].pop();
                    tt[j] = t[k];
                    k++;
                    if(k == 3) {
                        break;
                    }
                }  
                
                while(!stair_time[j].empty()) {
                    tt[j] = max(t[k%3] + stair[j][2], tt[j]);
                    t[k % 3] = max(-stair_time[j].top(), tt[j]);
                    stair_time[j].pop();
                    tt[j] = t[k % 3];
                    k++;
                }
                tt[j] += stair[j][2];
            }
            
            result = min(result, max(tt[0], tt[1]) + 1);
            
        }
        cout << "#" << test_case << " " << result <<endl;
	}
	return 0;
}