#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<string>
#include<stack>
#include<queue>
using namespace std;
long long i,j,n,tc;
char c1,c2;
struct tel{
	long long maxs,st;
};
tel a[101][101];
int main(){
	cin>>n;
	cin.ignore();
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			scanf("%c",&c1);
			scanf("%c",&c2);
			cin.ignore();
	//	cin>>c1>>c2;
		//	cout<<c1<<" "<<c2<<endl;
			if(c1<='9' && c1>='0')tc=c1-'0';
			else{
				if(c1=='T')tc=10;
				if(c1=='Q')tc=12;
				if(c1=='A')tc=1;
				if(c1=='J')tc=11;
				if(c1=='K')tc=13;
			}
		//.	cout<<tc<<" ";
			a[n-i+1][j].st=tc;
		}
	//	cout<<endl;
	}
	a[1][1].maxs=a[1][1].st;
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
		//	cout<<a[i][j].st<<" ";
			a[i][j].maxs=max(a[i-1][j].maxs,a[i][j-1].maxs)+a[i][j].st;
		}
	//	cout<<endl;
	}
	cout<<a[n][n].maxs<<endl;
	return 0;
}

/*
4
8S AD 3C AC
8C 4H QD QS
5D 9H KC 7h
TC QC AS 2D
*/
