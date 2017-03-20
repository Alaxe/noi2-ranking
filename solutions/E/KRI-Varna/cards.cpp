#include<iostream>
using namespace std;
int main()
{
int i=0,n,a,v,d,maxv,maxd,v1,d1;
cin >> n;

cin>> v1>>d1;
maxv=v1; maxd=d1;


for (a=1;a<n;a++)
{
cin>> v >> d;
if ((v>=maxv)&&(d>=maxd)) maxv=v;maxd=d;
}

for (a=1;a<n;a++)
{
if ((maxd>d)&&(maxv>v)) maxd=d;maxv=v;i++;

}


cout << i-1<< endl;


return 0;
}
