#include<iostream>
using namespace std;
bool mirror(long long n)
{int a=n,b=0;
 while(a>0)
 {b=b*10+a%10;
  a=a/10;
 }
 return (n == b);
}
int main()
{long long n,maxp=0,a,b;
cin>>n;
for(int i=1;i<=n;i=i+1)
    for(int j=1;j<=n;j=j+1)
    if(mirror(j*i)==true && i*j>=maxp)
    {maxp=i*j;
     a=i;
     b=j;
    }
if(a>b)cout<<b<<" "<<a<<endl;
else cout<<a<<" "<<b<<endl;
cout<<maxp<<endl;
return 0;
}
