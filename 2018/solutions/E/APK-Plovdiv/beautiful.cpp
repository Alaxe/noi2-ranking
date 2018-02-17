#include<iostream>
using namespace std;
int main()
{
int n,k,mas[18];
cin>>n>>k;
if(n==0 || n==19|| n>18) cout<<"NO";
for(int i=0;i<=n;i++)
{
    mas[0]=k;
    mas[i]=0;
    cout<<mas;
}
cout<<mas;
return 0;
}
