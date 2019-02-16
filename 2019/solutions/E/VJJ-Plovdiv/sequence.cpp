#include<iostream>
using namespace std;
int main()
{long long k,prrd,br=0;
cin>>k;
prrd=(k-1)*2-1;
for (long long i=prrd;i>=1;i=i-2)
{
br=br+i;
}
cout<<br+k<<endl;
return 0;
}
