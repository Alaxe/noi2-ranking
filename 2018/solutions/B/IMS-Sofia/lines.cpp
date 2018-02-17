#include<iostream>
using namespace std;

struct point{
	int x,y;
}p[1002];

long long lice(point a,point b,point c) {
	//cout<<(a.x+b.x)*(a.y-b.y)<<" "<<(b.x+c.x)*(b.y-c.y)<<" "<<(c.x+a.x)*(c.y-a.y)<<"\n";
	return (a.x+b.x)*(a.y-b.y) + (b.x+c.x)*(b.y-c.y) + (c.x+a.x)*(c.y-a.y);
}	

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	for(int i=0;i<n;i++) {
		int a,b;
		cin>>a>>b;
		p[i].x=a+102;
		p[i].y=b+102;
	}
	int otg=2;
	for(int i=0;i<n;i++) {
		for(int j=i+1;j<n;j++) {
			int curr=2;
			for(int k=j+1;k<n;k++) {
				if(lice(p[i],p[j],p[k])==0) {
					curr++;
				}
			}
			if(curr>otg) {
				otg=curr;
			}
		}
	}
	cout<<otg<<"\n";
	return 0;
}
