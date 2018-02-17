#include<iostream>
using namespace std;
int t;
int n;
int a[100000];
int color;

bool isRepeated(int x)
{
    int t=0;
    for(int i=1;i<=n;i++)
        if(a[i]==x)t++;
    if(t==2)return true;
    return false;
}

void Clean ()
{
    for(int i=0;i<=n;i++)
        a[i] == 0;
    n=0;
    color = 0;
}


void Solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    color = 2;
    for(int i=3;i<=n;i++)
    {
        if(isRepeated(a[i]))color++;
        if(i==a[i-2])color++;
    }
     if(n == a[1] && n%2!=0 && n>3)color++;
}


int main ()
{
    cin>>t;

    int i;

    while(i<t)
    {
        Solve();
        cout<<color<<endl;
        Clean();
        i++;
    }
    return 0;
}
