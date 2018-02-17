#include<iostream>
using namespace std;
int main ()
{
    int br=0,n,q,a,b,i,Max,f1,f2;
    cin>>n>>q;
    for(i=1; i<=n; i++)
    {
        cin>>a>>b;
        f1=a;
        f2=b;
        if(a>f1 || b>f2)
        {
            f1=a;
            f2=b;
            Max=max(f1,f2);
        }
        if(a==Max || b==Max)
        {
            if(a<b)br=br+(b-a)*q;
            else if(a>b)br=br+(a-b)*q;
        }

    }

    cout<<br<<endl;

    return 0;
}
