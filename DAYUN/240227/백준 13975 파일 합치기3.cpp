// 알고리즘 월말평가 유사 문제 (개인)

#include<iostream>
#include<queue>

using namespace std;

priority_queue<long long, vector<long long>, greater<long long>> pq;

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
        long long result = 0;
        
        int K;
        cin >> K;
        for(int i = 0; i < K; i++) {
            int data;
            cin >> data;
            pq.push(data);
        }

        while(pq.size() >= 2) {
            long long a = pq.top();
            pq.pop();
            long long b = pq.top();
            pq.pop();

            result += (a + b);
            pq.push(a + b);
        }

        pq.pop();

        cout << result <<endl;
	}
	return 0;
}