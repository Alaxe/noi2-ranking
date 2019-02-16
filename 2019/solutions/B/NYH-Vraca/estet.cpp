#include<iostream>
using namespace std;
int main(){
	
	int N, countUp=0, countDown=0;
	do{cin>>N;}
	while(N<=0 || N>100000);
	
	int trees[N];
	int copyTrees[N];
	cout<<endl;
	for(int i = 0; i < N; i++){
		cin>>trees[i];
	}
	
	for(int i = 0; i < N; i++){
		copyTrees[i] = trees[i];
	}
	
	for(int i = 1; i < N; i++){
		if(trees[i-1] >= trees[i]){
			trees[i-1] = 0;
		}
	}
	
	for(int i = 0; i < N; i++){
		if(trees[i] != 0){
			countUp++;
		}
	}
	
	for(int i = 1; i < N; i++){
		if(copyTrees[i-1] <= copyTrees[i]){
			copyTrees[i-1] = 0;
		}
	}
	
	for(int i = 0; i < N; i++){
		if(copyTrees[i] != 0){
			countDown++;
		}
	}
	
	cout<<endl;
	
	if(countUp > countDown){
		cout<<countUp;
	} else if(countDown > countUp){
		cout<<countDown;
	} else {
		cout<<N;
	}
	return 0;
}
