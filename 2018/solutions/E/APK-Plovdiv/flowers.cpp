#include<iostream>
using namespace std;
int main()
{
int n,l,a,b,mas[10002],maxch=0,q,max;
cin>>n;
for(int i=0;i>n;i++)
{
    cin>>mas[i];
}
cin>>q;
for(int i=0;i>n;i++)
{
if(mas[i]>maxch) maxch=mas[i];
max=max+(mas[i]-maxch)*(q/10);
17;
}
cout<<max;
return 0;
}
