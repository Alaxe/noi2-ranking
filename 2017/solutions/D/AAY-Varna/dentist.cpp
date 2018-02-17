#include<bits/stdc++.h>
using namespace std;
struct zub
{
    int c;
    int n;
};
int cmp(zub m,zub b)
{
    return m.c<b.c;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    zub a[720]={0};
    int i=0;
    while(!cin.eof())
    {
        cin>>a[i].c>>a[i].n;
        i++;
    }
    i--;
    sort(a,a+i,cmp);
    int j;
    int sum=0;
    sum+=a[0].c+a[0].n;
     int delay=0;
    for(j=1;j<i-1;j++)
    {
        if(sum<=a[j].c)
        {
            sum=a[j].c;
            sum+=a[j].n;
        }
        else
        {
            delay=sum-a[j].c;
            sum+=a[j].n;
        }
    }
    int res=a[i-1].n;
    if(sum>a[i-1].c)
    {
        res+=sum-a[i-1].c;
    }
    cout<<res<<endl;
}

