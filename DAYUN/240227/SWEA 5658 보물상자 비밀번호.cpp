//SWEA 5658 보물상자 비밀번호

/*
    1. 모든 문자열을 숫자로 변환하여 저장
    1.1 중복 검사 unique
*/

#include<iostream>
#include<algorithm>
#include<functional>
#include <vector>

using namespace std;
 
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

        int n, k;
        //input을 위함
        string str;
        cin >> n >> k;
        cin >>str;
        //숫자로 변환한 값 저장
        int arr[28] ={0};
        //미리 숫자로 변환
        for(int i = 0; i < n; i++){
            if((str[i] >= '0') && (str[i] <= '9')) {
                arr[i] = str[i] - '0'; 
            }
            else {
                arr[i] = str[i] - 'A' + 10;
            }
        }
        
        //저장할 위치 -> 모두 끝나면 num_i == n
        int num_i = 0;
        vector<int> result_arr;
        result_arr.resize(n);
        int side = n / 4;
        for(int i = 0; i < side; i++) {
            int num = 0;
            for(int j = 0; j < n; j++) {
                num <<= 4;
                num += (arr[(j + i) % n]);
                if(((j + 1) % side) == 0) {
                    result_arr[num_i] = num;
                    num_i++;
                    num = 0; 
                }
            }
        }

        sort(result_arr.begin(), result_arr.end());
        //unique함수 중복한것을 제외한 마지막 위치를 리턴한다. 
        auto a = unique(result_arr.begin(), result_arr.end());
        int size = a - result_arr.begin();
        result = result_arr[size - k];
        cout << "#" << test_case << " " << result <<endl;
	}
	return 0;
}