#include<iostream>
using namespace std;
int main()
{
long long n,brstr=0,e,d,s,h,dh,sh,m,dm,sm;
cin>>n;
for(int i=1;i<=n;i++)
{
e=i%10;
d=i/10%10;
s=i/100%10;
h=i/1000%10;
dh=i/10000%10;
sh=i/100000%10;
m=i/1000000%10;
dm=i/10000000%10;
sm=i/100000000;
if(d==0&&s==0&&h==0&&dh==0&&sh==0&&m==0&&dm==0&&sm==0) brstr++;
 else if(e==d) brstr++;
 else if(e==d&&d==s) brstr++;
 else if(e==d&&d==s&&s==h) brstr++;
 else if(s==d&&d==s&&s==h&&h==dh) brstr++;
 else if(s==d&&d==s&&s==h&&h==dh&&dh==sh) brstr++;
 else if(s==d&&d==s&&s==h&&h==dh&&dh==sh&&sh==m) brstr++;
 else if(s==d&&d==s&&s==h&&h==dh&&dh==sh&&sh==m&&m==dm) brstr++;
 else if(s==d&&d==s&&s==h&&h==dh&&dh==sh&&sh==m&&m==dm&&dm==sm) brstr++;
}

cout<<brstr<<endl;
return 0;
}
