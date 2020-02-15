#include <iostream>
#include <map>
#include <time.h>
#include <cstdio>
#include <cmath>
#include <queue>

using namespace std;

map<long long,int> m;
map<long long,int>::iterator it;
long long n,K;
long long bpc;
long long a[100001], b[100001];
long long ba, bb, Br;



void Resh_1(int W){
long long i,j,k,br,k1,k2;
bool fl=false;
	Br=0;
	for (i=1; i<=ba-K+1; i++){
		for (j=1; j<=bb-K+1; j++){
			if (a[i]==b[j]){
				br=1;
				for (k=2; k<=K; k++){
					if (W==1 and a[i+k-1]==b[j+k-1] and a[i+k-2]<a[i+k-1] and b[j+k-2]<b[j+k-1]) {
						br++;
					}
					else
					if (W==2 and a[i+k-1]==b[j+k-1] and a[i+k-2]==a[i+k-1] and b[j+k-2]==b[j+k-1]) {
						br++;
					}
					else
					break;
				}
				if (br==K) 	
					Br++;
//				if (br>0) cout<<i<<" "<<j<<endl;
			}
		}
//	cout<<endl;	
		
	}
}

int main ()
{
long long i,j,p,q,br,t,aa,sum, nW;
bool fl=false;
//	freopen("red.04.in", "r", stdin);
// 	freopen("red.35.sol", "w", stdout);
	scanf("%lld%lld",&nW,&K);
	scanf("%lld",&ba);
	for (i=1; i<=ba;i++) scanf("%lld",&a[i]);
	scanf("%lld",&bb);
	for (i=1; i<=bb;i++) scanf("%lld",&b[i]);
	Resh_1(nW);
	cout<<Br<<endl;
  return 0;
}

