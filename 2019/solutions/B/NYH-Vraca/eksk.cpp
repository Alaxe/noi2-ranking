#include<iostream>
using namespace std;
int main(){
	int N, A, B;
	do{cin>>N;}
	while(N<=1 || N>200000);
	cout<<endl;
	int shortWays[N][2];
	
	for(int i = 0; i < N-1; i++){
		for(int j = 0; j < 2; j++){
			cin>>shortWays[i][j];
		}
	}
	cout<<endl;
	do{cin>>A>>B;}
	while(A=B || A<1 || B<1 || B>N || A>N);
	
	return 0;
}
