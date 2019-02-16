#include<iostream>

using namespace std;

const int MAXN = 100000;
int n;
int a[MAXN+100];
int dpv[MAXN+100], dpb[MAXN+100];
int maxd;

void input()
{
    int temp = 0;
    cin>>n>>a[0];
    for (int i=1; i<n; i++)
    {
        cin>>temp;
        if (temp != a[i-1]) 
        {
            a[i] = temp;
        }
        else 
        {
            i--;
            n--;
        }
    }
}

void output()
{
    cout<<maxd<<endl;
}

void solve()
{
    int mm=0;
    int curr_max;
    for (int i=0; i<n; i++)
    {
        curr_max = 0;
        for (int j=i-1; j>=0; j--)
        {
            if (a[i]>a[j] && dpv[j]>curr_max) curr_max = dpv[j];
            if (a[j] == a[i]) break;
        }
        dpv[i] = curr_max + 1;
        //cerr<<dpv[i]<<' ';
    }
    //cerr<<endl;
    for (int i=n-1; i>=0; i--)
    {
        curr_max = 0;
        for (int j=i+1; j<n; j++)
        {
            if (a[i]>a[j] && dpb[j]>curr_max) curr_max = dpb[j];
            if (a[j] == a[i]) break;
        }
        dpb[i] = curr_max + 1;
        //cerr<<dpb[i]<<' ';
    }
    //cerr<<endl;
    maxd = dpb[0]+dpv[0];
    for (int i=1; i<n; i++)
    {
        if (maxd<dpb[i]+dpv[i]) maxd = dpb[i] + dpv[i] - 1;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    solve();
    output();
    return 0;
}

/*
8
1 7 4 3 6 4 2 3
*/