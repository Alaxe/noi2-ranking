#include<iostream>
#include<algorithm>
using namespace std;
int main(){
int n, k[100000],m,otg[100000],a,b;
cin>>n;
for(int i=0;i<n;i++)
{
      cin>>k[i];
}
sort(k,k+n);
cin>>m;
for(int i=0;i<m;i++)
{
     cin>>a>>b;
     for(int j=0;j<n;j++)
     {
          if(a<=k[j] and k[j]<=b)
          {
              otg[i]++;
          }
     }
}
cout<<otg[0];
for(int i=1;i<m;i++)
{
     cout<<endl<<otg[i];
}

return 0;
}
