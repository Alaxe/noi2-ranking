#include<iostream>
#include<algorithm>

using namespace std;

int n,u;
int v[1000005];
bool chislo[1005];
int brch,ch[1005];
int z,m[1005];

bool cmp(int a,int b)
{
    if(a!=b) return a<b;
}

void dududu(int n,int chisla)
{
    if(chisla==brch)
    {

    }
    for(int i=n;i<=u-chisla;i++)
    {
        dududu(i);
    }
}

int main()
{
    cin>>n>>u;
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
        if(chislo[v[i]]==false)
        {
            chislo[v[i]]=true;
            ch[brch]=v[i];
            brch++;
        }
    }
    sort(ch,ch+brch,cmp);
    for(int i=0;i<brch;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(v[j]==ch[i]) v[j]=i+1;
        }
    }
    for(int i=0;i<u-brch+1;i++)
    {
        m[i]=i+1;
    }
    for(int i=1;i<brch-1;i++)
    {
        for(int j=1;j<u-brch+1;j++)
        {
            m[j]=m[j-1]+m[j];
        }
    }
    for(int j=0;j<u-brch+1;j++)
    {
        z=m[j]+z;
    }
    cout<<z<<"\n";

    dududu(1,0);

    return 0;
}
