/*
    빡구현
*/


#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<int> map[10][10];
int a_route[100];
int b_route[100];
int bc[8];


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

        int m, a;
        cin >> m >> a;
        for(int i = 0; i < m; i++) {
            cin >> a_route[i];
        }
        for(int i = 0; i < m; i++) {
            cin >> b_route[i];
        }
        cout << " ?";

        for(int ap = 0; ap < a; ap++) {
            int y, x, r, p;
            cin >> x >> y >> r >> p;
            for(int )

        }

        for(int i = 0; i < 10; i++) {
            for(int j = 0; j < 10; j++) {
                for(int m : map[i][j])
                    cout << m;
                
                cout << " ";
            }
            cout << endl;
        }


        cout << "#" << test_case << " " << result <<endl;
	}
	return 0;
}