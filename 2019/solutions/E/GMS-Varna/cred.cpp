#include <iostream>
using namespace std;
int main()
{
long long int n,m,edn,desn,stn,hn;
cin>>n>>m;
if(n/10==0||n/10==1||n/10==2||n/10==3||n/10==4||n/10==5||n/10==6||n/10==7||n/10==8||n/10==9){
while(n<(m-1))
{
edn=n%10;
desn=n/10;
n=n+edn+desn;
}
}
cout<<n<<endl;
return 0;
}
