#include <iostream>
using namespace std;
int main()
{
int m,k,a,br=0,sum=0,naibl1=9999,maxnom=0,nom=0,z,h,naibl2=9999,g;
cin>>m>>k;
while(br!=200)
{
cin>>a;
br++;
nom++;
if(a%2==0)sum=sum+a;
if(a>m)
if(a-m<naibl1){naibl1=a-m;z=nom;if(z>maxnom)maxnom=z;}
if(m>a)
if(m-a<naibl2){naibl2=m-a;g=nom;if(g>maxnom)maxnom=g;}
if(sum>k){h=sum;break;}
}
cout<<maxnom<<" ";
cout<<h<<endl;
return 0;
}
