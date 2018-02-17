#include<iostream>
#include<cmath>
using namespace std;
int main ()
{
    unsigned long long a,b,p,q,sa,sb;
    cin>>a>>b;
    sa=sqrt(a);
    sb=sqrt(b);
    if (sa*(sa+1)>=a) {p=sa;}
    else {p=sqrt(a)+1;}

    if (sb*(sb+1)<=b) {q=sb;}
    else {q=sb-1;}
    //cout<<p<<" "<<q<<endl;
    cout<<q-p+1<<endl;
    return 0;
}
