#include<bits/stdc++.h>
using namespace std;
int main()
{string e,s,t;
long long o=1,z,p,j,q=1,i,c=0;
cin>>e;
s="";
t="2";
while(q<e.size())
{
for(j=t.size()-1;j>=0;j--)
{p=((t[j]-'0')*2)%10;
z=p+c;
s=char(z+'0')+s;
c=((t[j]-'0')*2)/10;
}
if(c>0)s='1'+s;
c=0;
q+=s.size();
t=s;
s="";
o++;
}
cout<<o<<endl;

return 0;
}
