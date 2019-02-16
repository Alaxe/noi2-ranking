#include <bits/stdc++.h>
#include <vector>

using namespace std;

vector<int> g[10101];
int u[10101];
long long d[10101];

int n, WAGE;

long long test(int x){
	queue<int> bfs;
	for (int i=1;i<=n;i++){
		u[i]=0;
		d[i]=0;
	}
	bfs.push(x);
	u[x]=1;
	d[x]=WAGE;
	while (!bfs.empty()){
		int t=bfs.front();
		bfs.pop();
		for (int nx:g[t]){
			if (u[nx]==0){
				u[nx]=1;
				d[nx]=d[t]+WAGE;
				bfs.push(nx);
			}
		}
	}
	long long v=0;
	for (int i=1;i<=n; i++){
		if (u[i]==0){
			return -1;
		}
		else{
			v += d[i];
		}
	}
	return v;
}

int main(){
	cin>>n>>WAGE;
	int m=0;
	for (int i=1;i<=n;i++){
		int k;
		cin>>k;
		m+=k;
		for(int j=0; j<k; j++){
			int a;
			cin>>a;
			g[a].push_back(i);
		}
	}
	long long v=-1;
	for (int i=1;i<=n;i++){
		long long asd=test(i);
		if (asd!=-1){
			if (v==-1) v=asd;
			else v=min(v, asd);
		}
	}
	cout<<v<<endl;
}
// End of file