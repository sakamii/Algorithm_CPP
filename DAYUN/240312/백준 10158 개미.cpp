/*
    가로 길이: w, h

*/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//45, 135, 225, 
//오른쪽 위 1
//왼쪽 위 2
//오른쪽 아래 3
//왼쪽 아래 4


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); 
    cout.tie(NULL);

    int w, h;
    int y, x;
    int end_time;
    cin >> w >> h;
    h++;
    w++;
    cin >> x >> y;
    y = h - 1 - y;
    cin >> end_time;

    vector<int> v;
    //1. 오른쪽위 
    //가로, 세로
    int time = 0;
    int t = 0;
    int direction = 45;
    int dagaksun = min(h, w);
    bool flag = false;
    while(true) {
        //direction(45);
        int y_d = h - 1 - y;
        int x_d = w - 1 - x;
        int prev_x = x;
        int prev_y = y;
        int prev_time = time;
        
        switch(direction) {
            case 1 :  
                //오른쪽 위 1
                if(x_d < y) {
                    t = x_d;
                    y -= x_d;
                    x += x_d;
                    direction = 2;
                }
                else if(x_d > y){
                    t = y;
                    y = 0;
                    x += y;
                    direction = 3;
                }
                else {
                    flag = true;
                }
                break;
            case 2 : 
                 //왼쪽 위 2
                if(y < x) {
                    x -= y;
                    y = 0;
                    t = y;
                    direction = 4;
                }
                else if(y > x){
                    x = 0;
                    y -= x;
                    t = x;
                    direction = 1;
                }       
                else {
                    flag = true;
                }
                break;
            case 3 :
                //오른쪽 아래 3
                if(y_d > x_d) {
                    x = w - 1;
                    y += x_d;
                    t = x_d;
                    //왼쪽 아래 
                    direction = 4;
                }
                else if(y_d < x_d) {
                    x += y_d;
                    y = h - 1;
                    t = y_d;
                    direction = 2;
                }
                else {
                    flag = true;
                }
                break;
            case 4: 
                ////왼쪽 아래 4 x y_d
                if(y_d < x) {
                    y = h - 1;
                    x -= y_d;
                    t = y_d;
                    //왼쪽 위
                    direction = 2;
                }
                else if(y_d > x) {
                    y += x;
                    x = 0;
                    t = x;
                    //오른쪽 아래
                    direction = 3;
                }
                else {
                    
                    flag = true;
                }
                break;
        }

        if(end_time <= (prev_time + t)) {
            //time 
            int i = (y - prev_y) / t;
            int j = (x - prev_x) / t;
            y = prev_y + (i * (end_time - prev_time));
            x = prev_x + (i * (end_time - prev_time));
            break;
        }

        if(flag = true) {

        }
    }   
}