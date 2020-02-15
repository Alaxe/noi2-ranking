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
long long pc[10000], pc1[10000];


void Resh_1(int nT){
long long i,j,p,q,br,t,aa,sum;
bool fl=false;
	Br=0;
	sum=a[1];		 
	br=1;
 	for (i=2; i<=ba;i++){
        if (a[i]>a[i-1] and nT==1) {
			br++; sum+=a[i];		
		}
	else
        if (a[i]==a[i-1] and nT==2) {
			br++; sum+=a[i];		
		}
		else {
			br=1; sum=a[i];		
		}
		if (br>=K) {
			if (br>K) sum-=a[i-K];		
			m[sum]++;
			fl=true;
		}
	}
//
	if (!fl) {
		Br=0;
	}
	else {
		sum=0; fl=false;
		sum=b[1];	
		br=1;
	 	for (i=2; i<=bb;i++){
	        if (b[i]>b[i-1] and nT==1) {
				br++;
				sum+=b[i];
			}
			else 
	        if (b[i]==b[i-1] and nT==2) {
				br++;
				sum+=b[i];
			}
			else {
				br=1;
				sum=b[i];	
			}
			if (br>=K) {
				if (br>K){
					sum-=b[i-K];	
				}
				it=m.find(sum);
			  	if (it != m.end()) Br+=m[sum];
			}
		}
	}
}

int main ()
{
long long i,j,p,q,br,t,aa,sum, nW;
bool fl=false;
	Br=0;
//	freopen("red.09.in", "r", stdin);
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

