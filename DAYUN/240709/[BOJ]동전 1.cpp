// https://www.acmicpc.net/problem/2293

 #include<iostream>
 
 using namespace std;
 
 int money[10001];
 
 int main(){
 	int n, k;
	 int num;
	 cin >> n >> k;
	 money[0] = 1;
	for(int i = 0;i <n;i++){
		cin >> num;
		for(int j = 0; j <= (k - num); j++){
			money[j + num] += money[j];
		}
	}
	
	cout << money[k];
 }