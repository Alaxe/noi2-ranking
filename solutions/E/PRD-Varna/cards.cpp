#include<iostream>
using namespace std;
int main()
{
    long long n, x, y, a, b, i, br=1, s1=0,s2=0, f=0;
    cin>>n>>a>>b;
    s1=a*b;f++;
    for(i=2;i<=n;i++)
    {
        cin>>x>>y;
        s2=x*y;
        if(s1>=s2){if(f!=1){br+=1;}s1=s2;s2=0;f=0;}
        else {s1=s2;s2=0;}
    }
if(br==1) cout<<0<<endl;
else  cout<<br<<endl;
    return 0;
}
