#include<iostream>
using namespace std;
int main()
{
    int n,m,dn,a,b,br=0;
    cin>>n>>m;
    dn=n;
    while(dn<=m)
     {
       if(dn<10) {dn=dn+dn;br++;}

       if(dn>9&&dn<100){a=dn/10;b=dn%10;dn=dn+a+b;br++;}

       if(dn>=100&&dn<1000&&dn<=m) {a=dn/100;b=dn/10%10;int c=dn%10;dn=a+b+c+dn;br++;}

       if(dn>=1000&&dn<10000&&dn<=m) {a=dn/1000;b=dn/100%10;int c=dn/10%10;int d=dn%10;dn=a+b+c+d+dn; br++;}

       if(dn>=10000&&dn<100000&&dn<=m) {a=dn/10000;b=dn/1000%10;int c=dn/100%10;
       int d=dn/10%10; int z=dn%10;dn=dn+a+b+c+d+z; br++;}
    }
    cout<<br<<endl;
    return 0;
}
