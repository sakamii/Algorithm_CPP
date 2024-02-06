#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int arr[334][334];
int sum[334][334];

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            scanf("%1d", &arr[i][j]);
            sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + arr[i][j];
        }

    int answer = 0;
    for (int i = 1; i <= m; i++){
        for (int j = i; j <= m; j++){
            int row=0,col = (j-i)+1;
            for(int y = 1; y<=n; y++){
                //y,i부터 y,j까지 부분합
                int temp = sum[y][j] - sum[y-1][j] - sum[y][i-1] + sum[y-1][i-1];
                //cout<< temp << endl;
                if(temp == 0){
                    row += 1;
                    answer = max(answer,row*col);
                }
                else{
                    answer = max(answer,row*col);
                    row = 0;
                }
            }
        }
        //cout<<"---"<<endl;
    }

    cout << answer << "\n";
    return 0;
}