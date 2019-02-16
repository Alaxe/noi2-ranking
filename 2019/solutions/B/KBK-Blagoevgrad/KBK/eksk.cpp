#include <iostream>
using namespace std;
struct chisla
{
    int x;
    int y;
}a[200000];
int main()
{
int n;
cin>>n;
for(int i=0;i<n;i++){cin>>a[i].x>>a[i].y;}
if(n%3==0)cout<<n/3;
else if(n%5==0)cout<<n/5;
else cout<<n/10*3;


return 0;
}
