#include<bits/stdc++.h>
using namespace std;
long long k,m,n,ost,s1,s2;
struct str
{
    long long o,n;
};
str m1[52],m2[52];
int main()
{
    for(int i=0;i<50;i++)
    {
        m1[i].o=1;
    }
    for(int i=0;i<50;i++)
    {
        m2[i].o=1;
    }
    cin>>k>>m>>n;
    ost=(m-1)%k;
    if(ost!=0)
    {
        for(int i=1; i<n; i++)
        {
            m1[0].n=m1[1].o;
            for(int j=1; j<(m-1)/k; j++)
            {
                m1[j].n=m1[j-1].o+m1[j+1].o;
            }
            m1[(m-1)/k].n=m1[(m-1)/k-1].o;
            for(int j=0; j<=(m-1)/k; j++)
            {
                m1[j].o=m1[j].n;
            }
        }
        for(int i=0;i<=(m-1)/k;i++)
        {
            s1+=m1[i].n;
        }
    }
    s1*=ost;
    for(int i=1; i<n; i++)
        {
            m2[0].n=m2[1].o;
            for(int j=1; j<(m-1)/k-1; j++)
            {
                m2[j].n=m2[j-1].o+m2[j+1].o;
            }
            m2[(m-1)/k-1].n=m2[(m-1)/k-2].o;
            for(int j=0; j<(m-1)/k; j++)
            {
                m2[j].o=m2[j].n;
            }
        }
        for(int i=0;i<(m-1)/k;i++)
        {
            s2+=m2[i].n;
        }
    s2*=(k-ost);
    cout<<s1+s2<<endl;
}
/**
2 6 4
*/
