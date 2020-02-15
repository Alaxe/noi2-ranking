#include<iostream>
using namespace std;

void inputArr(int *arr, int n){
	for(int i = 0; i < n; i++){
		cin>>arr[i];
	}
}

bool check(int first[], int f, int second[], int s, int k, bool w){
	for(int i = 1; i < k; i++){
		if((first[f] == first[f+i]) != w) return false;
	}
	for(int i = 0; i < k; i++) {
		if(first[f + i] != second[s + i]) return false;
	}
	return true;
}

int main()
{
	int w, k, answer = 0;
	cin>>w>>k;
	bool type = w != 1;
	int f, s;
	cin>>f;
	int first[f];
	inputArr(first, f);
	cin>>s;
	int second[s];
	inputArr(second, s);
	
	for(int i = 0; i <= f - k; i++){
		for(int j = 0; j < s; j++){
			if(check(first, i, second, j, k, type)) answer++;
			else if(!type) j++;
		}
	}
	
	cout<<answer;
	
	return 0;

}
