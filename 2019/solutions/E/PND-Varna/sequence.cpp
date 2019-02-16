#include<iostream>
using namespace std;
int main()
{int n,ch;
cin>>n;
if(0<n<=1000000)
ch=n+((n-1)+(n-2))*n;
cout<<ch<<endl;
return 0;
}
