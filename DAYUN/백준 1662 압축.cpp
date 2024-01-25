#include <iostream>
#include<string>
#include<queue>


using namespace std;

string str;
string calculate()
{
    string result;
    result = '0';

    return result;
}

string run(int i, int j)
{
    int pos1 = -1, pos2 = -1;
    pos1 = str.substr(i, j - i + 1).find('(');
    pos2 = str.substr(i, j - i + 1).find(')');
    if(pos1 == -1 || pos2 == -1)
    {
        //1(9) i == j 1 0 (1  92 )3
        int c = 0;
        for(int k = i; k <= j; k++)
        {
            c = c * 10;
            c += str[k] - '0';
        }

        return calculate();
    }
    else
    {
        str.replace(i + pos1 - 2, i + pos2 - pos2 + 3, run(i + pos1 + 1, i + pos2 - 1));
    }
}

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    //압축되지 않은 문자열 s k(q)와 같이 압축
    //k는 한자리  정수q는 0자리 이상의 문자열
    cin >> str;
    
    queue<char> q;




	return 0;
}