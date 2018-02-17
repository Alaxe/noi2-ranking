#include<iostream>
using namespace std;
int main ()
{
    long long q,a,b,c,d,e,n,i;
    cin>>n;
    cin>>a,b,c,d,e;
    cin>>q;
    if(a<b) (a=b);
    if(a<c) (a=c);
    if(a<d) (a=d);
    if(a<e) (a=e);
    if(b<c) (b=c);
    if(b<d) (b=d);
    if(b<e) (b=e);
    if(c<e) (c=e);
    if(c<d) (c=d);
    if(e<d) (e=d);
    i=(a-b*q)+(a-c*q)+(a-d*q)+(a-e*q);
    cout<<i<<endl;

}
