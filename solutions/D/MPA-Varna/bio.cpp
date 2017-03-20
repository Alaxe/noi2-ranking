#include<iostream>
using namespace std;
int ar[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int main()
{char ch,c1,c2,c3;
int a,b,c,d,e,f,g,h,l;
cin>>a>>ch>>b>>c>>c1>>d>>e>>c2>>f>>g>>c3>>h;

l=ar[h-1]+g-1;
cout<<21252-l<<endl;

return 0;
}
