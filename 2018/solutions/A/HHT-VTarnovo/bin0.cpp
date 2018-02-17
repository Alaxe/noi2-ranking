#include<iostream>
using namespace std;
long long st, fn, s;
long long mid1, mid2;
long long count=0;
int dp[80][1000];
int check(int x, int y){
	int br1=0;
	for(int i=x;i<=y;i++){
		int br=0;
		int r = i;
		while(r/2!=0&&br<=s){
			if(r%2==0)br++;
			r/=2;
		}
		if(br==s){
			br1++;
			//cout<<i<<endl;
		}
	}
	return br1;
}
int step(int x){
	int i=0;
	while(1){
		if((1<<i)>=x){
			break;
		}
		i++;
	}
	return i;
}
main(){
	cin>>st>>fn>>s;
	mid1 = 1<<step(st);
	mid2 = 1<<(step(fn)-1);
	//PASCAL START
	if(mid1<mid2){
		int from, to;
		from = step(st);
		to = step(fn) - 1;
		dp[1][1] = 1;
		for(int i=0;i<=to;i++)dp[i][0] = 1;
		for(int i=2;i<=to;i++){
			for(int j=1;j<=to+1;j++){
				dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
			}
		}
		for(int i=from;i<to;i++){
			count += dp[i][s];
		}
		count += check(st, mid1-1);
		count += check(mid2+1, fn);
	}
	else {
		count = check(st,fn);
	}
	
	
	//PASCAL END
	

	/*for(int i=0;i<=to;i++){
		for(int j=0;j<=to+1;j++){
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}*/
	cout<<count<<endl;
}
