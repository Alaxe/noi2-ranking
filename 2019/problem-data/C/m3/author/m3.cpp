#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdio>

using namespace std;

double s[4],h1=0.0,h2=0.0,h3=0.0, h4=0.0;
long long N,S,a,b,c,d, sekt;

int main() {
long long i,j,ch,ost,wid;
//	freopen("m3.88.in", "r", stdin);
//	freopen("m3.56.sol", "w", stdout);

	cin>>S>>N;
	cin>>a>>b>>c>>d;
	if (4*d*S<=N) {
		h1=h2=h3=h4=(double)(N/(4.0*S));
		printf("%1.3f %1.3f %1.3f %1.3f \n",h1,h2,h3,h4);
		return 0;
	}
	ch=N/(d*4);		// пълни сектори	
	ost=N%(d*4);	// вода в последния сектор
	if (ost==0){
		h1=h2=h3=h4=(double)(d);
		printf("%1.3f %1.3f %1.3f %1.3f \n",h1,h2,h3,h4);	
		return 0;
	}
	sekt=ch%4+1;
//	if (sekt==0) sekt=4;
	if (sekt==1 || sekt==3){
		if (sekt==1)swap(b,c);
		else{
			swap(b,a); swap(b,c);
		}
		if (ost<=a) h1=double(ost);
		else
		if (ost<=2*a) h1=a, h2=(double)(ost-a);
		else
		if (ost<=2*b) h1=h2=(double)(ost/2.0);
		else
		if (ost<=2*b+c) h1=h2=b, h3=(double)(ost-2*b); 
		else
		if (ost<=2*b+2*c) h1=h2=b, h3=c, h4=(double)(ost-(2*b+c)); 
		else
		if (ost<=4*b) h1=h2=b, h3=h4=(double)((ost-2*b)/2.0);
		else
		h1=h2=h3=h4=(double)(ost/4.0);
	}
	else
	if (sekt==2){
		swap(a,b);
		if (ost<=a) h1=double(ost);
		else
		if (ost<=a+b) h1=a, h2=(double)(ost-a);
		else
		if (ost<=a+2*b) h1=a, h2=b, h3=(double)(ost-a-b);
		else
		if (ost<=3*a) h1=a, h2=h3=(double)((ost-a)/2.0); 
		else
		if (ost<=3*c) h1=h2=h3=(double)(ost/3.0); 
		else
		if (ost<=4*c) h1=h2=h3=c, h4=(double)(ost-3*c);
		else
		h1=h2=h3=h4=(double)(ost/4.0);
	}
	else
	if (sekt==4){
		swap(a,b); swap(a,c);
		if (ost<=a) h1=double(ost);
		else
		if (ost<=a+b) h1=a, h2=(double)(ost-a);
		else
		if (ost<=a+2*b) h1=a, h2=b, h3=(double)(ost-a-b);
		else
		if (ost<=a+2*c) h1=a, h2=h3=(double)((ost-a)/2.0); 
		else
		if (ost<a+3*c) h1=a, h2=h3=c, h4=(double)(ost-a-2*c); 
		else
		if (ost<=4*a) h1=a, h2=h3=h4=(double)((ost-a)/3.0);
		else
		h1=h2=h3=h4=(double)(ost/4.0);
	}
	printf("%1.3f %1.3f %1.3f %1.3f \n",h1,h2,h3,h4);	
	return 0;
}

/*
*/