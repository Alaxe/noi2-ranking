#include <iostream>
using namespace std;int a[5000][5000];
int main()
{
int n,k;
cin>>n>>k;
for(int i=0;i<n;i++)
{
    cin>>a[0][i];
    for(int j=1;j<=a[0][i];j++)cin>>a[j][i];

}
if(n<=10)cout<<k*n*2;
    else cout<<k*n*2+(n/4)*k;



return 0;
}
