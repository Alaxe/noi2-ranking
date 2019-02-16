#include<iostream>
#include<cmath>
using namespace std;
int dn(int n, int d, int m)
{
    int a,b,c,br=1;
    int x=a;
    int x2=b;
    int c1a=c1a*10+a%10;
    a=a/10;
    int c2a=c2a*10+a%10;
    a=a/10;
    b=x+c1a+c2a;
    int c1b=c1b*10+b%10;
    b=b/10;
    int c2b=c2b*10+b%10;
    b=b/10;
    while (br<=c)
    {
        x2=x2+c1b+c2b;
        br++;
    }
    return br;


}
 main()
{
    int n,m;
    cin>>n>>m;
    int d=n+n/10+n%10;
    cout<<dn(n,d,m)<<endl;


return 0;
}
