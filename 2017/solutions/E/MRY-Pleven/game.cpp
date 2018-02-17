#include<iostream>
using namespace std;
int main()
{
    long long s,t,a,br,b,o,ans;
    cin>>s>>t;
    a=0;
    b=0;
    br=0;
    cin>>a;
    if(a%2==0)
    {
        a=a;
    }
    else
    {
        a=0;
    }
    o=1;
    for(int i=1;i<=i+1;i++)
    {
        o=i;
        cin>>b;
        if(b%2==0)
        {
            b=b;
        }
        else
        {
            b=0;
        }
        a=a+b;
        if(b<s)
        {
            if(s-b<o)
            {
                o=br;
            }
        }
        if(b>s)
        {
            if(b-s<o)
            {
                o=br;
            }
        }
        if(b==s)
        {
          o=br;
        }
        if(br==200 or a>t)
        {
            break;
        }
    }
    cout<<o<<" "<<a<<endl;
}
