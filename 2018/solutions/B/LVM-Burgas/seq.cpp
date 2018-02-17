#include<iostream>
#include<algorithm>
using namespace std;
int GetC(int n, int m)
{
int k=min(n,m),c=0;
for(int br=k;br>0;br--)
{
    int t=n-br;
    int mm=min(br,t);
    if(t>1)c=c+GetC(t,mm);
    if((t==1)||(t==0)) c++;
}
return c;
}
int main()
{
int n,m;
cin>>n>>m;
cout<<GetC(n,m)<<endl;

}

