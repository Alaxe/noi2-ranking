#include <iostream>
using namespace std;
int main ()
{
    unsigned int s1,t1,s2,t2,s,t,e1,e2,e;
    cin>>s1>>t1;
    cin>>s2>>t2;
    if(s2>s1)
    {
        if(e1>s2)
        {
            e2=e1+t2;
        }
    }
    else e2=s2+t2;
    if(s1>s2)
    {
        if(e2>s1)
        {
            e1=e2+t1;
        }
    }
    else e1=s1+t1;
    if(s1<s2)
    {
        s=s2;
        t=t2;
        e=e2;
    }
    else
    {
        s=s1;
        t=t1;
        e=e1;
    }
    while(s2<=720)
    {
        s2=s1;
        t2=t1;
        e2=e1;
        cin>>s2>>t2;
        if(s2>720)break;
        if(s2>s1)
        {
            if(e1>s2)
            {
                e2=e1+t2;
            }
        }
        else e2=s2+t2;
        if(s1>s2)
        {
            if(e2>s1)
            {
                e1=e2+t1;
            }
        }
        else e1=s1+t1;
        if(s1<s2)
        {
            s=s2;
            t=t2;
            e=e2;
        }
        else
        {
            s=s1;
            t=t1;
            e=e1;
        }
    }
    cout<<e<<endl;

    return 0;
}
