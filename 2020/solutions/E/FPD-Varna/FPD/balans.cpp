#include<iostream>
using namespace std;
int main()
{
    long long n,t1=0,t2=0,g;
    cin>>n;
    char c[n+1];
    for(long long i=0; i<n; i++)
    {
        cin>>c[i];
    }
    for(g=n; g>=1; g--)
    {
        for(long long i=0; i<g; i++)
        {
            if(c[i]=='a'||c[i]=='b'){t1++;}
            if(c[i]=='c'||c[i]=='d'){t2++;}
        }
        if(t1==t2){break;}
        t1=0;
        t2=0;
    }
    if(g>n){cout<<0<<endl;return 0;}
    cout<<g<<endl;
}
