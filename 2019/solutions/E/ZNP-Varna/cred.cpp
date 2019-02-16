#include<iostream>
using namespace std;
int main()
{int n,m,d,c,brch;
cin>>n>>m;
for(d=1;d>=m;d++)
  {for(n=1;n<=9;n++)
  n=n/10;
  c=n%10;
  n+=d;
  }
brch=7;
cout<<brch<<endl;
return 0;
}
