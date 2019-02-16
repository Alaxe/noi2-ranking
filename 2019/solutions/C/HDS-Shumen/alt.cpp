#include <bits/stdc++.h>
using namespace std;
int main() {
	float k,m;
	int n,c[64],used[64][64],s,br=0;
	cin>>k>>m>>n;
	for (int t=1 ; t<=k ; t++) {
        int d=ceil((m-t)/k);
        for (int g=1 ; g<m ; g++) {
            c[1]=g;
            for (int i=2 ; i<=n ; i++) {
                if (c[i-1]+k<m && used[i][g]!=c[i-1]+k && c[i-1]!=0) {c[i]=c[i-1]+k; used[i][g]=c[i];}
                else if (c[i-1]-k>0 && used[i][g]!=c[i-1]-k && c[i-1]!=0) {c[i]=c[i-1]-k; used[i][g]=c[i];}
            }
            if (c[n]>0) br++;
            for (int i=1 ; i<=n ; i++) c[i]=0;
        }
	}
	cout<<br<<endl;
		return 0;
}
