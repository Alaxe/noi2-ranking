#include<iostream>
using namespace std;
long long s,t,z;
long long cntPr[65];
long long zeroWays(int n,int zeros){
	if(n<zeros) return 0;
	for(int i=0;i<zeros;i++){
		int num=n-i;
		for(int j=2;j*j<=num;j++){
			while(num%j==0){
				num/=j;
				cntPr[j]++;
			}
		}
		if(num!=1) cntPr[num]++;
	}
	for(int i=zeros;i>1;i--){
		int num=i;
		for(int j=2;j*j<=num;j++){
			while(num%j==0){
				num/=j;
				cntPr[j]--;
			}
		}
		if(num!=1) cntPr[num]--;
	}
	long long ans=1;
	for(int i=2;i<=n;i++){
		while(cntPr[i]){
			cntPr[i]--;
			ans*=i;
		}
	}
	return ans;
}
long long cnt(long long curr,int pos,int zeros){
	if(curr==0) zeros=0;
	if(pos==0) return curr>=s&&curr<=t&&zeros==z;
	if(curr>t||curr+(1ll<<pos)<s+1||zeros>z||z-zeros>pos) return 0;
	if(curr>=s&&curr+(1ll<<pos)<=t+1) return zeroWays(pos,z-zeros);
	return cnt(curr,pos-1,zeros+1)+cnt(curr+(1ll<<(pos-1)),pos-1,zeros);
}
int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin>>s>>t>>z;
	int pos=0;
	while((1ll<<pos)<=t) pos++;
	pos--;
	cout<<cnt(0,pos,0)+cnt((1ll<<pos),pos,0)<<"\n";
	return 0;
}

