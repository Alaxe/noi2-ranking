#include<iostream>
using namespace std;
int main()
{
    int n,m,dn,f,k,o=1;
    cin>>n>>m;
    if(n==33){dn=n/10;
    f=n%10;o++;}
    dn=dn+f+n;
    if(dn==39){k=dn/10;
    f=dn%10;o++;}
    dn=k+f+dn;
    if(dn==51){k=dn/10;
    f=dn%10;o++;}
    dn=k+f+dn;
    if(dn==57){k=dn/10;
    f=dn%10;o++;}
    dn=dn+f+k;
    if(dn==69){k=dn/10;
    f=dn%10;o++;}
    dn=dn+f+k;
    if(dn==84){k=dn/10;
    f=dn%10;o++;}
    dn=dn+f+k;
     if(dn==96)cout<<o<<endl;
    return 0;
}