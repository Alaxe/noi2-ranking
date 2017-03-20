#include<iostream>
using namespace std;
int main()
{
    int n, m, k, o,f,g,h,r,s,sumch=0;
    cin>>m>>k;
    cin>>n;
    cin>>o;
    cin>>f;
    cin>>g;
    cin>>h;
    cin>>r;
    cin>>s;
    if(n%2==0)sumch=sumch+n;
    if(o%2==0)sumch=sumch+o;
    if(f%2==0)sumch=sumch+f;
    if(g%2==0)sumch=sumch+g;
    if(h%2==0)sumch=sumch+h;
    if(r%2==0)sumch=sumch+r;
    if(s%2==0)sumch=sumch+s;
    n=m-n;
    o=m-o;
    f=m-f;
    g=m-g;
    h=m-h;
    r=m-r;
    s=m-s;
    if(n>o)swap(k, o);
    if(n>f)swap(k, f);
    if(n>g)swap(k, g);
    if(n>h)swap(k, h);
    if(n>r)swap(k, r);
    if(n>s)swap(k, s);
    cout<<k<<" "<<sumch<<endl;
    return 0;
}
