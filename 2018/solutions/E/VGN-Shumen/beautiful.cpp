#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;

int main()
{
long long int n,k,br=0;
cin>>n>>k;
bool i=false;
long long int c=1;
while(br!=n)
{
   c=c*10;
   br++;
}
long long int br2=0,c2=1;
while(br2!=n-1)
{
    c2=c2*10;
    br2++;
}
long long int kk=k;
while(kk<c&&i!=true)
{
    if(kk>=c2)i=true;
    kk+=k;
}
if(i==false)
{
    cout<<"NO"<<endl;
    return 0;
}
cout<<kk-k<<endl;
return 0;
}
