#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
int n;
struct line{
	int x, y, d;
};
operator<(line a, line b){
	if(a.y != b.y)return (a.y>b.y );
	else return(a.x > b.x);
}

priority_queue <line> qu;
vector <line> plain[10000];
int dp[1000][1000];

bool myFunct(line a,line b) {
	return a.y<b.y;
}

void setDpVal(line a,int val){
	for(int x = a.x-1; x<=a.x+a.d;x++){
		if(dp[a.y][x] == -1)dp[a.y][x] = val;
		else dp[a.y][x] = min(dp[a.y][x], val);
	}
}

void lookLeft(line a){
	line nextLine;
	nextLine.x = 0;
	nextLine.d = 0;
	nextLine.y = 0;
	sort(plain[a.x-1].begin(), plain[a.x-1].end(), myFunct);
	for(int i = 0;i<plain[a.x-1].size();i++){
		if(plain[a.x-1][i].y<a.y)nextLine = plain[a.x-1][i];
	}
	//cout<<a.x<<"-"<<a.y<<" --> "<<nextLine.x<<"-"<<nextLine.y<<endl;
	if(nextLine.y == 0){
		setDpVal(a, 0);
	} else {
		setDpVal(a, dp[nextLine.y][nextLine.x] + 1);
	}
	
	cout<<"--->"<<dp[nextLine.y][nextLine.x] + 1<<endl;
}

void lookRight(line a){
	line nextLine;
	nextLine.x = 0;
	nextLine.d = 0;
	nextLine.y = 0;
	sort(plain[a.x+1].begin(), plain[a.x+1].end(), myFunct);
	for(int i = 0;i<plain[a.x+1].size();i++){
		if(plain[a.x+1][i].y<a.y)nextLine = plain[a.x+1][i];
	}
	//cout<<a.x<<"-"<<a.y<<" --> "<<nextLine.x<<"-"<<nextLine.y<<endl;
	if(nextLine.y == 0){
		setDpVal(a, 0);
	} else {
		setDpVal(a, dp[nextLine.y][nextLine.x] + 1);
	}
	
	//cout<<"--->"<<dp[nextLine.y][nextLine.x] + 1<<endl;
}
main(){
	int maxY= 0, maxX=0;
	cin>>n;

	for(int i=0;i<n;i++){
		int x, y, d;
		cin>>x>>y>>d;
		line newLine;
		newLine.x = x;
		newLine.y = y;
		newLine.d = d;
		if(y>maxY)maxY=y;
		if(x>maxX)maxX=x;
		for(int j=x;j<x+d;j++){
			plain[j].push_back(newLine);
		}
		qu.push(newLine);
	}
//	for(int i=0;i<14;i++){
//		
//		cout<<i<<"--> ";
//		for(int j=0;j<plain[i].size();j++){
//			cout<<plain[i][j].y<<" ";
//		}
//		cout<<endl;
//	}

	for(int i = 0;i<=maxY+5;i++){
		for(int j=0;j<=maxX+5;j++){
			dp[i][j] = -1;
		}
	}
	
	while(!qu.empty()){
		line a = qu.top();
		qu.pop();
		
		lookLeft(a);
		lookRight(a);
	}
	
//	for(int i = 0;i<=maxY+1;i++){
//		for(int j=0;j<15;j++){
//			if(dp[i][j] != -1)cout<<dp[i][j]<<" ";
//			else cout<<"- ";
//		}
//		cout<<endl;
//	}
	
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		int c;
		cin>>c;
		while(dp[maxY][c] == -1 && maxY  >=0){
			maxY --;
		}
		if(maxY == -1)cout<<0;
		else cout<<dp[maxY][c]++;
	}
	
	
}
/*
13
1 4 2
9 5 2
8 1 5
2 2 2
6 2 2
2 6 3
1 3 1
4 3 2
9 3 3
5 4 5
4 5 2
7 5 1
8 6 2
*/
