#include<iostream>
using namespace std;
   int main()
{int n;
long long w,h,x[100000000],y[100000000],br;
cin>>w>>h;
cin>>n;
for(int i=0;i<=n-1;i++)
   {cin>>x[i];
    cin>>y[i];
   }
br=w*h;
cout<<br<<endl;
}
