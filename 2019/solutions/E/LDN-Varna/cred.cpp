#include<iostream>
using namespace std;
int main()
{int n,m,br=1,slch=0,a,b;
cin>>n>>m;
a=n;
slch=a+n%10;
b=slch;
b/=10;
br++;
if(slch>=m)
cout<<br<<endl;
else cout<<br+(br+b)<<endl;
return 0;
}
