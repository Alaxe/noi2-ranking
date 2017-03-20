#include<iostream>
using namespace std;
int main ()
{int m,k,ch,br=0,sbor=0,raz=0,minraz=100000000;
cin>>m>>k;
cin>>ch;br++;
while(sbor<=k)
if(ch%2==0)sbor+=ch;
{if(m>=ch)raz=m-ch;
else if(ch>m)raz=ch-m;
if(raz<minraz)minraz=raz;
}
cout<<br<<" "<<sbor;
return 0;
}
