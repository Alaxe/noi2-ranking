#include <iostream>
using namespace std;
int main()
{
    unsigned long long n,k,a,i,l=0,b;
	cin>>n>>k;
	if(n==1) a=1;

	if(n==18)a=100000000000000000;
	else if(n==17)a=10000000000000000;
	else if(n==16)a=1000000000000000;
	else if(n==15)a=100000000000000;
	else if(n==14)a=10000000000000;
	else if(n==13)a=1000000000000;
	else if(n==12)a=100000000000;
	else if(n==11)a=10000000000;
	else if(n==10)a=1000000000;
	else if(n==9) a=100000000;
	else if(n==8) a=10000000;
	else if(n==7) a=1000000;
	else if(n==6) a=100000;
	else if(n==5) a=10000;
	else if(n==4) a=1000;
	else if(n==3) a=100;
	else if(n==2) a=10;
	if(n==18)b=1000000000000000000;
	if(n==17)b=100000000000000000;
    else if(n==16)b=10000000000000000;
    else if(n==15)b=1000000000000000;
	else if(n==14)b=100000000000000;
	else if(n==13)b=10000000000000;
	else if(n==12)b=1000000000000;
	else if(n==11)b=100000000000;
	else if(n==10)b=10000000000;
	else if(n==9) b=1000000000;
	else if(n==8) b=100000000;
	else if(n==7) b=10000000;
	else if(n==6) b=1000000;
	else if(n==5) b=100000;
	else if(n==4) b=10000;
	else if(n==3) b=1000;
	else if(n==2) b=100;
	else if(n==1) b=10;


	for(i=a;i<b;i++)
	{
		if(i%k==0){l=i;break;}
	}
	if(l==0) cout<<"No"<<endl;
	else cout<<l<<endl;

return 0;
}
