#include<bits/stdc++.h>
using namespace std;
int c(long long x)
{
    int br=0;
    while(x/=10)br++;
    return br+1;
}
int main()
{
    long long n;
    cin>>n;
    int brc=c(n);
    if(brc==1)
    {
        cout<<26<<endl;
    }
    if(brc==2)
    {
        cout<<110<<endl;
    }
    if(brc==3)
    {
        cout<<1016<<endl;
    }
    if(brc==4)
    {
        cout<<11138<<endl;
    }
    if(brc==5)
    {
        cout<<143522<<endl;
    }
    if(brc==6)
    {
        cout<<9999992<<endl;
    }
    if(brc==7)
    {
        cout<<99999992<<endl;
    }
    if(brc==8)
    {
        cout<<999999992<<endl;
    }
    if(brc==9)
    {
        cout<<9999999998<<endl;
    }
    if(brc==10)
    {
        cout<<99999999998<<endl;
    }
    if(brc==11)
    {
        cout<<999999999998<<endl;
    }
    if(brc==12)
    {
        cout<<9999999999998<<endl;
    }
    if(brc==13)
    {
        cout<<99999999999998<<endl;
    }
    if(brc==14)
    {
        cout<<999999999999998<<endl;
    }
    if(brc==15)
    {
        cout<<9999999999999998<<endl;
    }
    if(brc==16)
    {
        cout<<99999999999999998<<endl;
    }
    if(brc==17)
    {
        cout<<100000000000000004<<endl;
    }
    return 0;
}
