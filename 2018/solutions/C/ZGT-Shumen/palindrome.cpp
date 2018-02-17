#include <iostream>
using namespace std;
string s;
int l,a,b,c;
void read()
{
    cin>>s;
    l=s.size();
}
int obrushtane(int x)
{
    int n=0;
    n=x%10;
    x/10;
    while(x!=0)
    {
        n=n*1-+x%10;
        x/10;
    }
    return n;
}
void chetno()
{
    a=s[0];
    b=s[l-1];
    for(int i=1; i<l/2; i++)
    {
        a=a+s[i]*10;
    }
    for(int i=l-2; i>l/2; i--)
    {
        b=b+s[i]*10;
    }
    if(a>b)
    {
        a=obrushtane(b);
        //cout<<a<<b<<endl;
    }
    else
    {

        if(a<10)a=obrushtane(a)*10+1;
        else a=obrushtane(a)+1;
        b=obrushtane(a);
    }
}
void nechetno()
{
    b=s[l/2];
    a=s[0];
    c=s[l-1];
    for(int i=1; i<l/2; i++)
    {
        a=a+s[i]*10;
    }
    for(int i=l-2; i>l/2; i--)
    {
        c=c+s[i]*10;
    }
    if(a>b)
    {
        c=a;
        a=obrushtane(c);
        //cout<<a<<b<<endl;
    }
    else
    {
        b++;
        if(a<10)a=obrushtane(a)*10;
        else a=obrushtane(a);
        c=obrushtane(a);
    }
}

int main ()
{
    read();
    if(l==1)
    {
        if(s[0]==9)cout<<1<<endl;
        else cout<<s[0]+1<<endl;
    }
    if(l%2==0)
    {
        chetno();
        cout<<a<<b<<endl;
    }
    else
    {
        nechetno();
        cout<<a<<b<<c<<endl;
    }
    //chetno();
    //cout<<a<<b<<endl;
    return 0;
}
