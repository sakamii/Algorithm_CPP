#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <queue>
using namespace std;

/*
binary search 문제.
binary search => 중복을 고려하지 못함
이 문제에서는 배열내 중복된 값이 있어도
그 위치가 다르면 다른 값이라고 생각하고 문제를 풀어야함
그래서 따로 세팅해줘야함

배열을 정렬하고 binary search를 돌림
만일 특정값을 찾았는데
그 값의 low, end index가 i라면
=> 한 인덱스에서 세개를 더한거라면 패스 (0인경우 이런게 나옴)
특정값을 찾으면 break => 어차피 중복된 넘버여도 인덱스가 다르면 다른값으로 취급

*/
int main()
{
    int n;
    cin >> n;
    vector<long long int> numbers;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        numbers.push_back(temp);
    }
    sort(numbers.begin(), numbers.end());
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        int low = 0, end = n - 1;
        while (low < end)
        {
            long long int check = numbers[low] + numbers[end];
            if (check < numbers[i])
                low++;
            if (check > numbers[i])
                end--;
            if (check == numbers[i])
            {
                if (low != i && end != i)
                {
                    count++;
                    break;
                }
                if (low == i)
                    low++;
                if (end == i)
                    end--;
            }
        }
    }
    cout << count << endl;
}