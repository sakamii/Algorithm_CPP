#include<iostream>
#include <vector>
#include <string>
using namespace std;

string message, key;
char arr[5][5];
bool visited[26];
int idx;
int restChar;
vector<string>parsed;

void toPW(){
    for(int i=0;i<parsed.size();i++){

        //1번경우
        bool flag=false;
        for(int j=0;j<5;j++){
            int one=-1;
            int two=-1;
            for(int k=0;k<5;k++){
                if(arr[j][k]==parsed[i][0]) one=k;
                if(arr[j][k]==parsed[i][1]) two=k;
            }
            if(one!=-1&&two!=-1){
                parsed[i][0]=arr[j][(one+1)%5];
                parsed[i][1]=arr[j][(two+1)%5];
                flag=true;
                break;
            }
        }
        if(flag) continue;

        //2번경우
        for(int j=0;j<5;j++){
            int one=-1;
            int two=-1;
            for(int k=0;k<5;k++){
                if(arr[k][j]==parsed[i][0]) one=k;
                if(arr[k][j]==parsed[i][1]) two=k;
            }
            if(one!=-1&&two!=-1){
                parsed[i][0]=arr[(one+1)%5][j];
                parsed[i][1]=arr[(two+1)%5][j];
                flag=true;
                break;
            }
        }
        if(flag) continue;
        
        //3번경우
        int onex, oney,twox, twoy;
        for(int j=0;j<5;j++){
            for(int k=0;k<5;k++){
                if(arr[j][k]==parsed[i][0]){
                    onex=j, oney=k;
                }
                if(arr[j][k]==parsed[i][1]){
                    twox=j, twoy=k;
                }
            }
        }
        parsed[i][0]=arr[onex][twoy];
        parsed[i][1]=arr[twox][oney];
    }
}

void parsing(){
    int nowidx=0;
    while(true){
        if(nowidx>=message.length()-1){
            if(nowidx==message.length()-1){
                string temp="";
                temp+=message[nowidx];
                temp+='X';
                parsed.push_back(temp);
            }
            break;
        }
        if(message[nowidx]==message[nowidx+1]){
            string temp="";
            temp+=message[nowidx];
            if(message[nowidx]=='X'){
                temp+='Q';
            }
            else{
                temp+='X';
            }
            parsed.push_back(temp);
            nowidx++;
        }
        else{
            string temp="";
            temp+=message[nowidx];
            temp+=message[nowidx+1];
            parsed.push_back(temp);
            nowidx+=2;
        }
        
    }
}

void toArr(){
    string temp1="";
    for(int i=0;i<key.length();i++){
        if(!visited[key[i]-'A']){
            visited[key[i]-'A']=true;
            temp1+=key[i];
        }
    }
    for(int i=0;i<26;i++){
        if(i==9) continue;
        if(!visited[i]){
            temp1+='A'+i;
        }
    }
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            arr[i][j]=temp1[i*5+j];
        }
    }
}

int main(int argc, char** argv)
{
    cin>>message>>key;
    toArr();
    parsing();
    toPW();
    for(int i=0;i<parsed.size();i++){
        cout<<parsed[i];
    }
}
