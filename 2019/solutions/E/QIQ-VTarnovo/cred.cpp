#include<iostream>
using namespace std;
int main()
{int m,n,sledvashto,broi,e,d;
cin>>n>>m;
e=n%10;
d=n/10%10;
sledvashto=n+e+d;
if(sledvashto<=m) broi++;
cout<<broi<<endl;
return 0;
}
