#include<iostream>
using namespace std;
int main()
{
int n,m,br=0;
cin>>n>>m;
while(n<m)
{
cin>>n;
if(n==n+n/10+n-n*10 )
           {
            if(n<m) br++;
            else br--;
            }
}
cout<<br<<endl;
return 0;
}
