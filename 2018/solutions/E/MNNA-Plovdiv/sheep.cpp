#include<bits/stdc++.h>
using namespace std;
int main ()
{
    long long n,l,br=0,a1,a2,a3,i=0;
    cin>>n>>l;
    if(l==3)
    {
        cin>>a1>>a2>>a3;
    }
    if(l==2)
    {
        cin>>a1>>a2;
        a3=11;
    }
    if(l==1)
    {
        cin>>a1;
        a2=11;
        a3=11;
    }

    int ans=0;
    for(i=1;;i++)
    {
        int c=i,p=0;
        while(c!=0)
        {
            int d=c%10;
            c/=10;

            if(d==a1) p=1;
            if(d==a2) p=1;
            if(d==a3) p=1;
        }

        ans=i;
        if(p==0) br++;
        if(br==n) break;
    }

    cout<<ans<<endl;
    return 0;
}
