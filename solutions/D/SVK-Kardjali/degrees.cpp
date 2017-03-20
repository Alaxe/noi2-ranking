#include <iostream>
#include <cstring>
using namespace std;
int stepPROV(int y)
{   int br=0;
    while(y!=1)
    {
        br++;
        y=y/2;
    }
    br--;
return br;}
int main ()
{string a,b;
int n;
unsigned long long x[200000],j=1;
cin>>a;
n=a.size();
if(n!=1){
if(n%2==0)( n=n/2);
x[0]=2;
for(int i=1;i<=n;i++)
{
x[i]=2*x[i-1];
}
j=stepPROV(x[n]);
}
cout<<j<<endl;
return 0;
}
/*
248163264128256512
*/
