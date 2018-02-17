#include<iostream>
using namespace std;
long long s,t,ans;
long long tr[65][65];
int z;
string l,r;
void doTriangle()
{
    tr[0][0]=1;
    for (int i=0; i<61; i++)
    {
        tr[i][0]=tr[i][i]=1;
        for (int j=1; j<i; j++)
            tr[i][j]=tr[i-1][j-1]+tr[i-1][j];
    }
//    for (int i=0; i<10; i++)
//    {
//        for (int j=0; j<=i; j++)
//            cout<<tr[i][j]<<' ';
//        cout<<'\n';
//    }
}
void add (int n, int k)
{
    if (k<0)
        return;
    ans+=tr[n][k];
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    doTriangle();
    cin>>s>>t>>z;
    long long ss,tt;
    ss=s;
    tt=t;
    int brT,brS;
    while (ss!=0)
    {
        if (ss%2)
            l='1'+l;
        else
        {
            l='0'+l;
            brS++;
        }
        ss/=2;
    }
    while (tt!=0)
    {
        if (tt%2)
            r='1'+r;
        else
        {
            r='0'+r;
            brT++;
        }
        tt/=2;
    }
    if (brS==z)
        ans++;
    if (brT==z)
        ans++;
    int br=z,sizeL,sizeR;
    sizeL=l.size();
    sizeR=r.size();
    if (sizeR!=sizeL)
    {
        for (int i=1; i<sizeL; i++)
        {
            if (br==0)
                break;
            if (l[i]=='0')
            {
                add(sizeL-i-1,br-1);
                br--;
            }
        }
        br=z;
        for (int i=1; i<sizeR; i++)
        {
            if (br==0)
                break;
            if (r[i]=='1')
            {
                add(sizeR-i-1,br-1);
            }
            else
                br--;
        }
        for (int i=sizeL; i<sizeR-1; i++)
            add(i,z);
        cout<<ans<<'\n';
        return 0;
    }

    for (int i=s; i<=t; i++)
    {
        int x=i,br=0;
        while(x!=0)
        {
            if (x%2==0)
                br++;
            x/=2;
        }
        if (br==z)
            ans++;
    }
    cout<<ans<<'\n';
    return 0;
}
