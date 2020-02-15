#include <iostream>
#include <iomanip>
using namespace std; int b[100000];

int main()
{
    int n,a[100000],m,l[100000],r[100000];
    cin>>n;
    for(int j=1;j<=n;j++)
    cin>>a[j];
    cin>>m;
    for(int i=1;i<=m;i++)
   {
    cin>>l[i]>>r[i];
   }
   for(int j=1;j<=n;j++)
   for(int i=1;i<=m;i++)
   {
   if(a[j]>=l[i] && a[j]<=r[i]) b[i]++;
   }
   for (int i=1; i<=m; i++)
   cout<<b[i]<<endl;

    return 0;
}
