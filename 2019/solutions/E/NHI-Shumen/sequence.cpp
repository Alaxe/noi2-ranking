#include<iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int main()
{
int n;
cin>>n;
int br=0;
if(n==1)
{
    cout<<1<<endl;
    return 0;
}
for(int i=1;i<=n*(n-1)+1;i++)
{
    br++;
}
cout<<br<<endl;

    return 0;
}
