#include<iostream>
using namespace std;
int main()
{
int n,a,b;
cin>>n;
for(int i=0;i<n;i++)
{
    cin>>a>>b;
}
if(n==2) { cout<<"1"<<endl;return 0;}
cout<<n/2-1<<endl;

return 0;
}
