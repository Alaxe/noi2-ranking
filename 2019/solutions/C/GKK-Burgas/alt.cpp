#include<iostream>
using namespace std;
	int k, m, n;int a = 0;
void rec(int b, int j){
	
	if(b==1){
		a++;return;
	} 
	if(j+k < m){
		//a++;
		rec(b-1, j+k);
	}
	if(j-k > 0)
	{
		//a++;
		rec(b-1, j-k);
	}
	 
}

int main()
{

	cin>>k>>m>>n;
	for(int i = 1; i < m; i++){
		rec(n, i);
	}
	cout<<a<<endl;
	return 0;
}
