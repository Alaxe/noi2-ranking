#include<iostream>

using namespace std;

const int MAXN=1000;
const int MAXST=1000000;
int n;
int c[MAXN+12];
bool st[MAXST+100];
bool sto[MAXST+100];
bool stp[MAXST+100];
int br=0;

void input()
{
    cin>>n;
    for (int i=0; i<n; i++)
    {
        cin>>c[i];
    }
}

void output()
{
    cout<<br<<'\n';
}

void sbor(int sc, int l, int sb, int un)
{
    if (sb>=0)
    {
        if (un==0)
        {
            if (l==0 || st[sb]==1) return;
            st[sb]=1;
            if (stp[sb]==0) br++;
            for (int i=sc+1; i<n; i++)
            {
                if (c[i]<0) sbor(i, l-1, sb+c[i], 1);
                else sbor(i, l-1, sb+c[i], 0);
            }  
        }
        else
        {
            if (l==0 || stp[sb]==1) return;
            stp[sb]=1;
            if (st[sb]==0) br++;
            for (int i=sc+1; i<n; i++)
            {
                sbor(i, l-1, sb+c[i], 1);
            }
        }
    }
    else
    {
        if (l==0 || sto[sb]==1) return;
        sto[sb]=1;
        br++;
        for (int i=sc+1; i<n; i++)
        {
            sbor(i, l-1, sb+c[i], 1);
        }  
    }
}

void solve()
{
    for (int i=0; i<n; i++)
    {
        if (c[i]<0) sbor(i, n-i, c[i], 1);
        else sbor(i, n-i, c[i], 0);
    }
}

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    input();
    solve();
    output();
    return 0;
}

/*
5
1 -2 0 7 7 
*/
