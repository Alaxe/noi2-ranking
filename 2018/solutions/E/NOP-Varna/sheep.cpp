#include <iostream>
using namespace std;
int brc(int a)
{
	int br;
	if(a/8==0)
	{
	 if(a/7==0)
	 {
	 	if(a/6==0)
		{
			if(a/5==0)
			{
				if(a/4==0)
				{
					if(a/3==0)
					{
						if(a/2==0)
						{
						 br=1;
						}
						else br=2;
					}
					else br=3;
				}
				else br=4;
			}
			else br=5;
		}
		else br=6;
	 }
	 else br=7;
	}
	else br=8;
	return br;
}
int main()
{
	long long n,l,br=10,m[1000],i,a=0;
	cin>>n;
	cin>>l;
	for(i=0;i<l;i++)
	{
		cin>>m[i];
        while(a<n)
		{if(brc(i)==1 && i%m[i]!=0){br++;}
		else if(brc(i)==2 && (i%m[i]!=0 && i/10!=m[i])) {br++;}
		else if(brc(i)==3 && (i%m[i]!=0 && i/10!=m[i] && i/100!=m[i])) {br++;}
		else if(brc(i)==4 && (i%m[i]!=0 && i/10!=m[i] && i/100!=m[i]&& i/1000!=m[i])) {br++;}
		else if(brc(i)==5 && (i%m[i]!=0 && i/10!=m[i] && i/100!=m[i]&& i/1000!=m[i] && i/10000!=m[i])) {br++;}
		else if(brc(i)==6 && (i%m[i]!=0 && i/10!=m[i] && i/100!=m[i]&& i/1000!=m[i] && i/10000!=m[i]&& i/100000!=m[i])) {br++;}
		else if(brc(i)==7 && (i%m[i]!=0 && i/10!=m[i] && i/100!=m[i]&& i/1000!=m[i] && i/10000!=m[i]&& i/100000!=m[i]&& i/1000000!=m[i])){br++;}
		a++;}

     }
     cout<<n+br+10<<endl;

return 0;
}
