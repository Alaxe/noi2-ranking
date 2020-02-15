#include<iostream>
using namespace std;
int main()
{
int n,krasivi,e,d;
cin>>n;
e=e%10;
d=d/10%10;
krasivi=n/d+e/e;
cout<<krasivi<<endl;
return 0;
}
