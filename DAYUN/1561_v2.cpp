#include <iostream>

using namespace std;
int play[10000];
int p = 10000;


int main() {
    //n : child m : play
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> play[i];
    }   
    

    int tmin = 1;
    int tmax = 2000000000*30;
    while(tmin < tmax) {
        int tmid = (tmin + tmax) / 2;
        for (int i = 0; i < m; i++)
        {

        }
    }



}




//최소공배수
