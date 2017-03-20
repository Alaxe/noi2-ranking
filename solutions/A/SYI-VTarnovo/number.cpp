#include<iostream>
#include<math.h>
using namespace std;

double x,m;
double ans;

int main()
{
    cin>>m>>x;
    double s,a,b;
    a=floor(sqrt(x));
    b=ceil(sqrt(x));
    x=sqrt(x);
    s=b-x;
   // cout<<a<<" "<<b<<endl;
    //cout<<x<<endl;
    if(s<=0.55)ans=b-m;
    else ans=a-m;
    if(ans<=0)cout<<0<<endl;
    else cout<<ans<<endl;
}
