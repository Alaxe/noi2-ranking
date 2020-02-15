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

void PCis(){
long long i,j;
bool fl;
	pc[1]=2; bpc=1;
	for (i=3;;i+=2)	{
		fl=true;
		for (j=1; j<=(long long) (sqrt(i*1.0)); j++){
			if (i%pc[j]==0) {
				fl=false; break;
			}
		}
		if (fl) pc[++bpc]=i;
		if (bpc==10000) break;
	}
}

long long HeshC(long long t){
long long a,b=0, br=0;	
	while (t>0){
		a=t%10;
		br++;
		if (a==0) a=br;
		b=b+a*pc[a];
		t=t/10;
	}
return b;
}

long long iHesh(long long p){
long long aa, a1, a2;	
	aa=p%10000;
	if (aa==0) aa=123;
	if (p>10000) {
		a1=p%10000;
		if (a1==0)	a1=HeshC(a1);
		a2=p/10000;
		if (a2==0)	a2=HeshC(a2);
		p=a1*pc[aa]+a2*pc[aa];
		if (p>1000000000000)
			p=p%100000+1;
	}
	else
	p=p*pc[aa];
	if (p>1000000000000)
		p=p%100000+1;

	return p*pc[aa];	
}

void Resh_1(int nT){
long long i,j,p,q,br,t,aa,sum;
bool fl=false;
	Br=0;
	sum=iHesh(a[1]);		 
	br=1;
 	for (i=2; i<=ba;i++){
        if (a[i]>a[i-1] and nT==1) {
			br++; sum+=iHesh(a[i]);		
		}
	else
        if (a[i]==a[i-1] and nT==2) {
			br++; sum+=iHesh(a[i]);		
		}
		else {
			br=1; sum=iHesh(a[i]);		
		}
		if (br>=K) {
			if (br>K) sum-=iHesh(a[i-K]);		
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
		sum=iHesh(b[1]);	
		br=1;
	 	for (i=2; i<=bb;i++){
	        if (b[i]>b[i-1] and nT==1) {
				br++;
				sum+=iHesh(b[i]);
			}
			else 
	        if (b[i]==b[i-1] and nT==2) {
				br++;
				sum+=iHesh(b[i]);
			}
			else {
				br=1;
				sum=iHesh(b[i]);	
			}
			if (br>=K) {
				if (br>K){
					sum-=iHesh(b[i-K]);	
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
	srand (time(NULL));
	PCis();
// 	for (i=1; i<=10000; i++) pc1[i]=pc[i];
	for (i=1; i<=100000; i++){
		p=rand()%10000+1;
		q=rand()%10000+1;
		swap(pc[q],pc[p]);
	}
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

