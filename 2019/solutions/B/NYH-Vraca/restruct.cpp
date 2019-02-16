#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	int N, K, I;
	do{cin>>N;}
	while(N<2 || N>5000);
	int preferences[N][N];
	
	do{cin>>K;}
	while(K<1 || K>550);
	cout<<endl;
	
	for(int i = 0; i < N; i++){
		do{cin>>I;}
		while(I>=N);
		
		for(int j = 0; j < I; j++){
			cin>>preferences[i][j];
		}	
	}
	
	return 0;
}
